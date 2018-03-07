#include<iostream>
#include<vector>
using namespace std;

vector<int> par;
vector<int> rank;
#define maxv 520
bool judge[maxv];
int pos[maxv];
int N, M;
struct Node{
    int a, b;
    char op;
};
Node step[2200];

void init(int n){
    par.clear();
    rank.clear();
    par.reserve(n);
    rank.reserve(n);
    for (int i = 0; i < n;i++){
        par.push_back(i);
        rank.push_back(0);
    }
}

int find(int a){
    if(par.at(a)==a)
        return a;
    return par.at(a) = find(par.at(a));
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)
        return;
    if(rank.at(a)<rank.at(b))
        par.at(a) = b;
    else{
        par.at(b) = a;
        if(rank.at(a)==rank.at(b))
            rank.at(a)++;
    }
}

bool same(int a, int b){
    return find(a)==find(b);
}

int main(){
    while(cin>>N>>M){
        init(N * 3); //0~N-1 小于， N~2N-1 等于, 2N~3N-1 大于
        for (int i = 0; i < N;i++){
            judge[i] = true;
            pos[i] = -1;
        }
        for (int i = 0; i < M;i++){
            cin >> step[i].a >> step[i].op >> step[i].b;
            switch(step[i].op){
                case '=':
                    break;
                case '<':
                    if(step[i].a>step[i].b){
                        swap(step[i].a, step[i].b);
                        step[i].op = '>';
                    }
                    break;
                case '>':
                    if(step[i].a>step[i].b){
                        swap(step[i].a, step[i].b);
                        step[i].op = '<';
                    }
                    break;
            }
        }
        int count = 0;
        bool flag = false;
        for (int j = 0; j < N;j++){
            init(N * 3);
            flag = false;
            for (int i = 0; i < M;i++){
                if(step[i].a==j||step[i].b==j)
                    continue;
                switch(step[i].op){
                    case '<':
                        if(same(step[i].a+N,step[i].b+N)||same(step[i].a+2*N,step[i].b+2*N)){
                            judge[j] = false;
                            pos[j] = i + 1;
                            flag = true;
                            break;
                        }
                        unite(step[i].a, step[i].b);
                        break;
                    case '=':
                        if(same(step[i].a,step[i].b)||same(step[i].a+2*N,step[i].b+2*N)){
                            judge[j] = false;
                            pos[j] = i + 1;
                            flag = true;
                            break;
                        }
                        unite(step[i].a+N,step[i].b+N);
                        break;
                    case '>':
                        if(same(step[i].a+N,step[i].b+N)||same(step[i].a,step[i].b)){
                            judge[j] = false;
                            pos[j] = i + 1;
                            flag = true;
                            break;
                        }
                        unite(step[i].a+2*N,step[i].b+2*N);
                        break;
                }
                if(flag==true)
                    break;
            }
        }
        int res = 0;
        int maxRes = 0;
        for(int k=0;k<N;k++){
            if(judge[k]==true){
                count++;
                res = k;
            }
            else{
                if(maxRes<pos[k])
                    maxRes = pos[k];
            }
        }
        if(count==0)
            cout << "Impossible" << endl;
        else if(count>1){
            cout << "Can not determine" << endl;
        }
        else{
            cout << "Player " << res << " can be determined to be the judge after " << maxRes <<" lines" << endl;
        }
    }
    return 0;
}