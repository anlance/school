#include <unistd.h>
#include <iostream>
using namespace std;

//使用lockf()来给进程加锁，实现进程的互斥

int main()
{
	pid_t fpid;     //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
    if(fpid < 0)
		cout<<"error in fork!"<<endl;
	else if(fpid == 0){
        lockf(1, 1, 0);
        for (int i = 0; i < 3;i++){
            cout << "i'm the child" << i <<"| id is "<<getpid()<< endl;
        }
        count++;
        lockf(1, 0, 0);
    }
	else{
        lockf(1, 1, 0);
        for (int i = 0; i < 3;i++){
            cout << "i'm the parent" << i <<"| id is "<<getpid()<< endl;
        }
        count++;
        lockf(1, 0, 0);
    }
	cout<<"统计结果是："<<count<<endl;
	
	return 0;
}
