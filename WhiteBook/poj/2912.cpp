#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define maxv 520
int map[maxv][maxv];
bool judge[maxv];
int pos[maxv];
int N, M;
struct Node{
    int a, b;
    char op;
};
Node step[2200];



int main(){
    while(cin>>N>>M){
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
            memset(map, 0, sizeof(map));
            flag = false;
            for (int i = 0; i < M;i++){
                if(step[i].a==j||step[i].b==j)
                    continue;
                switch(step[i].op){
                    case '<':
                        if(map[step[i].a][step[i].b]==2 || map[step[i].a][step[i].b]==3){
                            judge[j] = false;
                            pos[j] = i + 1;
                            flag = true;
                            break;
                        }
                        map[step[i].a][step[i].b] = 1;
                        break;
                    case '=':
                        if(map[step[i].a][step[i].b] == 1 || map[step[i].a][step[i].b] == 3){
                            judge[j] = false;
                            pos[j] = i + 1;
                            flag = true;
                            break;
                        }
                        map[step[i].a][step[i].b] = 2;
                        break;
                    case '>':
                        if(map[step[i].a][step[i].b]==1 || map[step[i].a][step[i].b]==2){
                            judge[j] = false;
                            pos[j] = i + 1;
                            flag = true;
                            break;
                        }
                        map[step[i].a][step[i].b] = 3;
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