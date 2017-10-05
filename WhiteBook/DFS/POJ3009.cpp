#include<iostream>
#include<fstream>
using namespace std;

const int max_v = 21;
int mm[max_v][max_v];
bool flag[max_v][max_v];	//true是换方向点处
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int pre_addx=0, pre_addy=0;		//前一个方向
int min_count = 11;
int Count = 0;
int W=0, H=0;
int sx=0, sy=0;

void dfs(int x, int y) {
	if (min_count <= Count) {
		return;
	}		//剪枝
	else if (flag[x][y] == true) {//遭遇转折点（包括起点）
			//把起点重设置为不是转折点
			flag[x][y] = false;	
		for (int i = 0; i < 4; i++) {
			pre_addx = dx[i];
			pre_addy = dy[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (mm[nx][ny] == 0 && (0 <= nx&&nx < H) && (0 <= ny&&ny < W)) {
				Count++;	//换方向，增加步数
				dfs(nx, ny);
				Count--;	//还原步数
			}
			else if (mm[nx][ny] == 3 && (0 <= nx&&nx < H) && (0 <= ny&&ny < W)) {
				Count++;	//换方向，增加步数
				if (Count < min_count)
					min_count = Count;
				Count--;	//还原步数
				return;
			}
		}
	}
	else {	//按照之前的方向前进
		int temp_x = pre_addx;
		int temp_y = pre_addy;	//	此时的前一个方向
		int nx = x + temp_x;
		int ny = y + temp_y;
		while (mm[nx][ny] == 0 && (0 <= nx&&nx < H) && (0 <= ny&&ny < W)) {
			nx += temp_x;
			ny += temp_y;
		}
		if (mm[nx][ny] == 3 && (0 <= nx&&nx < H) && (0 <= ny&&ny < W)) {
			if (Count < min_count)
				min_count = Count;
			return;
		}
		else if (mm[nx][ny] == 1 && (0 <= nx&&nx < H) && (0 <= ny&&ny < W)) {//遇到阻碍
			mm[nx][ny] = 0;		//摧毁 
			flag[nx - temp_x][ny - temp_y] = true;
			dfs(nx - temp_x,ny - temp_y);
			mm[nx][ny] = 1;		//重建
			flag[nx - temp_x][ny - temp_y] = false;
		}
	}
}
int main() {
	while (cin >> W >> H&&W!=0&&H!=0) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> mm[i][j];
				flag[i][j] = false;
				if (mm[i][j] == 2) {
					sx = i; sy = j;
				}
			}
		}
		flag[sx][sy] = true;
		mm[sx][sy] = 0;		//将0赋值给起点
		Count = 0;
		min_count = 11;
		pre_addx = 0, pre_addy = 0;
		dfs(sx, sy);
		if (min_count <= 10) {
			cout << min_count << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}
