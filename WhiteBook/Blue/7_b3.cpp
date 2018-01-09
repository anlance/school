/*

凑算式

     B      DEF
A + --- + ------- = 10
     C      GHI
     
（如果显示有问题，可以参见【图1.jpg】）
	 
	 
这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。

这个算式一共有多少种解法？

注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。

*/

#include <iostream>
using namespace std;

//baoli

int main(){
	int count = 0;
	for(int i = 1; i < 10; i++){ //A
		for(int j = 1; j < 10; j++){ //B
			for(int k = 1; k < 10; k++){ //C
			int ac = i*k;
				for(int m = 111; m < 1000; m++){ //DEF
				if(m%10==0)
					continue;
				int cd = k*m;
					for(int n = 111; n <1000; n++){ //GHI
					if(n%10==0)
						continue;
						if(((ac+j)*n+cd) == ((k*n)*10)){
							count++;
						}
					}
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
//53422
