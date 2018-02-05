#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//Crawling of this problem failed or hasn't finished

char map[11][11];
bool vis[11][11];
int res[101];
int t, n, m;
int number, tNumber;

struct Node{
    int x;
    int y;
    int step;
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<Node> V;

bool check(int x,int y){
    if(x<0||y>m-1||x>n-1||y<0){
        return false;
    }
    else{
        if(!vis[x][y]){
            return false;
        }
        return true;
    }
}


int doit(Node a, Node b){
    Node temp, next;
    queue<Node> Q, P;
    int count = 0;

    Q.push(a);
    vis[a.x][a.y] = false;
    tNumber--;

    P.push(b);
    vis[b.x][b.y] = false;
    tNumber--;

    while((!Q.empty())||(!P.empty())){
        if(tNumber==0){
            return count;
        }
        if(!Q.empty()){
            temp = Q.front();
            Q.pop();
            for (int i = 0; i < 4;i++){
                next.x = temp.x + dx[i];
                next.y = temp.y + dy[i];
                next.step = temp.step + 1;
                if(check(next.x, next.y)){
                    Q.push(next);
                    if(count<next.step)
                        count = next.step;
                    vis[next.x][next.y] = false;
                    tNumber--;
                    //cout << "t1-" << tNumber << endl;
                }
            }
        }
        if(!P.empty()){
            temp = P.front();
            P.pop();
            for (int i = 0; i < 4;i++){
                next.x = temp.x + dx[i];
                next.y = temp.y + dy[i];
                next.step = temp.step + 1;
                if(check(next.x, next.y)){
                    P.push(next);
                    if(count<next.step)
                        count = next.step;
                    vis[next.x][next.y] = false;
                    tNumber--;
                    //cout << "t2-" << tNumber << endl;
                }
            }
        }
    }
    if(tNumber!=0){
        return -1;
    }
}


int main(){
    cin >> t;
    for (int i = 0; i < t;i++){
        cin >> n >> m;
        Node node;
        number = 0;
        V.clear();
        for (int j = 0; j < n;j++){
            for (int k = 0; k < m;k++){
                cin >> map[j][k];
                if(map[j][k]=='#'){
                    number++;
                    node.x = j;
                    node.y = k;
                    node.step = 0;
                    V.push_back(node);
                    vis[j][k] = true;
                }
                else{
                    vis[j][k] = false;
                }
            }
        }
        if(number==1||number==2){
            res[i] = 0;
            continue;
        }
        int min = 10;
        Node node1, node2;
        for (int j = 0; j < V.size();j++){
            node1 = V.at(j);
            for (int k = 1; k < V.size();k++){
                node2 = V.at(k);

                for (int b = 0; b < n;b++){
                    for (int c = 0; c < m;c++){
                        if(map[b][c]=='#'){
                            vis[b][c] = true;
                        }
                        else{
                            vis[b][c] = false;
                        }
                    }
                }
                tNumber = number;
                int result = doit(node1, node2);
                if(result!=-1){
                    if(result<min){
                        min = result;
                    }
                }
            }
        }
        min == 10 ? res[i] = -1 : res[i] = min;
    }
    for (int i = 0; i < t;i++){
        cout << "Case " << i << ": " << res[i] << endl;
    }
    return 0;
}