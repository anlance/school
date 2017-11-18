#include<iostream>
#include<algorithm>
using namespace std;


long N;
long long a[100001];
long long b[100001];

int main(){
    while(cin>>N){
        int temp = 0;
        long long Max = 0;
        long long Max2 = 0;
        for (int i = 0; i < N;i++){
            cin >> a[i];
        }
        sort(a, a+N);
        for (int i = 0; i < N;i++){
            cin >> b[i];
            if(b[i]>=Max){
                Max = b[i];
                temp = i;
            }
        }
        b[temp] = 0;
        for (int i = 0; i < N;i++){
            if(b[i]>=Max2){
                Max2 = b[i];
            }
        }
        for (int i = N - 1; i >= 0;i--){
            if(Max-a[i]>=Max2-a[i]){
                Max -= a[i];
            }else{
                Max2 -= a[i];
            }
        }
        if(Max2>=0&&Max>=0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

