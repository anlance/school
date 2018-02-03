#include<iostream>  
using namespace std;  
  
int CycleNum(int i)  
{  
    int count=1;  
    while(i!=1)  
    {  
        if(i%2)  
            i=3*i+1;  
        else  
            i/=2;  
        count++;  
    }  
    return count;  
}  
  
int main(void)  
{  
    int a,b;  
    while(cin>>a>>b)  
    {  
        int x=a<b?a:b;  
        int y=a>b?a:b;  
        int MaxCycle=0;  
        for(int i=x;i<=y;i++)  
        {  
            int temp=CycleNum(i);  
            if(MaxCycle<temp)  
                MaxCycle=temp;  
        }  
        cout<<a<<' '<<b<<' '<<MaxCycle<<endl;  
    }  
    return 0;  
}  