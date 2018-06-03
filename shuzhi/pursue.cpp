#include<iostream>
#include<fstream>
using namespace std;

#define maxv 10
double a[maxv],b[maxv],c[maxv],l[maxv],u[maxv],f[maxv],y[maxv],x[maxv];
int n;

void init(){
    fstream fin("test2.txt");
    fin>>n;
    for(int i = 0;i<n;i++){
        fin>>b[i];
        if(i!=n-1){
            fin>>c[i];
        }
        fin>>f[i];
        if(i!=n-1){
            fin>>a[i];
        }
    }
}

void pursue(){
    //alu分解
    l[0] = b[0];
    for(int i = 0;i<n-1;i++){
        u[i] = c[i] / l[i];
        l[i + 1] = b[i + 1] - a[i] * u[i];
    }
    //追
    y[0]= f[0]/l[0];
    for(int i=1;i<n;i++){
        y[i] = (f[i]-a[i-1]*y[i-1])/l[i];
    }
    //赶
    x[n-1] = y[n-1];
    for(int i=n-2;i>-1;i--){
        x[i]=y[i]-u[i]*x[i+1];
    }
}

int main(){
    init();
    pursue();
    for(int i = 0;i<n;i++){
        cout<<y[i]<<" "<<x[i]<<endl;
    }
    return 0;
}