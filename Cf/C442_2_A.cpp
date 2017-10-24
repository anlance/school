#include<iostream>
#include<string>
using namespace std;

int main(){
    int count = 0;
    string give;
    while(cin>>give){
        count = 0;
        for (int i = 0; i < give.length();i++){
            string temp = "";
            if(give[i]=='A'){
                string temp = "";
                for (int j = 0; j < 3;j++){
                    temp += give[i + j];
                }
                if(temp=="Ann")
                    count++;
            }
            else if(give[i]=='D'){
                string temp = "";
                for (int j = 0; j < 5;j++){
                    temp += give[i + j];
                }
                if(temp=="Danil")
                    count++;
            }
            else if(give[i]=='O'){
                string temp = "";
                for (int j = 0; j < 4;j++){
                    temp += give[i + j];
                }
                if(temp=="Olya")
                    count++;
            }
            else if(give[i]=='S'){
                string temp = "";
                for (int j = 0; j < 5;j++){
                    temp += give[i + j];
                }
                if(temp=="Slava")
                    count++;
            }
            else if(give[i]=='N'){
                string temp = "";
                for (int j = 0; j < 6;j++){
                    temp += give[i + j];
                }
                if(temp=="Nikita")
                    count++;
            }
        }
        if(count==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}