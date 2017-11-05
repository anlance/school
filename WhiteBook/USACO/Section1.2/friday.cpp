/*
ID: anlandu1
TASK: friday
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

bool isLeap(int y){
    if(y%4==0&&(y%100!=0||y%400==0))
        return true;
    else
        return false;
}
int month[12][2] = {
{31, 31},{28, 29},{31, 31},{30, 30},
{31, 31},{30, 30},{31, 31},{31, 31},
{30, 30},{31, 31},{30, 30},{31, 31}}; 

int main(){
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int week[7];
    int n;
    int days = 0;
    fin >> n;
    fill(week, week + 7, 0);
    for (int i = 0; i < n;i++){
        int t = isLeap(1900 + i);
        for (int j = 0; j < 12;j++){
            week[(days + 12) % 7]++;
            days += (month[j][t]%7);
        }
    }
    for (int i = 0; i < 6;i++){
        fout << week[(i+5)%7] << " ";
    }
    fout << week[4] << endl;
    return 0;
}