#include<iostream>
#include<fstream>
using namespace std;

//多项式拟合

int N;
#define maxv 10
double X[maxv], Y[maxv];
double map[maxv][maxv];

void init(int n){
    fstream fin("test3.txt");
    fin>>n;
    for(int i = 0;i<n;i++){
        fin >> X[i];
    }
    for (int i = 0; i < n;i++){
        fin >> Y[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            
        }
    }
}