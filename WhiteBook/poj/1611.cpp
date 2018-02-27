#include<iostream>
#include<vector>
using namespace std;

vector<int> par;
vector<int> rank;
int N, M;

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
    if(rank.at(a)<rank.at(b)){
        par.at(a) = b;
    }
    else{
        par.at(b) = a;
        if(rank.at(a)==rank.at(b)){
            rank.at(a)++;
        }
    }
}

bool same(int a,int b){
    return find(a) == find(b);
}


int main(){
    while(cin>>N>>M){
        if(N==0&&M==0)
            return 0;
        int num = 0;
        int pp = 0, ppother = 0;
        init(N);
        for (int i = 0; i < M;i++){
            cin >> num;
            cin >> pp;
            for (int j = 1; j < num;j++){
                cin >> ppother;
                unite(pp, ppother);
            }
        }
        int res = 0;
        for (int i = 0; i < N;i++){
            if(same(0,i))
                res++;
        }
        cout << res << endl;
    }
    return 0;
}