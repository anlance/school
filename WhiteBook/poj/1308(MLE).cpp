#include<iostream>
#include<vector>
using namespace std;

vector<int> par;
int maxCin = 0;


void init(){
    maxCin = 0;
    par.clear();
    par.reserve(0);
}

int find(int a){
    if(par.at(a)==a)
        return a;
    return par.at(a) = find(par.at(a));
}

void unite(int a, int b){
    int temp = a > b ? a : b;
    if(temp>maxCin){
        maxCin = temp;
        for (int i = par.size(); i < maxCin + 1;i++){
            par.push_back(i);
        }
    }
    par.at(b) = a;
}

bool helpsame(int a, int b){
    int temp = a > b ? a : b;
    if(temp>maxCin){
        maxCin = temp;
        for (int i = par.size(); i < maxCin + 1;i++){
            par.push_back(i);
        }
    }
    if(par.at(b)!=b)//该节点已经有父节点
        return true;
    else
        return false;
}

bool same(int a, int b){//用来查是否只存在一个连通分量
    return find(a) == find(b);
}

int main(){
    int a, b;
    init();
    int count = 0;
    bool flag = false;
    while(cin>>a>>b){
        if(a==-1&&b==-1)
            break;
        else if(a==0&&b==0){
            // for (int k = 0; k < par.size();k++){
            //     int x = find(k);
            //     cout << x << " ";
            // }
            count++;
            if(flag==true)
                cout << "Case " << count << " is not a tree." << endl;
            else{
                for (int i = 0; i < par.size();i++){
                    if(par.at(i)==i)
                        continue;
                    for (int j = 0; j < par.size();j++){
                        if(par.at(j)==j)
                            continue;
                        if(!same(i,j))
                            flag = true;
                        break;
                    }
                    if(flag==true)
                        break;
                }
                if(flag==true)
                    cout << "Case " << count << " is not a tree." << endl;
                else
                    cout << "Case " << count << " is a tree." << endl;
            }
            init();
            flag = false;
        }
        else{
            if(helpsame(a,b)){
                flag = true;
                //cout << "a" << a << "--" << b << endl;
            }
            else if(a==b){
                flag = true;
                //cout << a << "--" << b << "b" << endl;
            }
            else{
                unite(a, b);
            }
        }
    }
    return 0;
}