#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

/*
RE了
我去。。。
思想还是不错的
*/

struct Node{
    int to;
    int cost;
};
struct helpNode{
    int from, to;
    int cost;
};
bool cmp(helpNode a, helpNode b){
    return a.from < b.from;
}
vector<vector<Node> > start;//二维数组，
vector<Node> save;
vector<Node> kong;
int T, N, M;

int doit(){
    queue<Node> Q;
    for (int i = 0; i < start[1].size();i++){
        Q.push(start[1][i]);
    }
    Node temp, next;
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp.to==N){
            save.push_back(temp);
        }
        int x = temp.to;
        for (int i = 0; i < start[x].size();i++){
            next = start[x][i];
            if(temp.cost<next.cost){
                next.cost = temp.cost;
            }
            Q.push(next);
        }
    }
    int max = 0;
    for (int i = 0; i < save.size();i++){
        if(max<save[i].cost){
            max = save[i].cost;
        }
    }
    return max;
}

int main(){
    cin >> T;
    for (int i = 1; i < T + 1;i++){
        cin >> N >> M;
        save.clear();
        start.clear();
        kong.clear();
        helpNode temp;
        Node tt;
        vector<helpNode> help;
        int len = start.size();
        for (int j = 0; j < M;j++){
            cin >> temp.from >> temp.to >> temp.cost;
            if(temp.from>temp.to){
                swap(temp.from, temp.to);
            }
            //start[x].push_back(temp);
            help.push_back(temp);   //存储输入的所有点
        }
        sort(help.begin(), help.end(), cmp);    //从小到大排序
        temp = help[help.size() - 1];
        help.push_back(temp);   //增加最后一个元素 使最后两个一定相同
        int number = 0;
        for (int k = 0; k < help.size()-1;k++){
                number = help[k].from;
                tt.to = help[k].to;
                tt.cost = help[k].cost;
                if(help[k+1].from==help[k].from){
                    save.push_back(tt);     //相同起点的放入一个数组中
                }
                else{
                    int n = number - start.size();
                    while(n!=0){
                        start.push_back(kong);
                        n--;
                    }
                    save.push_back(tt);     //不同时,存入help[k];
                    start.push_back(save);
                    save.clear();
                }
        }
        start.push_back(save);  //存入最后一组起点相同de
        save.clear();
        int result = doit();
        cout << "Scenario #" << i << ":" << endl;
        cout << result << endl;
    }
    cout << endl;
    return 0;
}