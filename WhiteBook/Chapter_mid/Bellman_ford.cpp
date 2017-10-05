#include<iostream>
#include<vector>
using namespace std;

const int MAX_E=20;
const int MAX_V=8;
const int INF = 65236;
//单源最短路问题1
//Bellman-Ford算法


//图中不存在负圈
//从顶点from指向顶点to的权值为cost的边
struct edge {
	int from;
	int to;
	int cost;
};

edge es[MAX_E];	//边

int d[MAX_V];		//最短距离
int V, E;	//顶点，边

//求解顶点s出发到所有顶点的最短距离
void shortest_path(int s) {
	for (int i = 0; i < V; i++)
		d[i] = INF;
	d[s] = 0;
	while (true) {
		bool update = false;
		for (int i = 0; i < E; i++) {
			edge e = es[i];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update)
			break;
	}
}
