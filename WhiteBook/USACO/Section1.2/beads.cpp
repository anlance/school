/*
ID: anlandu1
TASK: beads
LANG: C++11                 
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int n, count = 0;   //n 珠子数目   
    int repeat = 0;     //重复使用的w数
    int flat = 0;       //遇到另一种不是白色的珠子时的下标
    int inWhile = 0;    //在while里循环的次数
    int a[700];         
    string beads;
    fin >> n >> beads;
    beads += beads;
    fill(a, a + 2*n, 1);
    for (int i = 1; i < 2 * n-1; i++)
    {
        if(beads[i]==beads[flat]||beads[i]=='w'){
            a[count]++;
        }else{
            repeat = 0;
            flat = i;
            count++;
            int temp = i;
            while(temp>0&&beads[temp-1]=='w'){
                temp--;
                inWhile++;
                repeat++;
                a[count]++;
            }
            a[count] -= repeat; //减去首尾的w数
        }
    }
    for (int i = 0; i < 2 * n - 1;i++){
        a[i] = a[i] + a[i + 1];
    }
    int max = 0;
    for (int i = 0; i < 2 * n - 1;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    if(inWhile>=2){ //循环大于2次，表示相近的两段一定重复多减
        max += 1;
    }
    if(max>n){
        max = n;
    }
    fout << max << endl;
    return 0;
}