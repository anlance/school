#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> par;
vector<int> rank;
#define maxv 105
#define maxe 10005
struct Edge{
    int from, to;
    int cost;
};
Edge edge[maxe];
bool used[maxe];
bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}
int N, E;

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
    for (int i = 0; i < E;i++){
        used[i] = false;
    }
    int res = 0;
    Edge temp;
    init(N);
    for (int i = 0; i < E;i++){
        temp = edge[i];
        if(temp.from==temp.to)
            continue;
        if(!same(temp.from, temp.to)){
            res += temp.cost;
            unite(temp.from, temp.to);
            used[i] = true;
        }
    }
    bool flag = false;
    for (int i = 0; i < E;i++){
        if (used[i] == false)
            continue;
        int ans = 0;
        init(N);
        for (int j = 0; j < E ;j++){
            temp = edge[j];
            if(temp.from==temp.to || j==i)
                continue;
            if(!same(temp.from, temp.to)){
                ans += temp.cost;
                unite(temp.from, temp.to);
            }
        }
        flag = false;
        for (int k = 2; k < N + 1;k++){
            if(!same(1,k)){
                flag = true;
                break;
            }
        }
        if(flag==true)
            continue;
        if(ans==res)
            return -1;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T;i++){
        cin >> N >> E;
        for (int j = 0; j < E;j++){
            cin >> edge[j].from >> edge[j].to >> edge[j].cost;
        }
        int ans = kruskal();
        if(N==0)
            ans = 0;
        if(ans==-1)
            cout << "Not Unique!" << endl;
        else
            cout << ans << endl;
    }
}