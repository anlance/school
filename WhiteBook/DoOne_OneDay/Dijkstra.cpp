//------------1-----------//
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int MAX_E = 100;
const int MAX_V = 100;
const int INF = 0x3f3f3f;

int d[MAX_V];   //表示s到每个顶点的最短距离
int v, e;
int g[MAX_V][MAX_V]; // 初值全为INF
bool used[MAX_V];   //标记已经更新过的顶点

void dijkstra(int s){
    fill(d, d + v, INF);
    fill(used, used + v, false);
    d[s] = 0;
    while(true){
        int t = -1;
        for (int i = 0; i < v;i++){ //找出最短距离最小的那个点
            if(!used[i]&&(t==-1||d[t]>d[i]))
                t = i;
        }
        if(t==-1)   //如果未查找到就说明所有的点已经确定
            break;
        used[t] = true;
        for (int i = 0; i < v;i++){
            d[i] = min(d[i], d[t] + g[t][i]);
        }
    }
}


//----------优化1-------------//
struct edge{
    int to;
    int cost;
};
typedef pair<int, int> P;//first是最短距离，second是顶点编号
struct cmp{
    bool operator()(P a ,P b){
        if(a.first<b.first)
            return a < b;
        return a > b;
    }
};
vector<edge> gf[MAX_V];

void dijkstraBt(int s){
    priority_queue<P, vector<P>, cmp> que;
    fill(d, d + v, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v]<p.first)
            continue;
        for (int i = 0; i < gf[v].size();i++){
            edge e = gf[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.cost], d[e.to]));
            }
        }
    }
}