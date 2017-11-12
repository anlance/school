#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*int main() {
	string s;
	while (cin >> s) {
		bool sss[26];
		bool judge = false;
		int temp;
		for (int k = 1; k <s.length(); k++) {
			for (int i = 0; i < s.length(); i++) {//辅助找到唯一的c
				sss[i] = false;
			}
			temp = k;
			judge = false;
			for (int i = 1; i < (s.length()-temp); i++) {//最后一个起始地址
				judge = false;
				for (int j = i; j < (temp+i)&&j<s.length(); j++) {
					for (int m = 0; m < temp&&m<s.length(); m++) {	//最初k个
						if ((i==1&&s[j] == s[m])||(s[j] == s[m]&&sss[m]==true)) {
							sss[m] = true;
							judge = true;
						}
					}
				}
				if (judge == false) {
					break;
				}
			}
			if (judge ==true) {
				break;
			}
		}
		cout << temp << endl;
	}
	return 0;
}
*/
//hhh上面是暴力，我以为能骗一下的，结果第四组数据就呵呵呵了，果然还是一开始的分治
//几天了，不写了