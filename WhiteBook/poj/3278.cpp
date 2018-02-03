#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int sx, ex;
int dx[3] = {1,-1, 0};
//vector<int> vis;
const int maxn=100001;
bool vis[maxn];
struct Node{
    int x, step;
};

// 
bool check(int x){
    if(x<0||x>maxn-1||vis[x]==true)
        return true;
    return false;
}

int bfs(int x){
    Node a,next;
    queue<Node> Q;
    a.x = x;
    a.step = 0;
    Q.push(a);
    //vis.push_back(a.x);
    vis[a.x] = true;
    while(!Q.empty()){
        a = Q.front();
        Q.pop();
        dx[2] = a.x;
        if(a.x==ex){
            return a.step;
        }
        for (int i = 0; i < 3;i++){
            next.x = a.x + dx[i];
            if(check(next.x)){
                    continue;
            }
            next.step =a.step+1;
            //vis.push_back(next.x);
            vis[next.x] = true;
            Q.push(next);
        }
        
    }
    return 0;
}

int main(){
    while(cin>>sx>>ex){
        //vis.clear();
        memset(vis, false, sizeof(vis));
        int result = bfs(sx);
        cout << result << endl;
    }
    return 0;
}