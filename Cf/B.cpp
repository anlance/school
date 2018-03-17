#include<iostream>
#include<algorithm>
using namespace std;

#define maxv  100005
int n;
long  x[maxv];

int main(){
    int num = 0;
    long minDis = 0;
    while(cin>>n){
        for (int i = 0; i < n;i++){
            cin >> x[i];
        }
        sort(x, x + n);
        minDis = x[1] - x[0];
        for (int i = 0; i +1 < n;i++){
            if(minDis>x[i+1]-x[i])
                minDis = x[i + 1] - x[i];
        }
        long  temp = x[n - 1] - x[0] + minDis;
        int ans = temp / minDis;
        int res = ans - n;
        cout << res << endl;
    }
    return 0;
}