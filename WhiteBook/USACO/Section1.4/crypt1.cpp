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

int N;
int a[10];  //原始数字
int reult[1000];  //存放可能的乘积结果值(3位);1*9##  2*5## 3*3## 4*2## (5|6|7|8|9)1##； 

int main(){
    ifstream fin("crypt1.in");
    ofstream fou("crypt1.out");
    while(fin>>N){
        for (int i = 0; i < N;i++){
            fin >> a[i];
        }
    }
}