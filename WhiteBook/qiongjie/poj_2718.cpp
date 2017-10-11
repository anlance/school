//复制的一份代码
//我是根本没打算用穷竭，而是先对输入的数分奇偶；
//偶数组，先找出相差最小的一对数，如果有多组的话，就考虑偏向中间的，然后小接大反序，大接小正序；
//奇数组找出一个非0最小数之后，后面类似；

//下面的代码是穷竭搜索加剪枝
#include<iostream>  
#include<algorithm>
#include<string>  
#include<string>  
 
using namespace std;
#define mxl 30  
#define mxn 20  
#define inf 0x3f3f3f3f  
int a[mxn], cnt;
int ans;
int poww[] = { 1,10,100,1000,10000 };
bool isdigit(char in) {
	return in >= '0'&&in <= '9';
}
int iabs(int in) {
	return in<0 ? -in : in;
}
void dfs(int loc, int numa, int numb, int flag) {
	int tema, temb;
	if (loc == cnt)
		ans = min(ans, iabs(numa - numb));
	if (loc - 1 >= cnt / 2) {
		tema = numb*poww[cnt - loc];
		temb = (numb + 1)*poww[cnt - loc] - 1;
		if (tema >= numa&&tema - numa >= ans)    return;
		if (temb <= numa&&numa - temb >= ans)    return;
	}
	for (int i = 0; i<cnt; ++i)   if (!(flag&(1 << i))) {
		if (!loc&&cnt>3 && !a[i])   continue;
		if (loc == cnt / 2 && cnt != 2 && !a[i])   continue;
		tema = numa, temb = numb;
		if (loc >= cnt / 2)   temb = temb * 10 + a[i];
		else    tema = tema * 10 + a[i];
		dfs(loc + 1, tema, temb, flag | (1 << i));
	}
}
int main() {
	int cs;
	cin>>cs;
	getchar();
	while (cs--) {
		ans = inf;
		cnt = 0;
		char eat;
		while ((eat = getchar()) != '\n')    if (isdigit(eat))
			a[cnt++] = eat - '0';
		dfs(0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}