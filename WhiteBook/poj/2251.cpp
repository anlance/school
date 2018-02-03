#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define Msize 32
char map[Msize][Msize][Msize];
bool vis[Msize][Msize][Msize];
int dx[6]={-1,1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,1,-1};

int L, R, C;
int sx, sy, sz;
int ex, ey, ez;

struct Node{
    int x, y, z, step;
};

bool check(int x,int y, int z){
    if(x<0||y<0||z<0||x>=L||y>=R||z>=C||map[x][y][z]=='#'||vis[x][y][z]==true)
         return true;
    return false;
}

int bfs(int x,int y, int z){
    Node a, next;
    queue<Node> Q;
    a.x = sx;
    a.y = sy;
    a.z = sz;
    a.step = 0;
    vis[sx][sy][sz] = true;
    Q.push(a);
    while(!Q.empty()){
        a = Q.front();
        Q.pop();
        if(a.x==ex && a.y==ey && a.z==ez){
            return a.step;
        }
        for (int i = 0; i < 6;i++){
            next.x = a.x + dx[i];
            next.y = a.y + dy[i];
            next.z = a.z + dz[i];
            if(check(next.x,next.y,next.z))
                continue;
            vis[next.x][next.y][next.z] = true;
            next.step = a.step + 1;
            Q.push(next);
        }
    }
    return 0;
}

int main(){
    while(cin>>L>>R>>C){
        if(L==0)
            break;
        for (int i = 0; i < L;i++){
            for (int j = 0; j < R;j++){
                for (int k = 0; k < C;k++){
                    cin >> map[i][j][k];
                    if(map[i][j][k]=='S'){
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                    if(map[i][j][k]=='E'){
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }
        memset(vis, false, sizeof(vis));
        int result = bfs(sx, sy, sz);
        if(result!=0){
            cout << "Escaped in " << result << " minute(s)." << endl;
        }
        else{
            cout << "Trapped!" << endl;
        }
    }
}