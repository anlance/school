//-------1-------//
#include<iosteam>
using namespace std;

const int INF = 0x3f3f3f;
const int MAX_V = 100;
const int MAX_E = 100;
sturct edge{
    int from;
    int to;
    int cost;
};
edge ee[MAX_E];
int d[MAX_V];   //最短距离
int num_v, num_e;

bool Bellman(int s){
    memset(d, INF, sizeof(d));
    d[s] = 0;
    int count = 0;  
    while(true){
        bool update = false;
        for (int i = 0; i < num_e;i++){
            edge et = ee[i];
            if(d[et.from]!=INF&&d[et.to]>d[et.from]+et.cost){
                d[et.to] = d[et.from] + et.cost;
                update = true;
            }
        }
        count++;
        if(!update)
            break;
        if(count==num_v)
            return false;   //负圈
    }
}

///---------------2------------//
bool Bellman2(int s){
    memset(d, INF, sizeof(d));
    d[s] = 0;
    int count = 0;
    while(true){
        bool update = false;
        for (int i = 0; i < num_e;i++){
            edge et = ee[i];
            if(d[et.from]!=INF&&d[et.to]>d[et.from]+et.cost){
                d[et.to] = d[et.from] + et.cost;
                update = true;
            }
        }
        count++;
        if(!upate)
            break;
        if(count==num_v)
            return false;
    }
}

//git 出现了一个错  看一下解决没
//再来