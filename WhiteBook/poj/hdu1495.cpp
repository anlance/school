#include<iostream>
using namespace std;

int gcd(int a, int b){
    return a == 0 ? b : gcd(b % a, a);
}

int main(){
    int a, b, c;
    while(cin>>a>>b>>c){
        if(a==0){
            break;
        }
        if(a%2!=0){
            cout << "NO" << endl;
            continue;
        }
        a /= gcd(b, c);
        if(a%2!=0)
            cout << "NO" << endl;
        else 
            cout << a-1 << endl;
    }
}