/*
ID: anlandu1
TASK: namenum
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int num[26] = {
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 0, 7, 7,
    8, 8, 8,
    9, 9, 9, 0};

int main(){
    ofstream fout("namenum.out");
    ifstream fin("namenum.in");
    ifstream tin("dict.txt");
    string N;
    while(fin>>N){
        int a = N.length();
        string name;
        int flag = 0;
        bool flags = false;
        while(tin>>name){
            int b = name.length();
            flag = 0;
            if(a==b){
                //fout << name << "..";
                for (int i = 0; i < b;i++){
                    //fout << N[i] << ".." << ".." << num[(int)name[i] - 65] << "//";
                    if((num[(int)name[i] - 65]+48)!=N[i]){
                        break;
                    }
                    flag++;
                }
                //fout << endl;
            }
            if(flag==b){
                flags = true;
                fout << name << endl;
            }
        }
        if(flags==false){
            fout << "NONE" << endl;
        }
    }
    return 0;
}