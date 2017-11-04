/*
ID: anlandu1
PROB: gift1
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct person{
    int money;
    string name;
};

int main(){
    person a[10];
    string gName,rName; //给的人名，接受的人名；
    int gMoney, rMoney, pNumber;//分别是给出的钱，收到的钱，接收的人数
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int n;
    fin >> n;
    for (int i = 0; i < n;i++){
        fin >> a[i].name;
        a[i].money = 0;
    }
    while (fin >> gName){
        fin >> gMoney >> pNumber;
        if(pNumber==0)
            continue;
        else{
            rMoney = gMoney / pNumber;
            gMoney = rMoney * pNumber;
            for (int i = 0; i < n; i++)
            {
                if (gName == a[i].name)
                {
                    a[i].money = a[i].money - gMoney;
                }
            }
            for (int i = 0; i < pNumber; i++)
            {
                fin >> rName;
                for (int i = 0; i < n; i++)
                {
                    if (a[i].name == rName)
                    {
                        a[i].money = a[i].money + rMoney;
                    }
                }
            }
        }
    }        
    for (int i = 0; i < n; i++){
        fout << a[i].name << " " << a[i].money << "\n";
    }
    return 0;
}