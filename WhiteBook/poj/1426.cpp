#include<iostream>  
using namespace std;  
  
int mod[524286];  //保存每次mod n的余数  
                  //由于198的余数序列是最长的  
                  //经过反复二分验证，436905是能存储198余数序列的最少空间  
                  //但POJ肯定又越界测试了...524286是AC的最低下限，不然铁定RE  
  
int main()  
{  
    int n,i;
    while(cin>>n)  
    {  
        if(!n)  
            break;  
  
        mod[1]=1%n;  //初始化，n倍数的最高位必是1  
  
        for(i=2;mod[i-1]!=0;i++)  //利用同余模定理，从前一步的余数mod[i/2]得到下一步的余数mod[i]  
            mod[i]=(mod[i/2]*10+i%2)%n;  
                     //mod[i/2]*10+i%2模拟了BFS的双入口搜索  
                     //当i为偶数时，+0，即取当前位数字为0  。为奇数时，则+1,即取当前位数字为1  
  
        i--;  
        int pm=0;  
        while(i)  
        {  
            mod[pm++]=i%2;   //把*10操作转化为%2操作，逆向求倍数的每一位数字  
            i/=2;  
        }  
        while(pm)  
            cout<<mod[--pm];  //倒序输出  
        cout<<endl;  
    }  
    return 0;  
}  