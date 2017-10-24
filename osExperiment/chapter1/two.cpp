#include <unistd.h>
#include <iostream>
using namespace std;

//在每个进程中使用for循环语句输出

int main()
{
	pid_t fpid;     //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
	if(fpid < 0)
		cout<<"error in fork!"<<endl;
	else if(fpid == 0){
        for (int i = 0; i < 3;i++){
            cout << "i'm the child" << i <<"| id is "<<getpid()<< endl;
        }
        count++;
    }
	else{
        for (int i = 0; i < 3;i++){
            cout << "i'm the parent" << i <<"| id is "<<getpid()<< endl;
        }
        count++;
    }
	cout<<"统计结果是："<<count<<endl;
	
	return 0;
}
