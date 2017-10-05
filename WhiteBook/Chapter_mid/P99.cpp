#include<iostream>
#include<vector>
using namespace std;

#define max_v 20

vector<int>G[max_v];	//图
int V;	//顶点数
int color[max_v];		//顶点i的颜色

bool dfs(int v,int c) {
	color[v] = c;	//把顶点v染成颜色c
	for (int i = 0; i < G[v].size(); i++) {
		//如果相邻的顶点颜色相同，返回false
		if (color[G[v][i]] == c)
			return false;
		//如果顶点还没被染色，则染成-c
		if (color[G[v][i] == 0] && !dfs(G[v][i], -c))
			return false;
	}
	//如果所有顶点然过色了，返回true
	return true;
}

int main(){
	cin >> V;
	for (int i = 0; i < V; i++) {
		if (color[i] == 0) {
			//如果顶点还没被染色，染成1
			if (!dfs(i, 1)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
