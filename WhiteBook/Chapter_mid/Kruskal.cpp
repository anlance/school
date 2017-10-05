#include<iostream>
#include"init_union_find.h"
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

//最小生成树问题2
//Kruskal算法
//
//按照边的权值大小从小到大查看一遍，如果不产生圈
//就把这条边加入到生成树中

const int max_e = 20;

struct edge {
	int u,v;
	int cost;
};


bool comp(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}

edge es[max_e];
int V, E;

int kruskal() {
	sort(es, es + V, comp);		//按照cost从小到大排序
	init(V);	//并查集的初始化
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
