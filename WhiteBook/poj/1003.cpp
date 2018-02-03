#include<iostream>
using namespace std;

float tt;

int doit(){
    float sum = 0.0;
    int i=2;
    while(sum<=tt){
        sum += (float)  (1.0/i);
        i++;
    }
    return i - 2;
}

int main(){
    while(cin>>tt){
        if(tt == 0.00)
            break;
        int result = doit();
        cout << result << " card(s)" << endl;  
    }
    return 0;
}