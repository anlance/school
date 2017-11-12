#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s;
	int n;
	int a[3];
	int x1, x2;
	while (cin >> n) {
		cin >> s;
		int temp = 0;
		for (int i = 0; i < 4; i++) {
			a[i] = 0;
		}
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
				case 'D':a[0]++; break;
				case 'L':a[1]++; break;
				case 'R':a[2]++; break;
				case 'U':a[3]++; break;
			}
		}
		if (a[0] <= a[3]) {
			x1 = a[0];
		}
		else {
			x1 = a[3];
		}
		if (a[1] <= a[2]) {
			x2 = a[1];
		}
		else {
			x2 = a[2];
		}
		cout << 2*(x1 + x2) << endl;
	}
}
