//#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int max_v = 305;
const int max_time = 50005;
int map[max_v][max_v];	//整个地图
int step[max_v][max_v];	//时间
int M;	//流星雨次数
class meteor {
public:
	int x, y, t;	//坐标与时间
	meteor(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->t = z;
	}
};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1 };		//移动
queue<meteor> que;

bool isLegal(int x, int y) {
	//是否在地图内
	if (0 <= x&&x < max_v && 0 <= y&&y < max_v)
		return true;
	else
		return false;
}

int bfs(int sx, int sy) {
	if (map[sx][sy] == 0)
		return -1;	//初始地点一开始被击中
	else if (map[sx][sy] == max_time)
		return 0;	//起点一直安全
	que.push(meteor(sx,sy,0));
	while (!que.empty()) {
		meteor nNode = que.front();
		que.pop();
		int px = nNode.x;
		int py = nNode.y;
		int pt = nNode.t;

		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (isLegal(nx, ny)) {//在地图内
				if (map[nx][ny] == max_time) {
					//到达安全区域
					return pt+1;
				}
				else if (pt+1 < map[nx][ny]&&step[nx][ny]==0) {
					//这个点不被破坏
					step[nx][ny] = nNode.t + 1;
					que.push(meteor(nx, ny, step[nx][ny]));
				}
			}
		}
	}
	return -1;
}

int main() {
	while (/*cin >> M*/~scanf("%d", &M)) {
		meteor Node(0, 0, 0);
		//初始化地图和时间线
		for (int i = 0; i < max_v; i++) {
			for (int j = 0; j < max_v; j++) {
				map[i][j] = max_time;
				step[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++) {//轰炸
			//cin >> Node.x >> Node.y >> Node.t;
			scanf("%d %d %d", &Node.x, &Node.y, &Node.t);
			map[Node.x][Node.y] = min(map[Node.x][Node.y], Node.t);
			for (int j = 0; j < 4; j++) {
				int nx = Node.x + dx[j];
				int ny = Node.y + dy[j];
				if (isLegal(nx, ny)) {
					map[nx][ny] = min(map[nx][ny], Node.t);
				}
			}
		}
		int result = bfs(0, 0);
		//cout << result << endl;
		printf("%d\n", result);
	}
}


