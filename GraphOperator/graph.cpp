#include "graph.h"
int stn = 0;

//构造函数
adjacencyWGraph::adjacencyWGraph(int numberOfV)
{
    //检查顶点合法性
    if (numberOfV < 0) {
        ostringstream s;
        s << "构造的顶点个数为：" << numberOfV << "    顶点个数必须≥0" << std::endl;
        throw illegalParameterValue(s.str());
    }
    n = numberOfV;
    e = 0;
    vertex = new string[n];
    for (int i = 0; i < n; i++) {
        vertex[i] = "NULL";
    }
    //构造二维矩阵
    a = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        a[i] = new int[n + 1];
    }
    //初始化二维矩阵
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            a[i][j] = INT_MAX;
        }
    }
}
//析构函数
adjacencyWGraph::~adjacencyWGraph()
{
    for (int i = 0; i < n + 1; i++) {
        delete[]a[i];
    }
    delete[]a;
    delete[]vertex;
}
//输入顶点集合
void adjacencyWGraph::inputV(const string &s)
{
    stringstream ss(s);
    for(int i = 0; i < n; i++)
    {
        ss >> vertex[i];
    }
}

//输入边的个数以及边的集合
void adjacencyWGraph::inputE(const int &e, const string &s)
{
    this->e = e;

    stringstream ss(s);
    string v1,v2;
    int w;

    for(int i=0;i<e;i++)
    {
        ss>>v1>>v2>>w;
        this->insertEdge(v1,v2,w);
    }
}

//文件输入
void adjacencyWGraph::inputFile(string path)
{
    int vtNum;
    ifstream file;
    file.open(path);
    file >> vtNum;

    for(int i = 0; i < n; i++)
    {
        file >> vertex[i];
    }
    int e;
    file >> e;
    this->e = e;
    string v1,v2;
    int w;

    for(int i=0;i<e;i++)
    {
        file>>v1>>v2>>w;
        this->insertEdge(v1,v2,w);
    }
    file.close();
}

