/*
ID: anlandu1
TASK: skidesign
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f


int main(){
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    int N;
    const int MAXH = 1005;
    int hill[MAXH];
    fin >> N;
    for (int i = 0; i < N;i++)
        fin >> hill[i];
    //sort(hill, hill + N);
    long minCost = INF;
    for (int i = 0; i < 100; i++){
        long sum = 0;
        for (int j = 0; j < N;j++){
            if(hill[j]<i){
                int temp = i - hill[j];
                sum += temp * temp;
                if(sum>=minCost){
                    break;
                }
            }else if(hill[j]>(i+17)){
                int temp = hill[j] - (i + 17);
                sum += temp * temp;
                if(sum>=minCost){
                    break;
                }
            }
        }
        if (sum < minCost)
            minCost = sum;
    }
    fout << minCost << endl;
    return 0;
}