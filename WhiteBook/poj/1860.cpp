#include<iostream>
#include<cstring>
using namespace std;

int n, m, s;
double v;
int all;
double d[102];
struct Node{
    int a, b;
    double r, c;
};
Node exc[202];

bool bellman(){
    memset(d, 0, sizeof(d));
    d[s] = v;

    bool flag;
    for (int i = 1; i < n ;i++){
        flag = false;
        for (int j = 0; j < all;j++){
            if(d[exc[j].b]<(d[exc[j].a] - exc[j].c) * exc[j].r){
                d[exc[j].b] = (d[exc[j].a] - exc[j].c) * exc[j].r;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
    for (int k = 0;k<all;k++)
        if(d[exc[k].b]<(d[exc[k].a]-exc[k].c)*exc[k].r)
            return true;
            
    return false;
}

int main(){
    int a, b;
    double rab, cab, rba, cba;
    while(cin>>n>>m>>s>>v){
        all = 0;
        for (int i = 0; i < m;i++){
            cin >> a >> b >> rab >> cab >> rba >> cba;
            exc[all].a = a;
            exc[all].b = b;
            exc[all].r = rab;
            exc[all++].c = cab;
            exc[all].a = b;
            exc[all].b = a;
            exc[all].r = rba;
            exc[all++].c = cba;
        }
        if(bellman()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}