#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;

//
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1)
		res[n] = 1;
	return res;
}


int main() {
	int N;
	map<int, int>a = prime_factor(N);
	map<int, int>::iterator ite;
	for ( ite = a.begin(); ite != a.end(); ite++) {
		cout << ite->first << " " << ite->second << endl;
	}
	return 0;
}
