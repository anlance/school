#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double fun(double a, double b){
	double c = pow(a+1,b);
	if(a==c)
		return a;
	return fun(c,b);
}

int main(){
	double a = 1.5;
	double b = 1.0/3.0;
	double res = fun(a,b);
	cout<<res<<endl;
	//cin>>a>>b;
	//cout<<res<<endl;
	return 0;
}