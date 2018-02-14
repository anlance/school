#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define INF 0x3f3f3f
#define maxv 105
int power[maxv];
int map[maxv][maxv];
int d[maxv];        
bool used[maxv];
int N, M;
int minPower;
int minCost;

bool check(int a,int b){
    if(power[a]>power[b]){
        if(power[a]-power[b]>N)
            return false;
        return true;
    }
    else{
        if(power[b]-power[a]>N)
            return false;
        return true;
    }
}


bool checkMin(int a, int b){
    if(power[a]>power[b]){
        if(power[a]-minPower>N)
            return false;
        return true;
    }
    else{
        if(power[b]-minPower>N)
            return false;
        return true;
    }
}
// int dijkstra(){
//     d[1] = map[1][1];
//     minPower = power[1];

//     while(true){
//         int v = -1;
//         for (int i = 1; i < M+1;i++){
//             if(!used[i]&&(v==-1||d[i]<d[v]))
//                 v = i;
//         }
//         if(v==-1)
//             break;
//         used[v] = true;
//         for (int i = 1; i < M + 1;i++){
//             minPower = power[1];
//             if(check(i,v)){
//                 if(!used[i]&&d[i]>d[v]+map[v][i]){
//                     d[i] = d[v]+map[v][i];
//                 }
//             }
//         }
//     }
//     int min = INF;
//     for (int i = 1; i < M + 1;i++){
//         d[i] += map[i][i];
//         d[i] -= map[1][1];
//         if(min>d[i]){
//             min = d[i];
//         }
//     }
//     return min;
// }



//怀疑人生
// bool flag = true;
// void dfs(int x, int y){
//     flag = true;
//     for (int i = 1; i < M + 1;i++){
//         if(check(y,i)){
//             //cout << used[i] << "--" << d[i] << "--" <<d[y]+map[y][i] <<endl;
//             if(!used[i]&&d[i]>d[y]+map[y][i]){
//                 //cout << i << "----" << endl;
//                 int lastMinPower = minPower;
//                 if(checkMin(y,i)){
//                     if(power[y]>power[i])
//                         minPower = minPower > power[i] ? power[i]:minPower;
//                     minPower = minPower > power[y] ? power[y] : minPower;
//                     used[i] = true;
//                     flag = false;
//                     d[i] = d[y] + map[y][i];
//                     //cout << d[i] << "========";
//                     dfs(y, i);
//                     used[i] = false;
//                     minPower = lastMinPower;
//                 }
//             }
//         }
//     }
//     if(flag==true){
//         for (int i = 1; i < M + 1;i++){
//             d[i] += map[i][i];
//             d[i] -= map[1][1];
//             if(minCost>d[i]){
//                 minCost = d[i];
//             }
//             cout << d[i] << "***";
//         }
//         cout << endl;
//         return;
//     }
// }

int main(){
    while(cin>>N>>M){
        int x = 0;
        int T, V;
        memset(d, INF, sizeof(d));
        memset(used, false, sizeof(used));
        for(int i=1;i<M+1;i++){
            for (int j = 1; j < M + 1;j++){
                map[i][j] = INF;
            }
        }
        for (int i = 1; i < M + 1; i++){
            cin >> map[i][i] >> power[i] >> x;
            for (int j = 0; j < x;j++){
                cin >> T >> V;
                map[i][T] = V;
            }
        }
        minPower = power[1];
        used[1] = true;
        d[1] = map[1][1];
        dfs(1, 1);
        for (int i = 1; i < M + 1;i++){
            cout << d[i] << "*";
        }
    }
}


