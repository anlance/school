#include<iostream>
using namespace std;

int n;
int t;
int s[105];

int main(){
    while(cin>>n){
        cin >>t;
        long long num = 0;
        for (int i = 0; i < n;i++){
            cin >> s[i];
            s[i] = 86400 - s[i];
        }
        for (int i = 0; i < n;i++){
            num += s[i];
            if(num>=t){
                num = i+1;
                break;
            }
        }
            cout << num << endl;
    }
    return 0;
}