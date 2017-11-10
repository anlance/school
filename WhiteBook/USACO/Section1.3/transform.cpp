/*
ID: anlandu1
TASK: transform
LANG: C++11                 
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

/*int N, temp, result;
char judge = false;
char Map[11][11];
char Copy[11][11];

bool vans(int n){//旋转90度，可以更加优化，去掉重复比对的地方
    temp = n;
    for (int i = 0; i < n;i++){
        temp--;
        for (int j = 0; j < n;j++){
            if(Map[i][j]!=Copy[j+n][temp]){
                return false;
            }
        }
    }
    result++;
    return true;
}

void doVans(){
    for (int k = 0; k < 3;k++){
        judge = vans(N);
        if(judge==true){
            break;
        }else{//如果没
            temp = N;
            for (int i = 0; i < N;i++){//下部分旋转90度
                temp--;
                for (int j = 0; j < N;j++){
                    Copy[j + N][temp] = Copy[i][j];
                }
            }
            for (int i = 0; i < N;i++){//上部分保存下部分
                for (int j = 0; j < N;j++){
                    Copy[i][j] = Copy[i + N][j];
                }
            }
             result++;
        }
    }
}

bool Reflect(int n){//镜像是关于中心的水平轴还是垂直轴?
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(Copy[i+n][n-j-1]!=Map[i][j]){
                return false;
            } 
        }
    }
    return true;
}

bool myself(){
    for (int i = 0; i < N;i++){//镜像
        for (int j = 0; j < N;j++){
           if(Map[i][j]!=Map[i+N][j]){
               return false;
           }
        }
    }
    return true;
}

int main(){
    ofstream fout("transform.out");
    ifstream fin("transform.in");
    result = 0;
    while(fin>>N){
        for (int i = 0; i < 2*N;i++){
            for (int j = 0; j < N;j++){
                fin >> Map[i][j];
                Copy[i][j] = Map[i][j];
            }
        }
        judge = false;
        for (int i = 0; i < N;i++){//上部分保存下部分
            for (int j = 0; j < N;j++){
                Copy[i][j] = Copy[i + N][j];
            }
        }
        doVans();
        if(judge==true){//是否能翻转完成
            fout << result << endl;
        }else{
            for (int i = 0; i < 2*N;i++){
                for (int j = 0; j < N;j++){
                    Copy[i][j] == Map[i][j];
                }
            }
            judge = Reflect(N);
            if(judge==true){
                fout << 5 << endl;
            }else{
                for (int i = 0; i < N;i++){//上部分保存下部分
                    for (int j = 0; j < N;j++){
                        Copy[i][j] = Copy[i + N][j];
                    }
                }
                for (int i = 0; i < N;i++){//镜像
                    for (int j = 0; j < N;j++){
                        Copy[i+N][j] = Copy[i][N-j-1];
                    }
                }
                doVans();
                if(judge==true){//是否能翻转完成
                    fout << 5 << endl;
                }
                else{
                    judge = myself();
                    if(judge==true){//是否能翻转完成
                        fout << 6 << endl;
                    }else{
                        fout << 7 << endl;
                    }
                }
            }
        }
        
    }
}
*/
char p[15][15];  
char q[15][15];  
int  n;  
ofstream fout("transform.out");
ifstream fin("transform.in");
int check1(){  
    for(int i = 0; i < n; ++i)  
        for(int j = 0; j < n; ++j)  
            if(p[n - j - 1][i] != q[i][j])  
                return 0;  
    return 1;  
}  
  
int check2(){  
    for(int i = 0; i < n; ++i)  
    {  
        for(int j = 0; j < n; ++j)  
        {  
            if(p[n - i - 1][n - j - 1] != q[i][j])  
                return 0;  
        }  
    }  
    return 1;  
}  
  
int check3(){  
    for(int i = 0; i < n; ++i)  
    {  
        for(int j = 0; j < n; ++j)  
        {  
            if(p[j][n - i - 1] != q[i][j])  
                return 0;  
        }  
    }  
    return 1;  
}  
  
int check4(){  
    for(int i = 0; i < n; ++i)  
    {  
        for(int j = 0; j < n; ++j)  
        {  
            if(p[i][n - j - 1] != q[i][j])  
                return 0;  
        }  
    }  
    return 1;  
}  
  
int check5(){  
    char h[15][15];  
    bool flag = 1;  
    for(int i = 0; i < n; ++i)  
        for(int j = 0; j < n; ++j)  
            h[i][j] = p[i][n - j - 1];  
    for(int i = 0; i < n; ++i)  
        for(int j = 0; j < n; ++j){  
            if(p[i][j] != q[i][j])  
                flag = 0;  
            p[i][j] = h[i][j];  
        }  
    if(check1())  
    {  
        fout << 5 << endl;  
        return 1;  
    }  
    if(check2())  
    {  
        fout << 5 << endl;  
        return 1;  
    }  
    if(check3())  
    {  
        fout << 5 << endl;  
        return 1;  
    }  
    if(flag)  
    {  
        fout << 6 << endl;  
        return 1;  
    }  
    return 0;  
}  
  
/*int check6(){ 
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) 
            if(p[i][j] != q[i][j]) 
                return 0; 
    return 1; 
    }*/  
  
  
int main(){  
    while(fin >> n)  
    {  
        for(int i = 0; i < n; ++i)  
            fin >> p[i];  
        for(int i = 0; i < n; ++i)  
            fin >> q[i];  
        if(check1())  
            fout << 1 << endl;  
        else if(check2())  
            fout << 2 << endl;  
        else if(check3())  
            fout << 3 << endl;  
        else if(check4())  
            fout << 4 << endl;  
        else if(check5()) ;  
            //  fout << 5 << endl;  
        /*  else if(check6()) 
            fout << 6 << endl;*/  
        else  
            fout << 7 << endl;  
    }  
    return 0;  
}  