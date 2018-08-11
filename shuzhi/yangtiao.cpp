
#include<stdio.h>
#include<math.h>
int Rk=0;
int Tk=0;
double fx(double x)     //被积函数fx=sin(x)/x;
{
    if(x==0.0)return 1.0;
    return sin(x)/x;
}
double getS(double a,double b,double h)
{
    double res=0.0;
    for(double i=a+h/2.0; i<b; i+=h)
        res+=fx(i);
    return res;
}
double Romberg(double a,double b,double e)
{
    int k=1;
    double T1,T2,S1,S2,C1,C2,R1,R2;
    double h=b-a;
    double s;
    T1=(fx(a)+fx(b))*h/2.0;
    int counter=0;
    while(1)
    {
        Rk++;
        counter++;
        s=getS(a,b,h);
        T2=(T1+h*s)/2.0;
        S2=(4.0*T2-T1)/3.0;
        h/=2.0;
        T1=T2;
        S1=S2;
        C1=C2;
        R1=R2;
        if(k==1)
        {
            k++;
            continue;
        }
        C2=(16.0*S2-S1)/15.0;
        if(k==2)
        {
            k++;
            continue;
        }
        R2=(64.0*C2-C1)/63.0;
        if(k==3)
        {
            k++;
            continue;
        }
        if(fabs(R1-R2)<e||counter>=100)break;
    }
    return R2;
}

int main()
{
    double a,b,e;
    printf("Input a b e:");
    //输入区间[a,b],和精度e
    scanf("%lf%lf%lf",&a,&b,&e);
    double t=Romberg(a,b,e);
    //输出龙贝格算法计算结果和相应二分次数
    printf("\nRomberg:%.7lf  --  %d\n",t,Rk);
    return 0;
}
