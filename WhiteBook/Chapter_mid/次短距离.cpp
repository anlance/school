#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

//POJ3255
/*
求一号路口到N号路口的次短距离
*/

/*
到某个顶点的v的次短距离
要么是到其他某个顶点u的最短距离再加上u->v的次短距离
要么是到u的次短距离再加上u->v的最短距离
所以应当记录到所有顶点的最短和次短距离
*/

const int max_v = 20;
const int INF = 65236;
int N, R;	//R条道路，N个路口

struct edge {
	int to;
	int cost;
};
typedef pair<int,int> P;
struct cmp {
	bool operator()(P a, P b) {
		if (a.first < b.first)
			return a < b;
		return a > b;
	}
};
vector<edge> G[max_v];	//图的邻接表
int dist[max_v];	//最短距离
int dist2[max_v];	//次短距离

void solve() {
	priority_queue<P, vector<P>, cmp> que;
	fill(dist, dist + N, INF);
	fill(dist2, dist2 + N, INF);
	dist[0] = 0;
	que.push(P(0, 0));

	while (!que.empty()) {
		//定位到当前顶点
		P p = que.top();	
		que.pop();
		int d = p.first;
		int v = p.second;

		if (dist2[v] < d)
			continue;	//如果当前顶点的次短距离已找到，直接下一个顶点

		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			int d2 = d + e.cost;
			if (dist[e.to] > d2) {
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			}	//找到当前顶点到下家的距离
			//并将从出发顶点到下家的最短距离存到优先队列里面
			if (dist2[e.to] > d2&&dist[e.to] < d2) {
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}	//如果存在到下一个顶点存在次短距离
			//找到每个下家的次短距离并存到优先队列里面
		}
	}
	cout << dist2[N - 1] << endl;
}
