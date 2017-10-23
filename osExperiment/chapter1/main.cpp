#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	pid_t fpid;     //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
	if(fpid < 0)
		cout<<"error in fork!"<<endl;
	else if(fpid == 0){
		cout<<"im a child process, my process id is "<<getpid()<<endl;
		count++;	
	}
	else{
		cout<<"i am the parent process, my process id is"<<getpid()<<endl;
		count++;
	}
	cout<<"统计结果是："<<count<<endl;
	
	return 0;
}
