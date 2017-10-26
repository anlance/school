#include<iostream>
#include<vector>
using namespace std;

struct doctor {
	int s, d;
};
int N;
doctor doc[1005];
int main() {

	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			cin >> doc[i].s >> doc[i].d;
		}
		//doc[N].s = doc[N-1].s, doc[N].d = 0;
		for (int i = 1; i < N; i++) {
			while (doc[i].s<=doc[i - 1].s) {
				doc[i].s += doc[i].d;
			}
		}
		cout << doc[N - 1].s << endl;
	}
	return 0;
}