//判断(v1,v2)是不是图的一条边
bool adjacencyWGraph::existsEdge(const string& v1, const string& v2)const
{
    if (a[indexOfV(v1)][indexOfV(v2)] != INT_MAX) {
        return true;
    }
    else {
        return false;
    }
}
//插入一条边(v1,v2)
void adjacencyWGraph::insertEdge(const string& v1, const string& v2, int w)
{
    if (a[indexOfV(v1)][indexOfV(v2)] == INT_MAX) {
        e++;
        a[indexOfV(v1)][indexOfV(v2)] = a[indexOfV(v2)][indexOfV(v1)] = w;
    }
}
//删除边(v1,v2)
void adjacencyWGraph::eraseEdge(const string& v1, const string& v2)
{
    if (a[indexOfV(v1)][indexOfV(v2)] != INT_MAX) {
        a[indexOfV(v1)][indexOfV(v2)] = a[indexOfV(v2)][indexOfV(v1)] = INT_MAX;
        e--;
    }
}
//确认顶点的度
int adjacencyWGraph::degree(const string& theVertex)const
{
    int sum = 0;
    int index = indexOfV(theVertex);
    for (int i = 1; i <= n; i++) {
        if (a[index][i] != INT_MAX) {
            sum++;
        }
    }
    return sum;
}
//查找顶点索引
int adjacencyWGraph::indexOfV(const string& theVertex)const
{
    for (int i = 0; i < n; i++) {
        if (vertex[i] == theVertex) {
            return i + 1;
        }
    }
    ostringstream s;
    s << "寻找索引时，" << theVertex << "不是有效节点" << std::endl;
    throw illegalParameterValue(s.str());
}
//输出节点集合
void adjacencyWGraph::outputVertex(string &s)const
{
    for (int i = 0; i < n; i++) {
        //cout << vertex[i] << "  ";
        s += vertex[i];
        s += "  ";
    }
    //cout << endl;
    s += "\r";
}
//边的形式输出图
void adjacencyWGraph::outputGraph(string &s)const
{
    stringstream ss;
    string temp;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] != INT_MAX) {
                //cout << vertex[i - 1] << "  " << vertex[j - 1] << "   " << a[i][j] << endl;
                ss.clear();
                ss << vertex[i-1];
                ss >> temp;
                s += temp;

                s += "  ";

                ss.clear();
                ss << vertex[j-1];
                ss >> temp;
                s += temp;

                s += "  ";

                ss.clear();
                ss << a[i][j];
                ss >> temp;
                s += temp;

                s += "\r";
            }
        }
    }
}
//矩阵形式输出图
void adjacencyWGraph::outputWithAdjacency(string &s)const
{
    stringstream ss;
    string temp;
    s += " ";
    for (int i = 0; i < n; i++) {
        for(int k = 0; k < maxLength+2-1; k++){
            s += " ";
        }

        ss.clear();
        ss << vertex[i];
        ss >> temp;
        s += temp;
    }
    s += "\r";
    for (int i = 1; i <= n; i++) {
        ss.clear();
        ss << vertex[i - 1];
        ss >> temp;
        s += temp;
        for(int k = 0; k < maxLength+2-1; k++){
            s += " ";
        }
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != INT_MAX) {
                ss.clear();
                ss << a[i][j];
                ss >> temp;
                s += temp;
                for(int k = 0; k < maxLength+2-(int)temp.length(); k++){
                    s += " ";
                }
            }
            else {
                s += "∞";
                for(int k = 0; k < maxLength; k++){
                    s += " ";
                }
            }
        }
        s += "\r";
    }
    //cout<<s<<endl;
}
//广度优先搜索
void adjacencyWGraph::bfs(const string& v, string &s)const
{
    queue<int> q;
    int *reach = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        reach[i] = 0;
    }
    reach[indexOfV(v)] = 1;
    q.push(indexOfV(v));
    //cout << v << "  ";
    s += v;
    s += "  ";
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        //标记没有到达的邻接于顶点w的顶点
        for (int i = 1; i <= n; i++) {
            if (a[w][i] != INT_MAX && reach[i] == 0) {
                q.push(i);
                reach[i] = 1;
                //cout << vertex[i - 1] << "  ";
                s += vertex[i-1];
                s += "  ";
            }
        }
    }
    //cout << endl;
    delete[]reach;
}
//初始化深度优先标记数组
void adjacencyWGraph::initReach()const
{
    for (int i = 1; i <= n; i++) {
        reach[i] = 0;
    }
}
//深度优先搜索
void adjacencyWGraph::dfs(int v,string &s)const
{
    reach[v] = 1;
    //cout << vertex[v - 1] << "  ";
    s += vertex[v-1];
    s += "  ";
    for (int i = 1; i <= n; i++) {
        //没有到达且邻接于v的节点
        if (a[v][i] != INT_MAX && reach[i] != 1) {
            dfs(i,s);
        }
    }
}
//利用广度优先算法判断图的连通性
bool adjacencyWGraph::isConnect()const
{
    queue<int> q;
    int *reach = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        reach[i] = 0;
    }
    reach[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        //标记没有到达的邻接于顶点w的顶点
        for (int i = 1; i <= n; i++) {
            if (a[w][i] != INT_MAX && reach[i] == 0) {
                q.push(i);
                reach[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (reach[i] == 0) {
            return false;
        }
    }
    return true;
}
//利用广度优先算法寻找图的连通分支
adjacencyWGraph* adjacencyWGraph::findConnect()const
{
    adjacencyWGraph *temp;
    stn = 0;          //连通分支数
    int **cnt = new int*[adjacencyWGraph::n + 1];           //记录节点矩阵
    for (int i = 0; i < n + 1; i++) {
        cnt[i] = new int[adjacencyWGraph::n + 1];
    }
    //节点矩阵初始化
    for (int i = 0; i < n + 1; i++) {
        cnt[i][0] = 0;
    }
    //标记数组
    int *reach = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        reach[i] = 0;
    }
    queue<int> q;
    for (int j = 1, k; j <= n; j++) {
        if (reach[j] == 0) {//若j没被标记过，则从j开始广度优先
            k = 1;              //第n+1个连通分支的第1个节点的位置
            reach[j] = 1;
            q.push(j);
            cnt[stn][0]++;          //第n+1个连通分支的节点数+1
            cnt[stn][k] = j;        //记录第k个节点
            k++;                  //节点位置加一
            while (!q.empty()) {
                int w = q.front();
                q.pop();
                //标记没有到达的邻接于顶点w的顶点
                for (int i = 1; i <= n; i++) {
                    if (a[w][i] != INT_MAX && reach[i] == 0) {
                        q.push(i);
                        cnt[stn][0]++;             //找到一个，该连通分支的节点数加一
                        cnt[stn][k] = i;              //记录该节点
                        k++;                      //节点位置+1
                        reach[i] = 1;         //标记
                    }
                }
            }
            stn++;         //连通分支数加一
        }
    }
    int c = stn;
    temp = new adjacencyWGraph[c];
    for (int i = 0; i < stn; i++) {
        //初始化第i+1个连通分支
        temp[i].n = cnt[i][0]; //节点数
        temp[i].vertex = new string[temp[i].n]; //节点集合
        for (int j = 0; j < temp[i].n; j++) {
            temp[i].vertex[j] = this->vertex[cnt[i][j + 1] - 1];
        }
        //矩阵
        temp[i].a = new int*[cnt[i][0] + 1];
        for (int j = 0; j < cnt[i][0] + 1; j++) {
            temp[i].a[j] = new int[cnt[i][0] + 1];
        }
        for (int j = 0; j < cnt[i][0] + 1; j++) {
            for (int k = 0; k < cnt[i][0] + 1; k++) {
                temp[i].a[j][k] = INT_MAX;
            }
        }
        //初始化边
        for (int j = 1; j <= cnt[i][0]; j++) {
            for (int k = 1; k <= cnt[i][0]; k++) {
                if (a[cnt[i][j]][cnt[i][k]] != INT_MAX) {
                    temp[i].insertEdge(this->vertex[cnt[i][j] - 1], this->vertex[cnt[i][k] - 1], a[cnt[i][j]][cnt[i][k]]);
                }
            }
        }
    }
    return temp;
}
//用Floyd算法求任意两节点的最短路径
int adjacencyWGraph::Floyd(const string& s1, const string& s2)const
{
    int **temp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        temp[i] = new int[n + 1];
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            temp[i][j] = a[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (temp[i][k] + temp[k][j] > 0 && temp[i][k] + temp[k][j] < temp[i][j]) {
                    temp[i][j] = temp[i][k] + temp[k][j];
                }
            }
        }
    }
    return temp[indexOfV(s1)][indexOfV(s2)];
}


//获取输入的字符串的最大长度，以保持输出的整齐
void adjacencyWGraph::getMaxLength()
{
    stringstream ss;
    this->maxLength = 2;
    string temp;
    int length;
    for(int i=0;i<n;i++){
        temp = vertex[i];
        length = temp.length();
        if(length>maxLength){
            maxLength = length;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
             if (a[i][j] != INT_MAX) {
                 ss.clear();
                 ss << a[i][j];
                 ss >> temp;
                 length = temp.length();
                 if(length>maxLength){
                     maxLength = length;
                 }
            }
        }
    }
}

//返回边的个数
int adjacencyWGraph::getEdgeNum()
{
    return this->e;
}

