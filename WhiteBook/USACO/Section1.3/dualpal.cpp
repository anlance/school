/*
ID: anlandu1
TASK: dualpal
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int N, S;
char pp[10] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main(){
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    while(fin>>N){
        fin >> S;
        int count = 0, cc = 0;
        for (int i = S + 1; cc < N;i++){
            int temp = i;
            int jud = 0;
            bool judge = false;
            string pa="";
            for (int j = 2; j < 11;j++){
                temp=i;
                pa="";
                count = 0;
                if(temp/j!=0){  //temp转换成j进制
                    while(temp/j!=0){
                        pa += pp[temp % j];
                        temp = temp / j;
                    }
                }
                pa += pp[temp % j];
                reverse(pa.begin(), pa.end());  //字符串的反转
                int xlength = pa.length()-1;
                if(xlength+1==1){
                    jud++;
                }else{
                    for (int k = 0; k < pa.length()/2;k++,xlength--){
                        if(pa[k]==pa[xlength]){
                            count++;
                        }else{
                            break;
                        }
                    }
                    if(count==pa.length()/2){
                        jud++;
                    }
                }
                if(jud>1){
                    fout  << i <<endl;
                    cc++;
                    break;
                }
            }
        }
    }
    return 0;
}