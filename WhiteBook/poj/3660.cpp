#include<iostream>
#include<cstring>
using namespace std;

#define maxv 105
int map[maxv][maxv];
int N, M;

void floyd(){
    for (int k = 1; k < N + 1;k++){
        for (int i = 1; i < N + 1;i++){
            for (int j = 1; j < N + 1;j++){
                if((map[i][k]&&map[k][j])||map[i][j]){
                    map[i][j] = 1;
                }
            }
        }
    }
}

int main(){
    while(cin>>N>>M){
        memset(map, 0, sizeof(map));
        int from, to;
        for (int i = 0; i < M;i++){
            cin >> from >> to;
            map[from][to] = 1;
        }
        floyd();
        int ans, res = 0;
        for (int i = 1; i < N + 1;i++){
            ans = 0;
            for (int j = 1; j < N + 1;j++){
                if(i==j)
                    continue;
                else if(map[i][j]||map[j][i])
                    ans++;
            }
            if(ans==N-1){
                res++;
                //cout << "--" << i << endl;
            }
        }
        cout << res << endl;
    }
    return 0;
}