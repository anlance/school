#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int INF = 0x3f3f3f;
int T, N;
int dist[1010];
bool vis[1010];
int map[1010][1010];

void dijkstra(int n)  
{  
    int k,min;  
    for(int i=1; i<=n; i++)  
    {  
        dist[i]=map[1][i];  
        vis[i]=0;  
    }  
    for(int i=1; i<=n; i++)
    {  
        k=0;  
        min=INF;  
        for(int j=1; j<=n; j++)  
            if(vis[j]==0&&dist[j]<min)  
            {  
                min=dist[j];  
                k=j;  
            }  
        vis[k]=1;  
        for(int j=1; j<=n; j++)  
            if(vis[j]==0&&dist[k]+map[k][j]<dist[j])  
                dist[j]=dist[k]+map[k][j];
    }  
    return;  
}  
int main()  
{  
    int t,n,a,b,w;  
    while(cin>>t>>n)  
    {  
        memset(map,0,sizeof(map));  
        memset(vis,0,sizeof(vis));  
        memset(dist,0,sizeof(dist));  
        for(int i=1; i<=n; i++)  
            for(int j=1; j<=n; j++)  
                map[i][j]=INF;//初始化为无穷大    
        for(int i=1; i<=t; i++)  
        {
            cin >> a >> b >> w;
            if(w<map[a][b])  
            {  
                map[a][b]=w;  
                map[b][a]=map[a][b];
            }
        }  
        dijkstra(n);
        cout << dist[n] << endl;
    }  
    return 0;  
}  