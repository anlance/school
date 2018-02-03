#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;


int main(){
	char str[256];
    memset(str, '\0', sizeof(str));
    while(true){
        gets(str);
        int len = strlen(str);
        if (len<=0||str[0]=='#'){
            break;
        }
        int sum = 0;
        for (int i = 0; i < len;i++){
            if(str[i]==' '){
                continue;
            }
            else{
                sum += (i + 1) * (int)(str[i] - 'A' + 1);
            }
        }
        cout << sum << endl;
        memset(str, '\0', sizeof(str));
    }
    return 0;
} 