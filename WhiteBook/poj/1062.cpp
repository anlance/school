// #include<iostream>
// #include<queue>
// #include<cstring>
// using namespace std;

// #define INF 0x3f3f3f
// #define maxv 105
// int power[maxv];
// int map[maxv][maxv];
// int d[maxv];        
// bool used[maxv];
// int N, M;
// int minPower;
// struct Node{
//     int from;
//     int to;
//     int min_power;
// };

// bool check(int a,int b){
//     if(power[a]>power[b]){
//         if(power[a]-power[b]>N)
//             return false;
//         else{
//             if(minPower==power[a]){
//                 minPower = power[b];
//                 return true;
//             }
//             else{
//                 if(power[a]-minPower>N)
//                     return false;
//                 else{
//                     if(minPower>power[b]){
//                         minPower = power[b];
//                     }
//                     return true;
//                 }
//             }
//         }
//     }
//     else{
//         if(power[b]-power[a]>N){
//             return false;
//         }
//         else{
//             if(power[b]==minPower){
//                 minPower = power[a];
//                 return true;
//             }
//             else{
//                 if(power[b]-minPower>N)
//                     return false;
//                 else{
//                     if(minPower>power[a]){
//                         minPower = power[a];
//                     }
//                     return true;
//                 }
//             }
//         }
//     }
// }

// int dijkstra(){
//     memset(d, INF, sizeof(d));
//     memset(used, false, sizeof(used));
//     d[1] = map[1][1];
//     minPower = power[1];

//     while(true){
//         int v = -1;
//         for (int i = 1; i < M+1;i++){
//             if(!used[i]&&(v==-1||d[i]<d[v]))
//                 v = i;
//         }
//         if(v==-1)
//             break;
//         used[v] = true;
//         for (int i = 1; i < M + 1;i++){
//             minPower = power[1];
//             if(check(i,v)){
//                 if(!used[i]&&d[i]>d[v]+map[v][i]){
//                     d[i] = d[v]+map[v][i];
//                 }
//             }
//         }
//     }
//     int min = INF;
//     for (int i = 1; i < M + 1;i++){
//         d[i] += map[i][i];
//         d[i] -= map[1][1];
//         if(min>d[i]){
//             min = d[i];
//         }
//     }
//     return min;
// }

// int main(){
//     while(cin>>N>>M){
//         int x = 0;
//         int T, V;
//         for(int i=1;i<M+1;i++){
//             for (int j = 1; j < M + 1;j++){
//                 map[i][j] = INF;
//             }
//         }
//         for (int i = 1; i < M + 1; i++){
//             cin >> map[i][i] >> power[i] >> x;
//             for (int j = 0; j < x;j++){
//                 cin >> T >> V;
//                 map[i][T] = V;
//             }
//         }
//         int result = doit();
//         cout << result << endl;
//         for (int i = 1; i < M + 1;i++){
//             cout << d[i] << "--";
//         }
//     }
// }

/*
解决不了等级问题
*/

#include<iostream>
#include<cstring>     
using namespace std;   
  
const int inf=0x7fffffff;   // 无限大    
    
int M,N;//M 为等级差，N 为物品数目     
int price[101][101];   // 物品 i 在有第 t 号替代品情况下的优惠价 pricr[t][i], 当 t=0 时说明 i 无替代品，此时为原价  
int lv[101];   // 第 i 号物品主人的等级 lv[i]  
int x[101];// 第 i 号物品的替代品总数 x[i]     
    
int dist[101];// 最初的源点 0 到任意点 i 的最初距离（权值），相当于每个物品的原价     
    
bool vist[101];   // 记录点 i 是否已被访问  
   
/*Initial and Input*/    
  
void data_init()     
{     
    memset(price,0,sizeof(price));     
    memset(lv,0,sizeof(lv));     
    memset(dist,inf,sizeof(dist));     
    memset(vist,false,sizeof(vist));    
      
    cin>>M>>N;     
    for(int i=1;i<=N;i++)     
    {     
        cin>>price[0][i]>>lv[i]>>x[i];   //price[0][i] 物品 i 无替代品时的原价  
    
        for(int j=1;j<=x[i];j++)     
        {     
            int t,u;   //t 替代品编号，u 优惠价 (临时变量)  
            cin>>t>>u;  
            price[t][i]=u;   // 物品 i 在有第 t 号替代品情况下的优惠价，即点 t 到点 i 的权值  
        }     
    }     
}     
    
  
int dijkstra()     
{     
         
    int node;// 记录与当前源点距离最短的点     
    int sd;// 最短距离     
    int i,j;  
    
    for(i=1;i<=N;i++)     
        dist[i]=price[0][i];  // 假设最初的源点就是 0 点，初始化最初源点到各点的权值 dist[i]  
  
    for(i=1;i<=N;i++)   // 由于 1 点是目标点，因此最坏的打算是进行 n 次寻找源点到其他点的最短路，并合并这两点（不再访问相当于合并了）  
    {     
        node=0;     
        sd=inf;     
        for(j=1;j<=N;j++)     
        {     
            if(!vist[j] && sd>dist[j])   // 在未访问的点中，寻找最短的一条  
            {     
                sd=dist[j];     
                node=j;   // 记录该点  
            }     
        }     
        if(node==0)   // 若 node 没有变化，说明所有点都被访问，最短路寻找完毕  
            break;     
             
        vist[node]=true;   // 记录 node 点已被访问  
        for(j=1;j<=N;j++)     
        {     
            if(!vist[j] && price[node][j] > 0 && dist[j] > dist[node] + price[node][j])   // 把未访问但与 node（新源点）连通的点进行松弛  
                dist[j]=dist[node]+price[node][j];     
        }     
    }     
    return dist[1];   // 返回当前次交易后目标点 1 在等级 lv[i] 约束下的最短距离  
}     
    
int main()     
{  
    data_init();   // 初始化并输入数据  
     
    int temp_price;    // 当前次交易后目标点 1 在等级 lv[i] 约束下的最少价格  
    int maxlv;       // 最大等级 (酉长的等级不一定是最大的)  
    int minprice=inf;    // 最低价格 (初始化为无限大)  
     
    for(int i=1;i<=N;i++)     
    {     
        /* 在等级限制下，寻找允许被当前点访问的点 */  
             
        maxlv=lv[i];   // 把当前物品的等级暂时看做最高等级  
        for(int j=1;j<=N;j++)   // 遍历其他各点  
        {     
            if(lv[j]>maxlv || maxlv-lv[j]>M)   // 当其它物品 j 的等级比当前物品高 (保证单向性)，或者两者等级之差超出限制 M 时  
                vist[j]=true;    // 物品 j 则强制定义为 “已访问” 状态，不参与后续操作  
            else    
                vist[j]=false;   // 否则物品 j 定义为 “未访问” 状态，参与后续操作  
        }     
  
        temp_price=dijkstra();   // 记录当前次交易后目标点 1 在等级 lv[i] 约束下的最短距离 (最少价格)  
  
        if(minprice>temp_price)   // 寻找各次交易后的最少价格，最终确认最少价格  
            minprice=temp_price;     
    }     
    cout<<minprice<<endl;     
    
    return 0;     
}    