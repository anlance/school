#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char map[10][10];
char vis[10];
int ccount;
int N, K;

void dfs(int index,int num){
    if(index>=N&&num!=0)
        return;
    if(N-index<num)
        return;
    if(num==0){
        ccount++;
        return;
    }
    for (int j = 0; j < N;j++){
        if(map[index][j] == '.')
            continue;
        if(vis[j]==true)
            continue;
        vis[j] = true;
        dfs(index + 1, num - 1);// 该行放
        vis[j] = false;
    }
    dfs(index + 1, num);//该行不放
}

int main(){
    while(cin>>N>>K){
        if(N==-1&&K==-1)
            break;
        for (int i = 0; i < N;i++){
            for (int j = 0; j < N;j++){
                cin >> map[i][j];
            }
            vis[i] = false;
        }
        //memset(vis,0,sizeof(vis)); 
        ccount = 0;
        dfs(0, K);
        cout << ccount << endl;
    }
    return 0;
}