#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
把所有终点放到一个数组里面
对两个起点进行bfs

把家和店假设成可以经过的

4 4
###@
###.
###M
###Y

这种情况

*/

struct Node{
    int x, y;
    int step;
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char map[201][201];
bool vis[201][201];
int num[201][201];
int R, C;
int ax, ay;
int bx, by;
int number;
vector<Node> V;

bool check(int x, int y){
    if(x<0||x>R-1||y<0||y>C-1){
        return false;
    }
    if(!vis[x][y]){
        return false;
    }
    return true;
}

void init(int R, int C){
    number = 0;
    for (int i = 0; i < R;i++){
        for (int j = 0; j < C;j++){
            if(map[i][j]=='Y'){
                ax = i;
                ay = j;
                vis[i][j] = true;
            }
            else if(map[i][j]=='M'){
                bx = i;
                by = j;
                vis[i][j] = true;
            }
            else if(map[i][j]=='#'){
                vis[i][j] = false;
            }
            else if(map[i][j]=='@'){
                number++;
                vis[i][j] = true;
            }
            else
                vis[i][j] = true;
        }
    }
}

void doit(int x,int y){
    queue<Node> Q;
    Node temp, next;
    temp.x = x;
    temp.y = y;
    temp.step = 0;
    vis[temp.x][temp.y] = false;
    Q.push(temp);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(number==0){
            break;
        }
        for (int i = 0; i < 4;i++){
            next.x = temp.x + dx[i];
            next.y = temp.y + dy[i];
            next.step = temp.step + 1;
            if(check(next.x,next.y)){
                vis[next.x][next.y] = false;
                if(map[next.x][next.y]=='@'){
                    num[next.x][next.y] += next.step;
                    Q.push(next);
                    next.step = num[next.x][next.y];
                    V.push_back(next);
                    number--;
                }
                else{
                    Q.push(next);
                }
            }
        }
    }
}

int main(){
    while(cin>>R>>C){
        V.clear();
        for (int i = 0; i < R;i++){
            for (int j = 0; j < C;j++){
                cin >> map[i][j];
                num[i][j] = 0;
                if(map[i][j]=='Y'){
                    ax = i;
                    ay = j;
                }
                else if(map[i][j]=='M'){
                    bx = i;
                    by = j;
                }
            }
        }
        init(R,C);
        doit(ax, ay);
        init(R, C);
        doit(bx, by);
        int min = 401*11;
        for (int i= V.size()/2; i < V.size();i++){
            //cout << V.at(i).step << endl;
            if (min > V.at(i).step){
                min = V.at(i).step;
            }
        }
        cout << min*11 << endl;
    }
    return 0;
}