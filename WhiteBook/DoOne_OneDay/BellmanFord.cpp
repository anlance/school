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
        if(!update)
            break;
        if(count==num_v)
            return false;
    }
}

//git 出现了一个错  看一下解决没
//再来

//---------3--------//
bool Bellamn3(int s){
    memset(d, INF, sizeof(d));
    d[s] = 0;
    int count = 0;
    while(true){
        bool upadte = false;
        for (int i = 0; i < num_e;i++){
            edge et = ee[i];
            if(d[et.from]!=INF&&d[et.to]>d[et.from]+et.cost){
                et.to = d[et.from] + et.cost;
                update = true;
            }
        }
        count++;
        if(!update)
            break;
        if(vount==num_v)
            return false;
    }
}

//------4------//
bool Bellman4(int s){
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
        if(!upadte)
            break;
        if(count==num_v)
            return false;
    }
    return true;
}

//-----5--------//

bool Bellman5(int s){
    memset(d, INf, sizeof(d));
    d[s] = 0;
    int count = 0;
    while(true){
        bool update = false;
        for (int i = 0; i < num_e;i++){
            edge et = ee[i];
            if(d[et.from]!=INf&&d[et.to]>d[et.from]+et.cost){
                d[et.to] = d[et.from] + et.cost;
                update = true;
            }
        }
        count++;    //可以把update与count结合成一个东西,但效果并不那么好
        if(!update)
            break;
        if(count==num_v)
            return false;
    }
    return true;
}