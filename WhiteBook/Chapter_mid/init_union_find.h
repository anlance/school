#pragma once
//并查集的实现(用vector)
#include<iostream>
#include<vector>
using namespace std;

vector<int> par;	//父亲
vector<int> Trank;	//树的高度

//初始化n个元素
void init(int n) {
	par.reserve(n);
	Trank.reserve(n);
	for (int i = 0; i < n; i++) {
		par.push_back(i);
		Trank.push_back(0);
	}
}

//查询树的根
int find(int x) {
	if (par.at(x) == x)
		return x;
	return  find(par.at(x));
}

//合并x和y所属的集合
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (Trank.at(x) < Trank.at(y))
		par.at(x) = y;
	else {
		par.at(y) = x;
		if (Trank.at(x) == Trank.at(y))
			Trank.at(x)++;
	}
}
 
//判断x和y是否属于同一个集合
bool same(int x, int y) {
	return find(x) == find(y);
}
