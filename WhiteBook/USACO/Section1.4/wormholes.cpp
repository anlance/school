/*
ID: anlandu1
TASK: wormhole
LANG: C++11                 
*/


#include <iostream>  
#include <cstdio>  
#include <map>  
#include <vector>  
#include <string>  
#include <stack>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
const int maxn=15;  
struct Node  
{  
    int x,y,num;  
    Node(int _x,int _y,int _num):x(_x),y(_y),num(_num) {}  
};  
  
int n;  
pair<int,int>  newpoints[maxn];  
vector<vector<Node> > plist;  
int match[maxn];  
bool vis[maxn];  
int N;  
int ans;  
pair<int,int> points[maxn];  
  
bool isCircle(int x,int y)  
{  
    while(x<plist[y].size())  
    {  
        if(vis[plist[y][x].num])  
            return true;  
        vis[plist[y][x].num]=true;  
        pair<int,int> p=newpoints[match[plist[y][x].num]];  
        x=p.first+1;  
        y=p.second;  
    }  
    return false;  
}  
bool judge()  
{  
    for(int i=1; i<=n; ++i)  
    {  
        memset(vis,0,sizeof(vis));  
        pair<int,int> p=newpoints[i];  
        if(isCircle(p.first,p.second))  
            return true;  
    }  
    return false;  
}  
  
void dfs(int cur)  
{  
  
    if(cur==N)  
    {  
        if(judge())  
            ++ans;  
        return ;  
    }  
    else  
    {  
        for(int i=1; i<=n; ++i)if(!match[i])  
            {  
                for(int j=i+1; j<=n; ++j)if(!match[j])  
                    {  
                        match[i]=j;  
                        match[j]=i;  
                        dfs(cur+1);  
                        match[j]=0;  
                    }  
                match[i]=0;  
                break;  
            }  
    }  
}  
  
void init()  
{  
    map<int,vector<int> > sortList;  
    for(int i=1; i<=n; ++i)  
        sortList[points[i].second].push_back(points[i].first);  
    int id=0,y=0;  
    for(map<int,vector<int> >::iterator it=sortList.begin(); it!=sortList.end(); ++it)  
    {  
        vector<int> &vec=it->second;  
        sort(vec.begin(),vec.end());  
        vector<Node> nlist;  
        for(int i=0; i<vec.size(); ++i)  
        {  
            nlist.push_back(Node(i,y,++id));  
            newpoints[id]=make_pair(i,y);  
        }  
        ++y;  
        plist.push_back(nlist);  
    }  
}  
  

int main()  
{  
    freopen("wormhole.in","r",stdin);  
    freopen("wormhole.out","w",stdout);  
    scanf("%d",&n);  
    for(int i=1; i<=n; ++i)  
        scanf("%d%d",&points[i].first,&points[i].second);  
    init();  
    N=n/2;  
    dfs(0);  
    printf("%d\n",ans);  
    return 0;  
}