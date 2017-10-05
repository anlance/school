#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

//单源最短路问题2
//Dijkstra算法(堆实现)
//不能存在负边

const int max_v=20;
const int INF = 65236;
struct edge {
	int to;
	int cost;
};
typedef pair<int, int>p;	//first是最短距离,second是顶点的编号
vector<edge> G[max_v];
int d[max_v];
int V;	//顶点数

struct cmp {
	bool operator()(p a,p b) {
		if (a.first < b.first)
			return a < b;
		return a > b;
	}
};

void dijkstra(int s) {
	//通过指定greater<p>参数，堆按照first从小到大的顺序取出值
	priority_queue<p, vector<p>,cmp> que;
	fill(d, d + V,INF);
	d[s] = 0;
	que.push(p(0, s));
	//初始化

	while (!que.empty()) {
		p P = que.top();
		que.pop();
		int v = P.second;
		if (d[v] < P.first)
			continue;
		for (int u = 0; u < G[v].size(); u++) {
			edge e = G[v][u];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(p(d[e.cost], d[e.to]));
			}

		}

	}

}



