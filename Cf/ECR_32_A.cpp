#include<iostream>
#include<vector>
using namespace std;

int a[1005];
int main() {
	int n;
	while (cin >> n) {
		int result = 0;
		if (n <= 2) {
            for (int i = 0; i < n; i++) {
				cin >> a[i];
			}
			result = 0;
		}
		else {
			for (int i = 0; i < n; i++) {
				cin >> a[i];
			}
			for (int i = 1; i < n - 1; i++) {
				if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
					result++;
				}
				else if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
					result++;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}