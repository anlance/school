#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int maxn = 10001;
struct number{
    int prime;
    int step;
};
bool vis[maxn];
number num[maxn];
int a, b;

bool judge(int digit){
    if(digit==2||digit==3){
        return true;
    }
    else if(digit<=1||digit%2==0){
        return false;
    }
    else if(digit>3){
        for (int i = 3; i * i < digit;i+=2){
            if(digit%2==0){
                return false;
            }
        }
        return true;
    }
}

void doit(){
    int i;
    int head = 0;
    int tail = 0;
    num[head].prime = a;
    num[tail++].step = 0;
    vis[a] = true;

    while(head<tail){
        number x=num[head++];  
        if(x.prime==b)  
        {  
            cout<<x.step<<endl;  
            return;  
        }  
  
        int unit=x.prime%10;       //获取x的个位  
        int deca=(x.prime/10)%10;  //获取x的十位  
  
        for(i=1;i<=9;i+=2)     //枚举x的个位，保证四位数为奇数（偶数必不是素数）  
        {  
            int y=(x.prime/10)*10+i;  
            if(y!=x.prime && !vis[y] && judge(y))  
            {  
                vis[y]=true;  
                num[tail].prime=y;  
                num[tail++].step=x.step+1;  
            }  
        }  
        for(i=0;i<=9;i++)     //枚举x的十位  
        {  
            int y=(x.prime/100)*100+i*10+unit;  
            if(y!=x.prime && !vis[y] && judge(y))  
            {  
                vis[y]=true;  
                num[tail].prime=y;  
                num[tail++].step=x.step+1;  
            }  
        }  
        for(i=0;i<=9;i++)     //枚举x的百位  
        {  
            int y=(x.prime/1000)*1000+i*100+deca*10+unit;  
            if(y!=x.prime && !vis[y] && judge(y))  
            {  
                vis[y]=true;  
                num[tail].prime=y;  
                num[tail++].step=x.step+1;  
            }  
        }  
        for(i=1;i<=9;i++)     //枚举x的千位,保证四位数，千位最少为1  
        {  
            int y=x.prime%1000+i*1000;  
            if(y!=x.prime && !vis[y] && judge(y))  
            {  
                vis[y]=true;  
                num[tail].prime=y;  
                num[tail++].step=x.step+1;  
            }  
        }  
    }
    cout << "Impossible" << endl;
    return;
}

int main()  
{  
    int test;  
    cin>>test;  
    while(test--)  
    {  
        cin>>a>>b;  
        memset(vis,false,sizeof(vis));  
        doit();  
    }  
    return 0;  
}  
