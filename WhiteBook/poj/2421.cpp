#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> par;
vector<int> rank;
#define maxv 10005
struct Edge{
    int from, to;
    int cost;
};
Edge edge[maxv];
bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}
int N, E, Q;

void init(int n){
    par.clear();
    rank.clear();
    par.reserve(n+1);
    rank.reserve(n+1);
    for (int i = 0; i < n + 1; i++){
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
    int res = 0;
    Edge temp;
    for (int i = 0; i < E;i++){
        temp = edge[i];
        if(temp.from==temp.to)
            continue;
        if(!same(temp.from, temp.to)){
            res += temp.cost;
            unite(temp.from, temp.to);
        }
    }
    return res;
}

int main(){
    while(cin>>N){
        init(N);
        int tc;
        for (int i = 1; i < N + 1;i++){
            for (int j = 1; j < N + 1;j++){
                edge[E].from = i;
                edge[E].to = j;
                cin >> edge[E].cost;
                E++;
            }
        }
        cin >> Q;
        int f, t;
        for (int i = 0; i < Q;i++){
            cin >> f >> t;
            unite(f, t);
        }
        int ans = kruskal();
        cout << ans << endl;
    }
    return 0;
}