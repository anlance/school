#include <iostream>  
#include <queue>  
#include <cstring>  
  
using namespace std;  
  
const int MAXN = 100;  
  
int a, b, c;  
bool notvist[MAXN+1][MAXN+1];  
  
struct node {  
    int a, b, level;  
    char path[MAXN+1];  
    int plen;  
};  
  
string path[] = {  
     "FILL(1)"  
    ,"FILL(2)"  
    ,"DROP(1)"  
    ,"DROP(2)"  
    ,"POUR(1,2)"  
    ,"POUR(2,1)"  
};  
  
void output_result(int lvl, char p[], int n)  
{  
    cout << lvl << endl;  
    for(int i=0; i<n; i++)  
        cout << path[(int)p[i]] << endl;  
}  
  
void bfs()  
{  
    queue<node> q;  
    memset(notvist, true, sizeof(notvist));  
  
    node f;  
    f.a = 0;  
    f.b = 0;  
    f.level = 0;  
    memset(f.path, 0, sizeof(f.path));  
    f.plen = 0;  
    q.push(f);  
  
    notvist[f.a][f.b] = false;  
  
    while(!q.empty()) {  
        f = q.front();  
        q.pop();  
  
        if(f.a == c || f.b == c) {  
            output_result(f.level, f.path, f.plen);  
            return;  
        }  
  
        node v;  
  
        v = f;  
        v.level++;  
        v.plen++;  
        // FILL(a)  
        if(a - f.a > 0) {  
            v.a = a;  
            v.b = f.b;  
            if(notvist[v.a][v.b]) {  
                v.path[f.plen] = 0;  
                q.push(v);  
                notvist[v.a][v.b] = false;  
            }  
        }  
        // FILL(b)  
        if(b - f.b > 0) {  
            v.a = f.a;  
            v.b = b;  
            if(notvist[v.a][v.b]) {  
                v.path[f.plen] = 1;  
                q.push(v);  
                notvist[v.a][v.b] = false;  
            }  
        }  
        // DROP(a)  
        if(f.a) {  
            v.a = 0;  
            v.b = f.b;  
            if(notvist[v.a][v.b]) {  
                v.path[f.plen] = 2;  
                q.push(v);  
                notvist[v.a][v.b] = false;  
            }  
        }  
        // DROP(b)  
        if(f.b) {  
            v.a = f.a;  
            v.b = 0;  
            if(notvist[v.a][v.b]) {  
                v.path[f.plen] = 3;  
                q.push(v);  
                notvist[v.a][v.b] = false;  
            }  
        }  
        // POUR(a,b)  
        if(f.a && (f.b < b)) {  
            if(f.a > (b - f.b)) {  
                v.a = f.a -(b - f.b);  
                v.b = b;  
            } else {  
                v.a = 0;  
                v.b = f.b + f.a;  
            }  
            if(notvist[v.a][v.b]) {  
                v.path[f.plen] = 4;  
                q.push(v);  
                notvist[v.a][v.b] = false;  
            }  
        }  
        // POUR(b,a)  
        if(f.b && (f.a < a)) {  
            if(f.b > (a - f.a)) {  
                v.a = a;  
                v.b = f.b -(a - f.a);  
            } else {  
                v.a = f.a + f.b;  
                v.b = 0;  
            }  
            if(notvist[v.a][v.b]) {  
                v.path[f.plen] = 5;  
                q.push(v);  
                notvist[v.a][v.b] = false;  
            }  
        }  
    }  
  
    cout << "impossible" << endl;  
}  
  
int main()  
{  
    cin >> a >> b >> c;  
    bfs();  
    return 0;  
}  