#include <unistd.h>
#include <iostream>
using namespace std;

//使用lockf()来给进程加锁，实现进程的互斥

int main()
{
	pid_t fpid;     //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
	if(fpid < 0){
        lockf(1, 1, 0);
        cout<<"error in fork!"<<endl;
        lockf(1, 0, 0);
    }
	else if(fpid == 0){
        lockf(1, 1, 0);
		cout<<"im a child process, my process id is "<<getpid()<<endl;
        count++;	
        lockf(1, 0, 0);
	}
	else{
        lockf(1, 1, 0);
		cout<<"i am the parent process, my process id is"<<getpid()<<endl;
        count++;
        lockf(1, 0, 0);
	}
	cout<<"统计结果是："<<count<<endl;
	
	return 0;
}
