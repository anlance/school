#include<iostream>
#include<vector>
using namespace std;

/*
我已经举得没问题了
但还是WA WA WA
*/

struct room{
    int start;
    int end;
    bool flag;
};
vector<room> V;

int doit(){
    int count = 0;
    for (int i = 0; i < V.size();i++){
        room temp = V.at(i);
        if(temp.flag==true){
            continue;
        }
        else{
            V[i].flag = true;
            for (int j = 1; j < V.size();j++){
                room next = V.at(j);
                if(next.flag==true){
                    continue;
                }
                else{
                    if(temp.end%2==0){
                        if(next.start>temp.end){
                            V[j].flag = true;
                            continue;
                        }
                    }
                    else{
                        if(next.start>temp.end+1){
                            V[j].flag = true;
                            continue;
                        }
                    }
                }
            }
            count+=10;
        }
    }
    return count;
}

int main(){
    int T, N;
    int a, b;
    cin>>T;
        for (int i = 0; i < T;i++){
            cin >> N;
            if(N==1){
                cin >> a >> b;
                cout << 10 << endl;
            }
            else{
                V.clear();
                for (int j = 0; j < N;j++){
                    cin >> a >> b;
                    room t;
                    if(a>b){
                        swap(a, b);
                    }
                    t.start = a;
                    t.end = b;
                    t.flag = false;
                    V.push_back(t);
                }
                int result = doit();
                cout << result << endl;
            }
        }
    return 0;
}