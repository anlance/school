#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

/*
ID: anlandu1
TASK: ariprog
LANG: C++11                 
*/

/*题读不懂*/

int a[250*250*2+10];
struct node{
       int start;
       int end;
       };
bool cmp (const node & c,const node & d){
     if(c.end!=d.end)
         return c.end<d.end;
     else
         return c.start<d.start;
}
bool istrue(int v,int temp){
     if(a[v]==1){
                  return true;
                  }
     return false;
}
int main(){
    FILE *fin = fopen("ariprog.in", "r");
    FILE *fout = fopen("ariprog.out", "w");
   // ofstream fout ("ariprog.out");
   // ifstream fin ("ariprog.in");
    int n,m;
    memset(a,0,sizeof(a));
    fscanf(fin,"%d%d",&n,&m);
    //   cin>>n>>m;
       int times=0;
       node res[10005];
       int sum=0;
      // int a[250*250];
       for(int i=0;i<=m;i++){
               for(int j=i;j<=m;j++){
                       a[i*i+j*j]=1;
                     // a[times++]=i*i+j*j;
              //        cout<<a[times-1]<<endl;
                      }
                      }
       for(int k=0;(k+n-1)<=m*m*2;k++){
               if(!istrue(k,times))
                    continue;
               for(int g=1;;g++){
                       if((k+g*(n-1))>m*m*2)
                            break;
                       int j;
                       for(j=0;j<n;j++){
                               int temp=k+g*j;
                               if(!istrue(temp,times))
                                   break;
                                   }
                       if(j>=n){
                           res[sum].start=k;
                           res[sum].end=g;
                           sum++;
                           }
                           }
                           }
       if(sum==0){
          fprintf(fout,"NONE\n");
        // cout<<"NONE"<<endl;
        //  continue;
          }
       else{
          sort(res,res+sum,cmp);
          for(int k=0;k<sum;k++){
                 // cout<<res[k].start<<" "<<res[k].end<<endl;
                                   fprintf(fout,"%d %d\n",res[k].start,res[k].end);
          }
          }
      cin>>n;
    return 0;
}