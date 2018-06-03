#include<iostream>
#include<fstream>
using namespace std;

#define maxv 15
double x[maxv],y[maxv];
int k,n;

void init(){
    fstream fin("test.txt");
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>x[i];
    }
    for(int i=0;i<n;i++){
        fin>>y[i];
    }
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>x[i];
    // }
    // for(int i=0;i<n;i++){
    //     cin>>y[i];
    // }
}

double laInsert(double X0){
    double Y=0.0;
    k=0;
    while(k!=n){
        double t = 1.0;
        for(int i = 0;i<n;i++){
            if(i==k)
                continue;
            t *= (X0 - x[i])/(x[k] - x[i]);
            //cout<<"t:"<<t<<endl;
        }
        Y += t*y[k];
        k++;
        //cout<<"Y:"<<Y<<endl;
    }
    return Y;
}

int main(){
    init();
    double X0 = 1.1300;
    //cin>>X0;
    double res = laInsert(X0);
    cout<<res<<endl;
}