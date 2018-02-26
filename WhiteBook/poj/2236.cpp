#include<iostream>
#include<vector>
using namespace std;

vector<int> par;
vector<int> rank;
#define maxv 1010
int x[maxv], y[maxv];
bool used[maxv];
int N,d;

void init(int n){
    par.reserve(n+1);
    rank.reserve(n+1);
    for (int i = 0; i < n+1;i++){
        par.push_back(i);
        rank.push_back(0);
    }
}

int find(int a){
    if(par.at(a)==a)
        return a;
    return par.at(a)=find(par.at(a));
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)
        return;
    if(rank.at(a)<rank.at(b)){
        par.at(a) = b;
    }
    else{
        par.at(b) = a;
        if(rank.at(a) == rank.at(b))
            rank.at(a)++;
    }
}

bool dis(int a, int b){
    if(used[a]==true&&used[b]==true){
        int dx, dy;
        if(x[a]>x[b])
            dx = x[a] - x[b];
        else
            dx = x[b] - x[a];
        if(y[a]>y[b])
            dy = y[a] - y[b];
        else
            dy = y[b] - y[a];
        if(dx*dx+dy*dy<=d*d)
            return true;
        else
            return false;
    }
    return false;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

int main(){
    cin >> N >> d;
    init(N);
    for (int i = 1; i < N + 1;i++){
        cin >> x[i] >> y[i];
        used[i] = false;
    }
    char ch;
    int com1, com2;
    while(cin>>ch){
        if(ch=='O'){
            cin >> com1;
            used[com1] = true;
            for (int i = 1; i < N + 1 ;i++){
                if(i==com1)
                    continue;
                if(dis(com1,i))
                    unite(com1, i);
                }
            }
        else if(ch=='S'){
            cin >> com1 >> com2;
            if(same(com1,com2))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }
}