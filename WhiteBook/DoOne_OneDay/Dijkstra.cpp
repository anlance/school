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
                que.push(P(d[e.cost], d[e.to]));//wrong
            }
        }
    }
}

//------------2--------//
void dijkstraBt2(int s){
    priority_queue<P, vector<P>, cmp> que;
    fill(d, d + v, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int u =p.second;
        if(d[u]<p.first)
            continue;
        for (int i = 0; i < gf[u].size();i++){
            edge et = gf[u][i];
            if(d[et.to]>d[u]+et.cost){
                d[et.to] = d[u] + et.cost;
                que.push(P(d[et.to], et.to));//wocao，以前乱写的，上午也没看请
            }
        }
    }
}

//--------3-----------//
void dijkstraBt3(int s){
    priority_queue<P, vector<P>, cmp> que;
    fill(d, d + v, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();//取出距离最短的点
        que.pop();
        int u = p.second;
        if(d[u]<p.first)
            continue;   //如果该点到s的距离大于最短距离，继续下次循环
        //否则，在和u相邻的顶点中，取出每条边
        //如果该边的to点的最短距离>该边的from点（u点）的最短距离加上边的权值
        //那么前面的就等于后面的和
        for (int i = 0; i < gf[u].size();i++){
            edge et = gf[u][i];
            if(d[et.to]>d[u]+et.cost){
                d[et.to] = d[u] + et.cost;
                que.push(P(d[et.to], et.to));
            }
        }
    }
}

//--------4--------//
void dijkstraBt4(int s){
    priority_queue<P, vector<P>, cmp> que;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int u = p.second;
        if(d[u]<p.first)
            continue;
        for (int i = 0; i < gf[u].size();i++){
            edge et = gf[u][i];
            if(d[et.to]>d[u]+et.cost){
                d[et.to] = d[u] + et.cost;
                que.push(P(d[et.to], et.to));
            }
        }
    }
}

//--------------5------------//
void dijkstra5(int s){
    priority_queue<P, vector<P>, cmp> que;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int u = p.second;
        if(d[u]<p.first)
            continue;
        for (int i = 0; i < gf[u].size();i++){
            edge et = gf[u][i];
            if(d[et.to]>d[u]+et.cost){
                d[et.to] = d[u] + et.cost;
                que.push(P(d[et.to], et.to));
            }
        }
    }
}