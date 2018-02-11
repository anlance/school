#include<iostream>
#include<cstring>
using namespace std;

/*
虫洞：农夫约翰有 F 个农场，每个农场有 N 块地，其间有 M 条路，W 条时光隧道（时间倒流）。
*/
#define maxv 505
#define maxe 5210
int d[maxv];
struct Node{
    int from;
    int to;
    int cost;
};
Node edge[maxe];
int N, M, W;
int all;

bool bellman(){
    memset(d, 0, sizeof(d));
    for (int i = 1; i < N+1;i++){
        for (int j = 0; j < all;j++){
            Node temp = edge[j];
            if(d[temp.to]>(d[temp.from]+temp.cost)){
                d[temp.to] = d[temp.from] + temp.cost;
                if(i==N){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int F;
    Node temp;
    while(cin>>F){
        for (int i = 0; i < F;i++){
            cin >> N >> M >> W;
            all = 0;
            for (int j = 0; j < M;j++){
                cin >> temp.from >> temp.to >> temp.cost;
                edge[all] = temp;
                all++;
                edge[all].from = temp.to;
                edge[all].to = temp.from;
                edge[all].cost = temp.cost;
                all++;
            }
            for (int j = 0; j < W;j++){
                cin >> temp.from >> temp.to >> temp.cost;
                temp.cost = -temp.cost;
                edge[all] = temp;
                all++;
            }
            if(bellman()){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}