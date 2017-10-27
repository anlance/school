#include<iostream>
using namespace std;

int n, x;
int s[100000];

int main(){
    while(cin>>n){
        cin >> x;
        int a;
        int num = 0;
        for (int i = 0; i < n;i++){
            cin >> a;
            num += a;
        }
        if((x-num)==(n-1)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}