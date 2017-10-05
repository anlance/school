#include<iostream>
#include<queue>
using namespace std;

int W, H, N;
char map[1024][1024];
//各点到当前工厂的距离
int d[1024][1024];
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
typedef pair<int, int> P;
P aim[10];
P ss, gg;
int bfs(P s,P g) {
	queue<P> que;
	P n;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			d[s.first][s.second] = -1;
	}
	que.push(s);
	d[s.first][s.second] = 0;
	while (que.size()) {
		P p = que.front();
		que.pop();
		if (p.first == g.first&&p.second == g.second)
			break;
		for (int i = 0; i < 4; i++) {
			n.first = s.first + dx[i];
			n.second = s.second + dy[i];
			if (0 <= n.first&&n.first < H && 0 <= n.second&&n.second < W&&d[n.first][n.second] == -1) {
				que.push(n);
				d[n.first][n.second] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[g.first][g.second];
}
int main() {
	int i, j, t, step = 0;
	cin >> H >> W >> N;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] <= '9'&&'1' <= map[i][j]) {
				t = map[i][j] - '0';
				aim[t].first = i;
				aim[t].second = j;
			}
			else if (map[i][j] == 'S') {
				ss.first = i;
				ss.second = j;
				map[i][j] = '.';
			}
		}
	for (int i = 1; i < N; i++) {
		gg.first = aim[i].first;
		gg.second = aim[i].second;
		step += bfs(ss, gg);
		ss.first = gg.first;
		ss.second = gg.second;
		map[gg.first][gg.second] = '.';
	}
	cout << step << endl;
}
