#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


double e = 1e-6;
int i = 0;

double fun(double a, double b){
	double c = pow(a+1,b);
	cout << "第"<<i<<"次迭代："<<a<<setiosflags(ios::fixed)<<setprecision(6)<< endl;
	i++;
	if(abs(a-c)<e)
		return a;
	return fun(c,b);
}

int main(){
	double a = 1.5;
	double b = 1.0/3.0;
	double res = fun(a,b);
	//cout<<res<<endl;
	//cin>>a>>b;
	//cout<<res<<endl;
	return 0;
}