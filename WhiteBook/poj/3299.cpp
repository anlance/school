#include<iostream>  
#include<cmath>  
#include<string>  
#include<iomanip>  
using namespace std;  
int main(void)  
{  
    char alpha;  
    double tem,dew,hum;  
    int i;  
    for(;;)  
    {  
        tem=dew=hum=200;    
        for(i=0;i<2;i++)  
        {  
            cin>>alpha;  
            if(alpha=='E')  
                return 0;  
            else if(alpha=='T')  
                cin>>tem;  
            else if(alpha=='D')  
                cin>>dew;  
            else if(alpha=='H')  
                cin>>hum;  
        }  
        if(hum==200)  
            hum=tem+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(dew+273.16)))-10);  
        else if(tem==200)  
            tem=hum-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(dew+273.16)))-10);  
        else if(dew==200)  
            dew=1/((1/273.16)-((log((((hum-tem)/0.5555)+10.0)/6.11))/5417.7530))-273.16;  
        cout<<setprecision(1)<<fixed<<"T "<<tem<<" D "<<dew<<" H "<<hum<<endl;  
    }  
    return 0;  
}  