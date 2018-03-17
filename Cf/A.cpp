#include<iostream>
using namespace std;

long long N;
long long l, r;

int main(){
    while(cin>>l>>r){
        long long sum = 1;
        int count = 0;
        if(l<=1)
            count++;
        while(sum*2<=r){
            sum *= 2;
            if(sum<l)
                continue;
            count++;
            // cout << sum << "--";
        }
        sum = 1;
        while(sum*3<=r){
            sum *= 3;
            if(sum<l)
                continue;
            count++;
            // cout << sum << "--";
        }
        sum = 1;
        while(sum*2<=r){
            sum *= 2;
            long long temp = sum;
            while(temp*3<=r){
                temp *= 3;
                if(temp<l)
                    continue;
                count++;
                // cout << temp << "--";
            }
        }
        // cout << endl;
        cout << count << endl;
    }
}