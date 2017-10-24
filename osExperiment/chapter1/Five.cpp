#include <unistd.h>
#include <iostream>
using namespace std;

//使用lockf()来给进程加锁，实现进程的互斥
//加在循环体内

int main()
{
	pid_t fpid;     //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
    if(fpid < 0)
		cout<<"error in fork!"<<endl;
	else if(fpid == 0){
        for (int i = 0; i < 3;i++){
            lockf(1, 1, 0);
            cout << "i'm the child" << i <<"| id is "<<getpid()<< endl;
            lockf(1, 0, 0);
        }
        count++;
    }
	else{
        for (int i = 0; i < 3;i++){
            lockf(1, 1, 0);
            cout << "i'm the parent" << i <<"| id is "<<getpid()<< endl;
            lockf(1, 0, 0);
        }
        count++;
    }
	cout<<"统计结果是："<<count<<endl;
	
	return 0;
}
