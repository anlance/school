#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<string, int>dp;
queue<string> que;
int Move[4] = { 1,-1,4,-4 };

void bfs() {
	que.push("01234567");
	dp["01234567"] = 0;
	while (!que.empty()) {
		string Node = que.front();
		que.pop();
		int Q = 0;	//Q是0的位置
		for (int i = 0; i < 8; i++) {
			if (Node[i] = '0') {
				Q = i;
				break;
			}
		}
		for (int j = 0; j < 4; j++) {
			int nQ = Q + Move[j];
			if (0 <= nQ&&nQ < 8 && !(Q == 3 && j == 0) && !(Q == 4 && j == 1)) {
				string next = Node;
				swap(next[Q], next[nQ]);
				if (dp.find(next) == dp.end()) {
					dp[next] = dp[Node] + 1;
					que.push(next);
				}
			}
		}
	}
}

int main() {
	bfs();
	string line;
	while (getline(cin, line))
	{
		line.erase(remove(line.begin(), line.end(), ' '), line.end());
		cout << dp[line] << endl;
	}

	return 0;
}
