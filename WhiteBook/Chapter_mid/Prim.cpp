#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

//最小生成树问题1
//prim算法
//不断从当前点寻找与之相连的最小边的点
//将已经相连的点保存到树中

const int max_v = 20;
const int INF = 65236;
//cost[u][v]表示边的权值
int cost[max_v][max_v];		
int mincost[max_v];		//从当前点出发到每个顶点的最小值
bool used[max_v];	//顶点是否保存在树T中
int V;

int prim() {
	for (int i = 0; i < V; i++) {
		mincost[i] = INF;
		used[i] = false;
	}
	int res = 0;
	while (true) {
		int v = -1;
		mincost[v] = INF;
		//从不属于树T中顶点中选取从当前点到其权值最小的顶点
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;
		}
		if (v == -1)
			break;
		used[v] = true;	//把顶点加入树T
		res += mincost[v];	//把边的长度加入到结果里
		for (int u = 0; u < V; u++) {
			if (!used[u])
				mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}
