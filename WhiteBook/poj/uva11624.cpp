#include <iostream>  
#include <stdio.h>  
#include <queue>  
#include <string.h>  
using namespace std;  
const int maxn=1010;  
int dx[4]= {0,1,-1,0};  
int dy[4]= {1,0,0,-1};  
char str[maxn][maxn];  
int c,r;  
int jx,jy,fx,fy;  
struct point  
{  
    int xx,yy,t;  
    bool isf;  
};  
queue<point>que;  
bool vis[maxn][maxn];  
int  bfs()  
{  
      while(!que.empty())  
      {  
          point now=que.front();  
          que.pop();  
          int nx,ny;  
          if(!now.isf)  
          {  
            if(now.xx==0||now.yy==0||now.xx==c-1||now.yy==r-1)  
            return now.t;  
          }    
         for(int i=0; i<4; i++)  
        {  
             nx=dx[i]+now.xx;  
             ny=dy[i]+now.yy;  
             if(nx>=0&&nx<c&&ny>=0&&ny<r&&!vis[nx][ny])  
             {  
                 vis[nx][ny]=true;  
                 point tmp;  
                 tmp.xx=nx;  
                 tmp.yy=ny;  
                 if(now.isf)  
                 tmp.t=now.t;  
                 else  
                tmp.t=now.t+1;  
                 tmp.isf=now.isf;  
                 que.push(tmp);  
             }  
        }  
      }  
    return -1;  
}  
int main()  
{  
    int t;  
    cin>>t;  
    while(t--)  
    {  
        scanf("%d%d",&c,&r);  
        while(!que.empty())  
            que.pop();  
        point h,F;  
        memset(vis,true,sizeof(vis));///状态  
        for(int i=0; i<c; i++)  
        {  
            scanf("%s",str[i]);  
            for(int j=0; j<r; j++)  
            {  
                if(str[i][j]=='.')  
                 vis[i][j]=false;  
                if(str[i][j]=='J')  
                {  
                    h.xx=i;  
                    h.yy=j;  
                    h.t=0;  
                    h.isf=false;  
                }  
                if(str[i][j]=='F')  
                {  
                    F.xx=i;  
                    F.yy=j;  
                    F.t=0;  
                    F.isf=true;  
                    que.push(F);///将所有火坐标加入队列  
                }  
            }  
        }  
      que.push(h);///最后加入人  
        
      int ans=bfs();  
      if(ans==-1)
          cout << "IMPOSSIBLE" << endl;
      else
          cout << ans + 1 << endl;
    }  
    return 0;  
}  