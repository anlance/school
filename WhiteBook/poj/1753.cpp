#include<iostream>
#include<queue>
using namespace std;
bool map[4][4];
bool temp[4][4];

struct Node{
    int x;
    int y;
}
int table[65536];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void flip(int x,int y){
    map[x][y] = ![x][y];
    if(x-1>=0)
        temp[x - 1][y] ^= 1;
    if(x+1<=3)
        temp[x + 1][y] ^= 1;
    if(y-1>=0)
        temp[x][y - 1] ^= 1;
    if(y+1<=3)
        temp[x][y + 1] ^= 1;
}

int doit(){//全0
    int count = 0;
    queue<Node> Q;
    Q.push(0, 0);
    Node next;
    while(Q.empty()){
        Node tt = Q.front();
        Q.pop();
        for (int i = 0; i < 4;i++){
            next.x = tt.x + dx[i];
            next.y = tt.y + dy[i];
        }
    }
}