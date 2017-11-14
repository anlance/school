/*
ID: anlandu1
TASK: palsquare
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int N;
char pp[36] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int main(){
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    while(fin>>N){
        for (int i = 1; i < 300 + 1;i++){
            int tem = i;
            int temp = i*i;
            int count = 0;
            string pa="", ps="";
            //i
            if(tem/N!=0){
                while(tem/N!=0){
                    ps += pp[tem % N];
                    tem = tem / N;
                }
            }
            ps += pp[tem % N];
            //i*i
            if(temp/N!=0){  //temp转换成N进制
                while(temp/N!=0){
                    pa += pp[temp % N];
                    temp = temp / N;
                }
            }
            pa += pp[temp % N];
            reverse(ps.begin(), ps.end());  //字符串的反转
            reverse(pa.begin(), pa.end());
            //fout << ps << " " << pa << endl;
            //judge
            int xlength = pa.length()-1;
            if(xlength+1==1){
                fout << ps << " " << pa << endl;
            }else{
                for (int j = 0; j < pa.length()/2;j++,xlength--){
                    if(pa[j]==pa[xlength]){
                        count++;
                    }else{
                        break;
                    }
                }
                if(count==pa.length()/2){
                    fout << ps << " " << pa << endl;
                }
            }
        }
    }
    return 0;
}