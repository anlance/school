#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char map[5][5];
bool vis[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, 1, -1};

struct Node{
    int x, y;
    int preX, preY;
};
bool check(int x, int y){
    if(x<0||x>4||y<0||y>4){
        return false;
    }
    if(!vis[x][y]){
        return false;
    }
    return true;
}

void init(){
    for (int i = 0; i < 5;i++){
        for (int j = 0; j < 5;j++){
            if(map[i][j]=='1'){
                vis[i][j] = false;
            }
            else{
                vis[i][j] = true;
            }
        }
    }
}

int doit(){
    queue<Node> Q;
    vector<Node> V;
    vector<Node> roate;
    Node temp, next;
    temp.x = 0;
    temp.y = 0;
    temp.preX = 5;
    temp.preY = 5;
    Q.push(temp);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        V.push_back(temp);
        if(temp.x==4&&temp.y==4){
            break;
        }
        for (int i = 0; i < 4;i++){
            next.preX = temp.x;
            next.preY = temp.y;
            next.x = temp.x + dx[i];
            next.y = temp.y + dy[i];
            if(check(next.x,next.y)){
                vis[next.x][next.y] = false;
                Q.push(next);
            }
        }
    }
    int i = V.size() - 1;
    int j = V.size() - 1;
    int count = j;
    while(i--&&i>-1){
        i = j;
        //cout << "i" << i << endl;
        temp = V.at(i);
        roate.push_back(temp);
        for (j = i - 1; j > -1;j--){
            next = V.at(j);
            if(temp.preX == next.x && temp.preY == next.y){
                //cout << "j" << j<<endl;
                break;
            }
        }
    }
    
    for (int i = roate.size() - 1; i > -1; i--){
        cout << "(" << roate.at(i).x << ", " << roate.at(i).y << ")" << endl;
    }
    return 0;
}

int main(){
    for (int i = 0; i < 5;i++){
        for (int j = 0; j < 5;j++){
            cin >> map[i][j];
        }
    }
    init();
    int result = doit();
    return 0;
}