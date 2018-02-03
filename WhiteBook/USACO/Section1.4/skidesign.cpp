/*
ID: anlandu1
TASK: crypt1
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f

int main{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    int N;
    int ans = INF;
    const int MAXH = 100;
    long long hill[MAXH];
    fin >> N;
    memset(hill, 0, sizeof(hill));
    for (int i = 0; i < N;i++){
        int hight;
        fin >> hight;
        hill[hight]++;
    }
    for (int i = 0; i <=83;i++){
        int mass = 0;
        for (int j = 0; j < i;j++){
            mass += hill[j] * pow2(i-j);
        }
        if(mass==0&&hill[i]==0)
            continue;
        int shorten = 0;
        for (int j = i + 17 + 1; j <= 100;j++){
            shorten += hill[j] * pow2(j - i - 17);
        }
        ans = min(ans, mass + shorten);
    }
    fout << ans << endl;
    return 0;
}