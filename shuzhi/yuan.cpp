#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;

const int length = 4;

void mycopy(double **a, double **b, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = b[i][j];
}
void mycopy(double *a, double *b, int n) {
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}
void output(double** a, int n) {
	for (int l = 0; l < n; l++) {
		for (int q = 0; q < n; q++) {
			cout << setw(12) << a[l][q];
		}
		cout << endl;
	}
	cout << endl << endl;
}
void output(double *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(12) << a[i];
	}
	cout << endl;
}
//高斯消元法
double* gauss(double** a, double *b, int n) {
	for (int k = 0; k < n-1; k++) {//第k(0--n-2)列
		for (int i = k + 1; i < n; i++) {
			a[i][k] = a[i][k] / a[k][k];
			for (int j = k + 1; j < n; j++) {
				a[i][j] = a[i][j] - a[k][j] * a[i][k];
			}
			//值向量更新
			b[i] = b[i] - b[k] * a[i][k];
		}
		//输出系数矩阵
		cout << "第" << k + 1 << "次的变换后的系数矩阵：" << endl;
		output(a, n);
	}
	//输出实际上三角增广矩阵
	cout << "实际最终上三角矩阵为：" << endl;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) cout <<setw(12)<< 0;
		for (int j = i; j < n; j++) {
			cout << setw(12) << a[i][j];
		}
		cout << setw(12) << b[i] << endl;
	}
	cout << endl << endl;
	//回带求解
	b[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			b[i] = b[i] - b[j] * a[i][j];
		}
		b[i] = b[i] / a[i][i];
	}
	return b;
}
//列主元的高斯消元法
double* keyGauss(double** a, double *b, int n) {
	//参数说明：a表示系数矩阵，b表示值向量，n表示系数矩阵的行数
	for (int k = 0; k < n - 1; k++) {//第k(0--n-2)列
		//选主元
		int maxrow = n-1;   //第k列主元的行
		for(int i = k; i < n; i++) {
			if (abs(a[i][k]) > abs(a[maxrow][k])) maxrow = i;
		}
		//交换主元行和第k行
		for (int i = 0; i < n; i++) swap(a[maxrow][i], a[k][i]);
		swap(b[maxrow], b[k]);
		for (int i = k + 1; i < n; i++) {
			//第i(k+1--n-1)行
			a[i][k] = a[i][k] / a[k][k];
			for (int j = k + 1; j < n; j++) {
				//第i行的一部分元素
				a[i][j] = a[i][j] - a[k][j] * a[i][k];
			}
			//值向量更新
			b[i] = b[i] - b[k] * a[i][k];
		}
		//输出系数矩阵
		cout << "第" << k + 1 << "次的变换后的系数矩阵：" << endl;
		output(a, n);
	}
	//输出实际上三角增广矩阵
	cout << "实际最终上三角矩阵为：" << endl;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) cout << setw(12) << 0;
		for (int j = i; j < n; j++) {
			cout << setw(12) << a[i][j];
		}
		cout << setw(12) << b[i] << endl;
	}
	cout << endl << endl;
	//回带求解
	b[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			b[i] = b[i] - b[j] * a[i][j];
		}
		b[i] = b[i] / a[i][i];
	}
	//返回值向量
	return b;
}
//杜利特尔分解
double* Doolittle(double** a, double *b, int n) {
	//第i行和第i列处理
	for (int i = 0; i < n; i++) {
		//第i行的相应元素
		for (int j = i; j < n; j++) {
			int k = i;
			while (k - 1 >= 0) {
				a[i][j] = a[i][j] - a[k - 1][j] * a[i][k - 1];
				k--;
			}
		}
		//值向量更新
		int k = i;
		while (k - 1 >= 0) {
			b[i] = b[i] - b[k-1] * a[i][k - 1];
			k--;
		}
		//第i列的相应元素
		for (int j = i + 1; j < n; j++) {
			int k = i;
			while (k - 1 >= 0) {
				a[j][i] = a[j][i] - a[j][k-1] * a[k-1][i];
				k--;
			}
			a[j][i] /= a[i][i];
		}
	}
	cout << "杜利特尔分解的L矩阵:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << setw(12) << a[i][j];
		}
		cout << setw(12) << 1 << endl;
	}
	cout << endl << endl << "杜利特尔分解的U矩阵：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) cout << setw(12) << 0;
		for (int j = i; j < n; j++) {
			cout << setw(12) << a[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
	//回带求解
	b[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			b[i] = b[i] - b[j] * a[i][j];
		}
		b[i] = b[i] / a[i][i];
	}
	//返回值向量
	return b;
}
//雅可比迭代
double* Jacobi(double **a, double *b, int n) {
	double *ans = new double[n];
	for (int i = 0; i < n; i++) ans[i] = 0;
	double *last = new double[n];
	double m;
	int cnt = 0;
	do {
		//对第i行
		double temp;
		for (int i = 0; i < n; i++) last[i] = ans[i];
		for (int i = 0; i < n; i++) {
			temp = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				temp += a[i][j] * last[j];
			}
			ans[i] = (b[i]-temp)/a[i][i];
		}
		m = 0;
		for (int i = 0; i < n - 1; i++) {
			m = max(m, abs(ans[i]-last[i]));
		}
		cout << "第" << ++cnt << "次迭代:  ";
		output(ans, n);
	} while (m >= 0.00001&&cnt < 80);
	delete []last;
	return ans;
}
double* seidel(double **a, double *b, int n) {
	double *ans = new double[n];
	for (int i = 0; i < n; i++) ans[i] = 0;
	double *last = new double[n];
	int cnt = 0;
	double m;
	do {
		double temp;
		for (int i = 0; i < n; i++) last[i] = ans[i];
		//第i行
		for (int i = 0; i < n; i++) {
			temp = 0;
			for (int j = 0; j < i; j++) temp += a[i][j] * ans[j];
			for (int j = i + 1; j < n; j++) temp += a[i][j] * last[j];
			ans[i] = (b[i] - temp) / a[i][i];
		}
		m = 0;
		for (int i = 0; i < n - 1; i++) {
			m = max(m, abs(ans[i] - last[i]));
		}
		cout << "第" << ++cnt << "次迭代:  ";
		output(ans, n);
	} while (m >= 0.00001&&cnt < 80);
	delete[]last;
	return ans;
}

