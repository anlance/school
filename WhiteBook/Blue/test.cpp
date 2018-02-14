#include<iostream>
#include<cstring>
using namespace std;

#define maxv 105
#define INF 0x3f3f3f
int map[maxv][maxv];
bool used[maxv];
int d[maxv];
int N;


void init() {
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}
}

void dijkstra() {
	memset(used, false, sizeof(used));
	memset(d, INF, sizeof(d));

	d[1] = 0;
	while (true) {
		int v = -1;
		for (int i = 1; i < N + 1; i++) {
			if (!used[i] && (v == -1 || d[i]>d[v]))
				v = i;
		}
		if (v == -1)
			break;
		used[v] = true;
		for (int i = 1; i < N + 1; i++) {
			if (!used[i] && d[i]>d[v] + map[v][i]) {
				d[i] = d[v] + map[v][i];
			}
		}
	}
}

int main() {
	while (cin >> N) {
		init();
		string temp = "";
		int result = 0;
		if (N == 1) {
			result = 0;
		}
		else if (N == 2) {
			cin >> map[2][1];
			result = map[2][1];
		}
		else {
			for (int i = 2; i < N + 1; i++) {
				for (int j = 1; j < N; j++) {
					cin >> temp;
					if (temp == "x") {
						map[i][j] = INF;
					}
					else {
						map[i][j] = atoi(temp.c_str());//×Ö·û´®×ªÕûÊý
					}
					map[j][i] = map[i][j];
				}
			}
			dijkstra();
			for (int i = 1; i < N + 1; i++) {
				if (result<d[i]) {
					result = d[i];
				}
			}
		}
		cout << result << endl;
	}
}
