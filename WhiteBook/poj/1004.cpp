#include<iostream>
using namespace std;

double x;
double sum;

int main(){
    while(cin>>x){
        sum = 0.00;
        sum += x;
        for (int i = 0; i < 11;i++){
            cin >> x;
            sum += x;
        }
        double result = (double)(sum / 12);
        cout << "$" << result << endl;
    }
}