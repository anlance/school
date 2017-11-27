#include<iostream>
#include<string>
using namespace std;

struct Node{
	int cost;
	int start;
	char cc;
};
string s;

int main(){
	cin >> s;
	int length = s.length();
	Node a[length];
	int Min = 65536, Max = 0;
	for (int i = 0; i < length;i++){
		a[i].cost = int(s[i]);
		if(int(s[i])<Min){
			Min = int(s[i]);
		}
		if(int(s[i])>Max){
			Max = s[i];
		}
	}

}
