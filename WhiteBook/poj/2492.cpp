#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> par;
vector<int> rank;
int N;
int bug, act;
bool flag;

void init(int n){
    par.clear();
    rank.clear();
    par.reserve((n+1)*2);
    rank.reserve((n+1)*2);
    for (int i = 0; i < (n + 1)*2;i++){
        par.push_back(i);
        rank.push_back(0);
    }
    flag = false;
}

int find(int a){
    if(par.at(a)==a)
        return a;
    return par.at(a) = find(par.at(a));
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)
        return;
    if(rank.at(a)<rank.at(b))
        par.at(a) = b;
    else{
        par.at(b) = a;
        if(rank.at(a)==rank.at(b))
            rank.at(a)++;
    }
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){
    int a, b;
    scanf("%d", &N);
    for (int i = 1; i < N + 1;i++){
        scanf("%d%d", &bug, &act);
        init(bug);
        for (int j = 0; j < act;j++){
            scanf("%d%d", &a, &b);
            if(same(a,b)||same(a+bug,b+bug)){
                flag = true;
            }
            else{
                unite(a, b + bug);
                unite(b, a + bug);
            }
        }
        if(i!=1)
            cout << endl;
        cout << "Scenario #" << i << ":" << endl;
        if(flag){
            cout << "Suspicious bugs found!" << endl;
        }
        else{
           cout << "No suspicious bugs found!" << endl;
       }
   }
}