#include<iostream>
using namespace std;

#define maxv 1005
#define INF 0x3f3f3f
int map[maxv][maxv];
int d1[maxv], d2[maxv];
bool vis[maxv];
int N, M, X;

int doit(int s){
    int Min;
    for (int i = 1; i < N + 1;i++){
        vis[i] = false;
        d1[i] = INF;
    }
    d1[s] = 0;
    while(true){
        int v = -1;
        for (int i = 1; i < N + 1;i++){
            if(!vis[i] && (v==-1||d1[i]<d1[v])){
                v = i;
            }
        }
        if(v==-1)
            break;
        vis[v] = true;
        for (int i = 0; i < N + 1;i++){
            d1[i] = min(d1[i], d1[v] + map[v][i]);
        }
    }
    for (int i = 1; i < N + 1;i++){
        vis[i] = false;
        d2[i] = INF;
    }
    d2[s] = 0;
    while(true){
        int v = -1;
        for (int i = 1; i < N + 1;i++){
            if(!vis[i] && (v==-1||d2[i]<d2[v])){
                v = i;
            }
        }
        if(v==-1)
            break;
        vis[v] = true;
        for (int i = 0; i < N + 1;i++){
            d2[i] = min(d2[i], d2[v] + map[i][v]);
        }
    }
    int max = 0;
    for (int i = 1; i < N+1;i++){
        if(d1[i]+d2[i]>max){
            max = d1[i] + d2[i];
        }
    }
    return max;
}

int main(){
    while(cin>>N>>M>>X){
        for (int i = 1; i < N + 1;i++){
            for (int j = 1; j < N + 1;j++){
                if(i==j){
                    map[i][j] = 0;
                }
                else{
                    map[i][j] = INF;
                }
            }
        }
        for (int i = 0; i < M;i++){
            int a, b, c;
            cin >> a >> b >> c;
            map[a][b] = c;
        }
        int result = doit(X);
        cout << result << endl;
    }
}