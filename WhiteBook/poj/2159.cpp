#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

char pre[105];
char next[105];
int p[26];
int n[26];

bool doit(string &a, string &b){
    int length = a.length();
    for (int i = 0; i < length;i++){
        pre[i] = a[i];
        next[i] = b[i];
        p[(int)(pre[i] - 'A')]++;
        n[(int)(next[i] - 'A')]++;
    }
    sort(p, p + 26);
    sort(n, n + 26);
    for (int i = 0; i < 27;i++){
        //cout << p[i] << "--" << n[i] << endl;
        if(p[i]!=n[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string a, b;
    while(cin>>a>>b){
        for (int i = 0; i < 27;i++){
            p[i] = 0;
            n[i] = 0;
        }
        for (int j = 0; j < 105;j++){
            pre[j] = 'A';
            next[j] = 'A';
        }
            if (doit(a, b))
            {
                cout << "YES" << endl;
            }
            else{
            cout << "NO" << endl;
            }
    }
}
