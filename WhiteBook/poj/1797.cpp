#include<iostream>
#include<algorithm>
using namespace std;

#define maxv 1010
#define maxe 1000010
#define INF 0x3f3f3f
struct Node{
    int from, to;
    int cost;
} edge[maxe];
int n, m;

int doit(){
    int i, j, d[maxv];
    for (i = 1; i < n + 1;i++)
        d[i] = 0;
    d[1] = INF;
    int flag = 1;
    while(flag){
        flag = 0;
        for (j = 1; j < m + 1;j++){
            if(d[edge[j].to]<min(d[edge[j].from],edge[j].cost)){
                d[edge[j].to] = min(d[edge[j].from], edge[j].cost);
                flag = 1;
            }
            if(d[edge[j].from]<min(d[edge[j].to],edge[j].cost)){
                d[edge[j].from] = min(d[edge[j].to], edge[j].cost);
                flag = 1;
            }
        }
    }
    return d[n];
}

int main(){
    int t;
    cin >> t;
    for (int i = 1; i < t + 1;i++){
        cin >> n >> m;
        for (int j = 1; j < m+1;j++){
                cin >> edge[j].from >> edge[j].to >> edge[j].cost;
            }
        int result = doit();
        cout << "Scenario #" << i << ":" << endl;
        cout << result << endl;
        cout << endl;
    }
}