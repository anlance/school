/*
读不懂题是千万难过中相当难过的一种难过

题意：
半圆表示一块面积可扩展的区域，开始时，面积是0，在（0,0）处开始以每年50平方米的速度同样呈半圆扩展，
输入一个正整数N，然后输入N对坐标，对于每一对坐标值：求出面积扩展到该点的年数，坐标值单位为米。
*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

double x, y;
double s = 0.0;
double rr = 0.0;
int year = 0;
int doit(){
    int i = 0;
    cin >> x >> y;
    while(1){
        i++;
        s = 100.0 * i;
        rr = s / 3.14;
        if(rr>=(x*x+y*y)){
            return i;
        }
    }
}

int main(){
    int num;
    vector<int> years;
    while(cin>>num){
        for (int i = 0; i < num;i++){
            int year = doit();
            years.push_back(year);
        }
        for (int i = 0; i < num;i++)
            cout << "Property " << i + 1 << ": This property will begin eroding in year " << years.at(i) << "." << endl;
        cout << "END OF OUTPUT." << endl;
    }
}