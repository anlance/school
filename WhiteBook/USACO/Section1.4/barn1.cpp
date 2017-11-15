/*
ID: anlandu1
TASK: barn1
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int M, S, C;
struct barn{
    int number;
    int distance;
};
bool cmp(barn a,barn b){
    return a.distance > b.distance;
}
bool cmp2(barn a,barn b){
    return a.number < b.number;
}
barn cow[201];
barn cowHelp[201];

int main(){
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    while(fin>>M){
        fin >> S >> C;
        for (int i = 0; i < C;i++){
            fin >> cow[i].number;
            cowHelp[i].number = cow[i].number;
        }
        if(M>=C){//这个判断很精髓
            fout << C << endl;
        }else{
              sort(cow, cow + C, cmp2);//我以为给的就是排好序的，结果还要自己动手
        for (int i = 0; i < C;i++){
            cowHelp[i].number = cow[i].number;
        }
        for (int i = 0; i < C-1;i++){
            cow[i].distance = cow[i + 1].number - cow[i].number;
            cowHelp[i].distance = cow[i].distance;
        }
        sort(cowHelp,cowHelp+C,cmp);
        sort(cowHelp, cowHelp + M-1, cmp2);
        int num = 0, start, end;
        start = cow[0].number;
        int temp = 0;
        for (int i = 0; i < M-1;i++){
            for (int j = temp; j < C;j++){
                if(cow[j].number==cowHelp[i].number){
                    end = cow[j].number;
                    num += (end - start + 1);
                    //fout << start << " " << end << ".." << endl;
                    //fout << num <<"---"<< endl;
                    temp = j + 1;
                    start = cow[temp].number;
                    break;
                }
            }
        }
        end = cow[C - 1].number;
        num += (end - start + 1);
        fout << num << endl;
        }
    }
    return 0;
}