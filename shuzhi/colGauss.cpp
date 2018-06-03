#include<iostream>
#include<fstream>
#include<cmath>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define maxv 8
double a[maxv][maxv];
int n, judge;

/*列选主元的Gauss消元法*/

//完成矩阵的初始化
void init(){
    // ifstream fin("test.txt");
    // fin >> n;
    // for (int i = 0; i < n;i++){
    //     for (int j = 0; j < n+1;j++){
    //         fin >> a[i][j];
    //     }
    // }
    n = 4;
    srand((int)time(0));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n+1;j++){
            a[i][j] = rand() % 30 -10;
        }
    }
}

int select(int index){
    double d = a[index][index];
    int l = index;
    for (int i = index; i < n ;i++){
        if(abs(a[i][index])>abs(d)){
            d = a[i][index];
            l = i;
        }
    }
    if(d==0){
        return -1;
    }
    if(l==index){
        return 0;
    }
    else{
        double temp = 0.0;
        for (int j = 0; j < n + 1;j++){
            temp = a[index][j];
            a[index][j] = a[l][j];
            a[l][j] = temp;
        }
        return 1;
    }
}

void gauss(){
    //消元
    int k = 0;
    int i = 0;
    while(k!=n-1){
        judge = select(k);
        if(judge==-1){
            return;
        }
        for (i = k + 1; i < n;i++){
            a[i][k] = a[i][k] / a[k][k];
            for (int j = k + 1; j < n+1;j++){
                a[i][j] = a[i][j] - a[i][k] * a[k][j];
            }
        }
        k++;
    }

    // for (i = 0; i < n;i++){
    //     for (int j = 0; j < n + 1;j++){
    //         cout << a[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    // cout << "---" << endl;
}

void back(){
    //回代
    a[n - 1][n] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2; i > -1;i--){
        double temp = 0.0;
        for (int j = i + 1; j < n;j++){
            temp += a[i][j] * a[j][n];
        }
        a[i][n] = (a[i][n] - temp) / a[i][i];
    }
}

int main(){
    init();
    gauss();
    if(judge==0){
        cout << "矩阵奇异" << endl;
        return 0;
    }
    back();
    for (int i = 0; i < n;i++){
        cout << a[i][n] << "  ";
        cout << endl;
    }
    return 0;
}