int main()
{
	double **a, *b,**aa,*bb;     //系数矩阵和值矩阵,aa bb 用于保存初始矩阵
	a = new double*[length];
	b = new double[length];
	aa = new double*[length];
	bb = new double[length];
	for (int i = 0; i < length; i++) {
		a[i] = new double[length];
		aa[i] = new double[length];
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < length; i++) {
		bb[i] = (rand() % 31) - 10;   //生成-10--20的随机数
		for (int j = 0; j < length; j++) {
			aa[i][j] = (rand() % 31) - 10;
		}
	}
/*	aa[0][0] = 10; aa[0][1] = -2; aa[0][2] = -1;
	aa[1][0] = -2; aa[1][1] = 10; aa[1][2] = -1;
	aa[2][0] = -1; aa[2][1] = -2; aa[2][2] = 5;
	bb[0] = 3; bb[1] = 15; bb[2] = 10;*/

	cout << "初始增广矩阵:" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << setw(12) << aa[i][j];
		}
		cout << setw(12) << bb[i] << endl;
	}
	cout << endl << endl;
	char choose;
	double *ans;
	cout << "a.高斯消元法" << endl << "b.列主元的高斯消元法" << endl;
	cout << "c.杜利特尔分解法" << endl << "d.雅可比迭代法" << endl;
	cout << "e.高斯塞达尔迭代法" << endl << "其余任意键退出" << endl;
	cout << "请选择：";
	while (cin >> choose) {
		mycopy(a, aa, length);
		mycopy(b, bb, length);
		switch (choose)
		{
		case 'a': {
			ans = gauss(a, b, length);
			cout << "方程组的解为：" << endl;
			output(ans, length);
			break;
		}
		case 'b': {
			ans = keyGauss(a, b, length);
			cout << "方程组的解为：" << endl;
			output(ans, length);
			break;
		}
		case 'c': {
			ans = Doolittle(a, b, length);
			cout << "方程组的解为：" << endl;
			output(ans, length);
			break;
		}
		case 'd': {
			ans = Jacobi(a, b, length);
			cout << "方程组的解为：" << endl;
			output(ans, length);
			break;
		}
		case 'e': {
			ans = seidel(a, b, length);
			cout << "方程组的解为：" << endl;
			output(ans, length);
			break;
		}

		default: return 0;
		}
		cout << "a.高斯消元法" << endl << "b.列主元的高斯消元法" << endl;
		cout << "c.杜利特尔分解法" << endl << "d.雅可比迭代法" << endl;
		cout << "e.高斯塞达尔迭代法" << endl << "其余任意键退出" << endl;
		cout << "请选择：";
	}
	return 0;
}
