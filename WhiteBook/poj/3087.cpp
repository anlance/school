#include<iostream>
#include<string>
#include<vector>
using namespace std;

string str1, str2, str12;
int length;

bool cmp(string &s1, string &s2,int len){
    for (int i = 0; i < len;i++){
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}

vector<string> vis;
int doit(string &s1,string &s2){
    int count = 0;
    string s12(401,'a');
    while(true){
        for (int i = 0; i < length;i++){
            s12[2 * i + 1] = s1[i];
            s12[2 * i ] = s2[i];
        }
        count++;
        if(cmp(s12, str12, length*2)){
            return count;
        }
        else{
            for (int i = 0; i < vis.size();i++){
                if(cmp(vis[i], s12, length*2)){
                    return -1;
                }
            }
            vis.push_back(s12);
        }
        for (int i = 0; i < length*2;i++){
            if(i<length){
                s1[i] = s12[i];
            }
            else{
                s2[i - length] = s12[i];

            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> length;
        vis.clear();
        cin >> str1 >> str2 >> str12;
        int result = doit(str1, str2);
        cout << i + 1 << " " << result << endl;
    }
}