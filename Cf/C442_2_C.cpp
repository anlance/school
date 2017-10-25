#include<iostream>
using namespace std;

int main(){
    int N = 0;
    int result = 0;
    int a = 0, b = 0;
    while(cin>>N){
        a = N / 2;
        b = N - a;
        result = a * 2 + b;
        cout << result << endl;
        for (int i = 2; i < N + 1; i += 2){
            cout << i << " ";
        }
        for (int i = 1; i < N + 1;i+=2){
            cout << i << " ";
        }
        for (int i = 2; i < N + 1; i += 2){
            cout << i << " ";
        }
        cout << endl;
    }
}