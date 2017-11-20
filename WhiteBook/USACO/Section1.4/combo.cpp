/*
ID: anlandu1
TASK: combo
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    int N;
    while(fin>>N){
        vector<int> combo1(3);
        vector<int> combo2(3);
        for (int i = 0; i < 3;i++){
            fin >> combo1[i];
        }
        for (int i = 0; i < 3;i++){
            fin >> combo2[i];
        }
        set<vector<int> > comboSet;
        vector<int> v1(3);
        vector<int> v2(3);
        for (int i = -2; i < 3;i++){
            for (int j = -2; j < 3;j++){
                for (int k = -2; k < 3;k++){
                    v1[0] = (i + combo1[0] + N) % N;
                    v1[1] = (j + combo1[1] + N) % N;
                    v1[2] = (k + combo1[2] + N) % N;
                    comboSet.insert(v1);
                    v2[0] = (i + combo2[0] + N) % N;
                    v2[1] = (j + combo2[1] + N) % N;
                    v2[2] = (k + combo2[2] + N) % N;
                    comboSet.insert(v2);
                }
            }
        }
        fout << comboSet.size() << endl;
    }
    return 0;
}