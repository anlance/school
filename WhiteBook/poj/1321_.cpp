#include<iostream>
#include<cstring>
using namespace std;

#define maxv 10
char map[maxv][maxv];
int n, m;
bool used[maxv];
int res = 0;

void dfs(int index, int num){
    if(n-index<num){
        return;
    }
    if(index>n+1&&num!=0){
        return;
    }
    if(num==0){
        res++;
        return;
    }
    for (int j = 0; j < n;j++){
        if(map[index][j]=='#' && used[j]==false){
            used[j] = true;
            dfs(index + 1, num-1);
            used[j] = false;
        }
    }
    dfs(index + 1, num);
}

int main(){
    while(cin>>n>>m){
        if(n==-1){
            break;
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cin >> map[i][j];
            }
        }
        memset(used, false, sizeof(used));
        res = 0;
        dfs(0,m);
        cout << res << endl;
    }
    return 0;
}
