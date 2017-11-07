/*
ID: anlandu1
TASK: milk2
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct cow{
    int start;
    int end;
};
bool cmp(cow a,cow b){
    return a.start < b.start;
}
int main(){
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int N;
    cow mm[5000];
    int min=0, max=0;
    int max_last = 0, max_empty = 0;//最长持续，最长间隔
    fin >> N;
    for (int i = 0; i < N;i++){
        fin >> mm[i].start >> mm[i].end;
    }
    sort(mm,mm+N,cmp);
    min = mm[0].start;
    max = mm[0].end;
    max_last = max - min;   //只有一组时
    for (int i = 1; i < N;i++){
        if(mm[i].start>max){//开始在上组结束后
            min = mm[i].start;
            if(max_empty<min-max){
                max_empty = min - max;
            }
            max = mm[i].end;
            if(max_last<max-min){
                max_last = max - min;
            }
        }else{//开始在上组结束前
            if(mm[i].end>max){//结束在上组结束后
                max = mm[i].end;
                if(max_last<max-min){
                    max_last = max - min;
                }
            }
        }
    }
    fout << max_last << " " << max_empty << endl;
    return 0;
}