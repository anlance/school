#ifndef GRAPH_H
#define GRAPH_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
/*图的矩阵表示，判断图的连通性，图遍历算法，求图的连通分支,计算任意两节点之间的距离*/
static int reach[10010] = { 0 };             //标记数组，用于深度优先算法（假设最多10000个节点）
extern int stn;                                //用于记录连通分支的数量
//异常类定义
class illegalParameterValue
{
private:
    string message;
public:
    illegalParameterValue() {
        message = "非法参数";
    }
    illegalParameterValue(string theMessage) {
        message = theMessage;
    }
    void outputMessage()const {
        cout << message << endl;
    }
};
//无向有权图
class adjacencyWGraph
{
private:
    string *vertex;                   //顶点集合
    int n;                            //顶点个数
    int e;                            //边的个数
    int **a;                          //邻接矩阵
    int maxLength = 2;                //输入的最长的字符串
public:
    //构造函数
    adjacencyWGraph(int numberOfV = 0);
    //析构函数
    ~adjacencyWGraph();
    //输入顶点集合
    void inputV(const string &s);
    void inputE(const int &e, const string &s);
    void inputFile(string path);
    int numberOfV()const { return n; }           //返回顶点个数
    int numberOfE()const { return e; }           //返回边数
    //判断(v1,v2)是不是图的一条边
    bool existsEdge(const string& v1, const string& v2)const;
    //插入一条边(v1,v2)
    void insertEdge(const string& v1, const string& v2, int w);
    //删除边(v1,v2)
    void eraseEdge(const string& v1, const string& v2);
    //初始化深度优先标记数组
    void initReach()const;
    //确认顶点的度
    int degree(const string& theVertex)const;
    //查找顶点索引
    int indexOfV(const string& theVertex)const;
    //输出节点集合
    void outputVertex(string &s)const;
    //边的形式输出图
    void outputGraph(string &s)const;
    //矩阵形式输出图
    void outputWithAdjacency(string &s)const;
    //广度优先搜索
    void bfs(const string &v, string &s)const;
    //深度优先搜索
    void dfs(int v, string &s)const;
    //利用广度优先算法判断图的连通性
    bool isConnect()const;
    //利用广度优先算法寻找图的连通分支
    adjacencyWGraph* findConnect()const;
    //用Floyd算法求任意两节点的最短路径
    int Floyd(const string& s1, const string& s2)const;
    //获取输入的字符串的最大长度，以保持输出的整齐
    void getMaxLength();
    //返回边的个数
    int getEdgeNum();
};

#endif // GRAPH_H
