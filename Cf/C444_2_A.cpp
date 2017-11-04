#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        int count = 0;
        bool judge = false;
        int  start = 0;
        for (int i = 0; i < str.length();i++){
            if(str[i]=='1'){
                start = i;
                judge = true;
                break;
            }
        }
        if(judge==false){
            cout << "no" << endl;
        }
        else{
            for (int j = start; j < str.length();j++){
                if(str[j]=='0'){
                    count++;
                }
            }
            if(count>=6){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}