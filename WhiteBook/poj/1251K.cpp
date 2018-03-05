#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define maxv 30
#define maxe 105
int N, E;
struct Edge{
    int from, to;
    int cost;
};
bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}
Edge edge[maxe];
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
    init(N);
    int res = 0;
    Edge e;
    for (int i = 0; i < E;i++){
        e = edge[i];
        if(!same(e.from, e.to)){
            unite(e.from, e.to);
            res += e.cost;
        }
    }
    return res;
}

int main(){
    char f, t;
    int ct;
    int cTo = 0;
    while(cin>>N){
        if(N==0)
            break;
        E = 0;
        for (int i = 0; i < N - 1;i++){
            cin >> f >> cTo;
            for (int j = 0; j < cTo;j++){
                cin >> t >> ct;
                edge[E].from = (int)f - 65;
                edge[E].to = (int)t - 65;
                edge[E].cost = ct;
                E++;
            }
        }
        int ans = kruskal();
        cout << ans << endl;
    }
    return 0;
}