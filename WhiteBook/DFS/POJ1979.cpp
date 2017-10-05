#include<iostream>
using namespace std;

int R=0, L=0;//R表示行,L表示列
const int max_v = 21;
char mm[max_v][max_v];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int res = 0;
void dfs(int x,int y) {
	res++;
	mm[x][y] = '#';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ((nx >= 0 && nx < R) && (ny >= 0 && ny < L) && mm[nx][ny] == '.')//nx<L?智障了,断片了
			dfs(nx, ny);
	}
}

int main() {
	int sx = 0;
	int sy = 0;
	while (cin >> L >> R&&(R!=0&&L!=0)) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < L; j++) {
				cin >> mm[i][j];
				if (mm[i][j] == '@') {
					sx = i;
					sy = j;
				}
			}
		}
		res = 0;
		dfs(sx, sy);
		cout << res << endl;
	}
	return 0;
}
