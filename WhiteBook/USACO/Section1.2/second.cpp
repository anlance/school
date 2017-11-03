/*
ID: anlandu1
PROB: ride
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    char a[6], b[6];
    int aa[6], bb[6];
    int ma = 1, mb = 1;
    fin >> a >> b;
    for (int i = 0; i < 6;i++){
        aa[i] = (int)a[i] - 64;
        bb[i] = (int)b[i] - 64;
    }
    for (int i = 0; i < 6;i++){
        if(aa[i]<1)
            aa[i] = 1;
        ma = (ma * aa[i]) % 47;
        if(bb[i]<1)
            bb[i] = 1;
        mb = (mb * bb[i]) % 47;
    }
    if(ma==mb){
        fout << "GO" << endl;
    }
    else
        fout << "STAY" << endl;
    return 0;
}