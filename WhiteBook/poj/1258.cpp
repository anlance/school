#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define maxv 105
#define inf 0x3f3f3f
int cost[maxv][maxv];
int d[maxv];
bool used[maxv];
int V;

int prim(){
    for (int i = 0; i < V;i++){
        d[i] = inf;
        used[i] = false;
    }
    int res = 0;
    d[0] = 0;
    while(true){
        int v = -1;
        for (int u = 0; u < V;u++){
            if(!used[u]&&(v==-1 || d[u]<d[v]))
                v = u;
        }
        if(v==-1)
            break;
        res += d[v];
        used[v] = true;
        for (int i = 0; i < V;i++){
            if(i==v)
                continue;
            d[i] = min(d[i], cost[v][i]);
        }
    }
    return res;
}

int main(){
    while(cin>>V){
        for (int i = 0; i < V;i++){
            for (int j = 0; j < V;j++){
                cin >> cost[i][j];
            }
        }
        int ans = prim();
        cout << ans << endl;
    }
}