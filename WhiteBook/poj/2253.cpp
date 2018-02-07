#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

struct Node{
    double x;
    double y;
};
Node point[201];
int N;
double map[201][201];

double doit(){
    for (int i = 1; i < N;i++){
        for (int j = i + 1; j < N + 1;j++){
            double x = point[i].x - point[j].x;
            double y = point[i].y - point[j].y;
            map[i][j] = sqrt(x * x + y * y);
            map[j][i] = map[i][j];
        }
    }
    for (int k = 1; k < N + 1;k++){
        for (int i = 1; i < N; i++){
            for (int j = i + 1; j < N + 1;j++){
                if(map[i][k]<map[i][j] && map[k][j]<map[i][j])   
                        if(map[i][k]<map[k][j])               
                            map[i][j]=map[j][i]=map[k][j];  
                        else  
                            map[i][j]=map[j][i]=map[i][k];
            }
        }
    }
    return map[1][2];
}

int main(){
    int number = 0;
    while(cin>>N){
        if(N==0){
            break;
        }
        number++;
        for (int i = 1; i < N + 1;i++){
            cin >> point[i].x >> point[i].y;
        }
        double result = doit();
        cout<<"Scenario #"<<number<<endl;  
        cout<<fixed<<setprecision(3)<<"Frog Distance = "<<result<<endl;
        cout<<endl;    
    }
    return 0;
}