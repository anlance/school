#include<iostream>
using namespace std;

int l=0, r=0;
bool flag=true;

void solve(int N) {
	int a = 0;
	while (N > 0) {
		for (int i = 0; i < 10; i++) {
			cin >> a;
			if (a > l)
				l = a;
			else if (a > r)
				r = a;
			else 
				flag = false;
		}
		if (flag == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		flag = true;
		l = 0;
		r = 0;
		N--;
	}
}
int main() {
	int n = 0;
	cin >> n;
	solve(n);
	return 0;
}
