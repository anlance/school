#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//单源最短路问题2
//Dijkstra算法
//不能存在负边

const int max_v=20;
const int INF = 65236;

int cost[max_v][max_v];	//邻接矩阵表示法
int d[max_v];	//顶点s出发的最短距离
bool used[max_v];	//已经使用过的顶点
int V;	//顶点数

//求从起点s出发到各个顶点的最短距离
void Dijkstra(int s) {
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;
	while (true) {
		int v = -1;
		//从尚未使用过的顶点中选择一个距离最小的顶点
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}
		if (v == -1)
			break;
		used[v] = true;
		for (int u = 0; u < V; u++) {
			d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}


