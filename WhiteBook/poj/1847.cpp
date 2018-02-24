#include<iostream>
#include<cstring>
using namespace std;
int n, s, e;
#define maxv 110
#define inf 0x3f3f3f
int map[maxv][maxv];
int d[maxv];
bool used[maxv];

int dijkstra(int start, int end){
    memset(d, inf, sizeof(d));
    memset(used, false, sizeof(used));

    d[start] = 0;
    while(true){
        int v = -1;
        for (int i = 1; i < n + 1;i++){
            if(!used[i]&&(v==-1||d[i]<d[v]))
                v = i;
        }
        if(v==-1)
            break;
        used[v] = true;
        for (int i = 1; i < n + 1;i++){
            if(!used[i]&&d[i]>d[v]+map[v][i])
                d[i] = d[v] + map[v][i];
        }
    }

    if(d[end]==inf){
        return -1;
    }
    else{
        return d[end];
    }
}

int main(){
    int num, t;
    while(cin>>n>>s>>e){
        for (int i = 1; i < n + 1;i++){
            for (int j = 1; j < n + 1;j++){
                map[i][j] = inf;
            }
        }
        for (int i = 1; i < n + 1;i++){
            cin >> num;
            for (int j = 0; j < num;j++){
                cin >> t;
                if(j==0)
                    map[i][t] = 0;
                else
                    map[i][t] = 1;
            }
        }
        int res = dijkstra(s, e);
        cout << res << endl;
    }
    return 0;
}