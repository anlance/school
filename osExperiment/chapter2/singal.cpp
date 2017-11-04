#include<unistd.h>
#include<iostream>
#include<stdio.h>
#include<signal.h>
using namespace std;

int ctrl_c_count = 0;
void (*old_handler)(int);

/*对SIGINT信号的处理*/
void ctrl_c(int signum){
    (void)signal(SIGINT, ctrl_c);
    ++ctrl_c_count;
}

int main(){
    int c;
    /*设置ctrl+c产生的信号SIGINT的处理程序为ctrl+c，取代系统原来默认的处理程序*/
    old_handler = signal(SIGINT, ctrl_c);   
    /*不断输入字符，并且同时按多次ctrl+c，直到回车结束*/
    while((c=getchar())!='\n')
        ;
    cout << "ctrl_c_cout = " << ctrl_c_count << endl;
    /*设置信号处理程序为原来的处理程序*/
    (void) signal(SIGINT,old_handler);
    /*不断输入字符，ctrl+c结束*/
    while((c=getchar())!='\n')
        ;
    return 0;
}