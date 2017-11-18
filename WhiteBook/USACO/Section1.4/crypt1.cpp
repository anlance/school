/*
ID: anlandu1
TASK: crypt1
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

//我的方法差太多了
//学习别人的

//int a[10];  //原始数字
//int reult[1000];  //存放可能的乘积结果值(3位);1*9##  2*5## 3*3## 4*2## (5|6|7|8|9)1##； 

int Hash[10];  
int Check (int x){
    while(x){
        if(!Hash[x%10])
            return 1;
        x = x / 10;
    }
    return 0;
}

int main(){
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out"); 
    int n;
    int t;
    while(fin>>n){
        int sum = 0; 
        for (int i = 0; i < n;i++){
            fin >> t;
            Hash[t] = 1;
        }
        for (int i = 100; i < 1000;i++){
            if(Check(i))
                continue;
            for (int j = 10; j < 100;j++){
                int m = i * j;
                if(m>9999)
                    break;
                if(Check(j)||Check(m))
                    continue;
                int fm = (j%10)*i;  
                if(fm<100||fm>=1000)  
                    continue;
                int sm = (j/10)*i;  
                if(sm<100||sm>=1000)  
                    continue;
                if(Check(sm)||Check(fm))  
                    continue;  
                //if ( m == sm*10+fm )  
                    sum++;       
            }
        }
        fout<<sum<<endl;  
    }
    return 0;
}