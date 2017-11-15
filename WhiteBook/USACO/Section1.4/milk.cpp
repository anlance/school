/*
ID: anlandu1
TASK: milk
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> P;
struct cmp {
	bool operator()(P a, P b) {
		if (a.first > b.first)
			return a < b;
        return a > b;
	}
};

int main(){
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int N, M;
    while(fin>>N){
        fin >> M;
        int Money = 0;
        vector<P> que;
        int a, b;
        for (int i = 0; i < M;i++){
            fin >> a >> b;
            que.push_back(P(a, b));
        }
        sort(que.begin(), que.end());
        for (int i = 0; i < que.size();i++){
            P temp = que.at(i);
            //fout << temp.first << "  " << temp.second << "-----" << endl;
            if(temp.second<N){
            Money += temp.first*temp.second;
            N -= temp.second;
            }else if(temp.second==N){
                Money += temp.first * temp.second;
                N -= temp.second;
                break;
            }else{
                temp.second -= N;
                Money += temp.first * N;
                N = 0;
                break;
            }
        }
            /*while(!que.empty()){
            P temp = que.top();
            que.pop();
            fout << temp.first << "  " << temp.second << "-----" << endl;
            if(temp.second<N){
            Money += temp.first*temp.second;
            N -= temp.second;
            }else if(temp.second==N){
                Money += temp.first * temp.second;
                N -= temp.second;
                break;
            }else{
                temp.second -= N;
                Money += temp.first * N;
                N = 0;
                break;
            }
        }*/
            fout << Money << endl;
    }
}