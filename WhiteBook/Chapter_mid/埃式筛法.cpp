#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;

//埃氏筛法
//首先找到素数2，然后把2的倍数的数删去
//然后是3.再删去
//然后。。。。。

const  int max_n = 65236;
int sieve(int n) {
	vector<int> prime;		//第i个素数
     int is_prime[max_n];	//is_prime[i]为true表示i为素数

	for (int i = 0; i < n; i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i < n; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
			for (int j = i+i; j < n; j+=i) {
				if (j%i == 0)
					is_prime[j] = false;
			}
		}
	}

}
