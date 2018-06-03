#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
#define maxv 105
int N;
double map[maxv][maxv];
double temp[maxv];
double res[maxv];

void init(){
	/*
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N+1;j++){
			cin>>map[i][j];
		}
	}
	*/
	ifstream fin("test.txt");
	fin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N+1;j++){
			fin>>map[i][j];
		}
	}
	cout<<N<<"---"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N+1;j++){
			cout<<map[i][j]<<"  ";
		}
		cout<<endl;
	}
}

/*ѡ��Ԫ������*/
void choice(int index, int r){
	int maxM = map[r][index];
	int replaceR = 0;
	for(int i=r;i<N;i++){
		if(map[i][index]>maxM){
			maxM = map[i][index];
			replaceR = i; 
		}
	}
	for(int i=0;i<N;i++){
		temp[i] = map[r][i];
		map[r][i] = map[replaceR][i];
		map[r][i] = temp[i];
	}
}
/*��Ԫ*/
void del(int r){
	for(int j=r;j<N;j++){
		double temp = map[j][r-1]/map[r-1][r-1];
		for(int i=0;i<N+1;i++){
			map[j][i] = map[j][i]-temp*map[r-1][i];
		}
	}
}

int main(){
	init();
	for(int i=0;i<N;i++){
		choice(i,i);
		if(i+1<N)
			del(i+1);
	}
	for(int i=0;i<N;i++){
		cout<<map[i][N]<<endl;
	}
	cin>>N;
	return 0;
}