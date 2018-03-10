#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define maxv 755
#define maxe 281255
int N, M, E;
struct Edge{
    int from, to;
    int cost;
};
bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}
Edge edge[maxe];
Edge node[maxv];
Edge save[maxv];
vector<int> par;
vector<int> rank;

void init(int n){
    par.clear();
    rank.clear();
    par.reserve(n);
    rank.reserve(n);
    for (int i = 0; i < n;i++){
        par.push_back(i);
        rank.push_back(0);
    }
}

int find(int a){
    if(par.at(a)==a)
        return a;
    return par.at(a) = find(par.at(a));
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)
        return;
    if(rank.at(a)<rank.at(b))
        par.at(a) = b;
    else{
        par.at(b) = a;
        if(rank.at(a)==rank.at(b))
            rank.at(a)++;
    }
}

bool same(int a, int b){
    return find(a) == find(b);
}

int kruskal(){
    sort(edge, edge + E, cmp);
    Edge e;
    int res = 0;
    for (int i = 0; i < E;i++){
        e = edge[i];
        if(!same(e.from, e.to)){
            unite(e.from, e.to);
            save[res].from = e.from;
            save[res].to = e.to;
            save[res].cost = e.cost;
            res++;
        }
    }
    return res;
}

int main(){
    while(cin>>N){
        for (int i = 1; i < N + 1;i++){
            cin >> node[i].from >> node[i].to;
            node[i].cost = 0;
        }
        E = 0;
        for (int i = 1; i < N + 1;i++){
            for (int j = i + 1; j < N + 1;j++){
                edge[E].from = i;
                edge[E].to = j;
                edge[E].cost = (node[i].from - node[j].from) * (node[i].from - node[j].from) + (node[i].to - node[j].to) * (node[i].to - node[j].to);
                E++;
            }
        }
        init(N + 1);
        cin >> M;
        int a, b;
        for (int i = 0; i < M;i++){
            cin >> a >> b;
            unite(a, b);
        }
        int ans = kruskal();
        for (int i = 0; i < ans;i++){
            cout << save[i].from << " " << save[i].to << endl;
        }
        if(ans==0)
            cout << " ";
    }
    return 0;
}