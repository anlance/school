/*

生日蜡烛

某君从某年开始每年都办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。

现在算起来，他一共吹熄了236根蜡烛。

请问，他从多少岁开始过生日party的？

请填写他开始过生日party的年龄数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include <iostream>
using namespace std;

int main(){
	int x;
	int result = 0;
	bool flag = false;
	for(int i = 1; i < 100; i++){
		result = 0; 
		for(int j = i; j < 100; j++){
			result += j;
			if(result>236){
				break;
			}
			if(result == 236){
				x = i;
				flag = true;
				break;
			}
		}
		if(flag == true)
			break; 
	} 
	cout<<x<<endl;
	return 0;
} 

//26

