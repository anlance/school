#include<iostream>
#include<queue>
using namespace std;

char map[102][102];
bool vis[102][102];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int R, C;
struct Node{
    int x;
    int y;
};

bool check(int x, int y){
    if(x<0||x>=R||y<0||y>=C){
        return false;
    }
    if(!vis[x][y]){
        return false;
    }
    return true;
}

void init(){
    for (int i = 0; i < R;i++){
        for (int j = 0; j < C;j++){
            if(map[i][j]=='@'){
                vis[i][j] = true;
            }
            else{
                vis[i][j] = false;
            }
        }
    }
}
void bfs(int x, int y){
    queue<Node> Q;
    Node temp, next;
    temp.x = x;
    temp.y = y;
    Q.push(temp);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        for (int i = 0; i < 8;i++){
            next.x = temp.x + dx[i];
            next.y = temp.y + dy[i];
            if(check(next.x,next.y)){
                vis[next.x][next.y] = false;
                Q.push(next);
            }
        }
    }
}

int main(){
    while(cin>>R>>C){
        if(R==0)
            return 0;
        int count = 0;
        for (int i = 0;i<R;i++){
            for (int j = 0; j < C;j++){
                cin >> map[i][j];
            }
        }
        init();
        for (int i = 0; i < R;i++){
            for (int j = 0; j < C;j++){
                if(!vis[i][j])
                    continue;
                else{
                    bfs(i,j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}