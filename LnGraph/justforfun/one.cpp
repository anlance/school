#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
#define MAX 100

const int MEMORY = 1024;
const int TAPE = 5;

struct JCB{
    char userName[5];
    char jobName[5];
    char status[5];
    int startTime;
	int runTime;
	int endTime;
    int turnTime;
    int memory;   //内存
    int tape;   //磁带
    double DQZZ_Time;//带权周转时间
    //JCB *next;
};

// typedef struct PCB{  
//     JCB *next;  
//     char state;//状态R-就绪E-结束,W-等待 
//     int order;  
// }PCB;//0资源不满足1主存满足条件2磁带满足条件3两种均满足条件 

JCB a[MAX];

void input(int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
        cout << "用户名：";
        cin >> a[i].userName;

        cout << "作业名：";
        cin >> a[i].jobName;

        cout << "到达时间：";
        cin >> a[i].startTime;

        cout << "运行时间：";
        cin >> a[i].runTime;

        cout << "内存：";
        cin >> a[i].save;

        cout<<"磁带：";
        cin >> a[i].tape;
    }
}


void FCFS(int n)//先来先服务
{
	int i, j, time1, time2;
	char temp[4];
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j<n - i - 1; j++)
			if (a[j].startTime>a[j + 1].startTime)
			{
				time1 = a[j].startTime;//开始时间进行互换
				a[j].startTime = a[j + 1].startTime;
				a[j + 1].startTime = time1;

				time2 = a[j].runTime;//CPU时间换
				a[j].runTime = a[j + 1].runTime;
				a[j + 1].runTime = time2;

                strcpy(temp, a[j].userName);   //把从src地址开始且含有'\0'结束符的字符串复制到以dst开始的地址空间。
				strcpy(a[j].userName, a[j + 1].userName);
				strcpy(a[j + 1].userName, temp);

				strcpy(temp, a[j].jobName);
				strcpy(a[j].jobName, a[j + 1].jobName);
				strcpy(a[j + 1].jobName, temp);
			}
	}
	for (i = 0; i<n; i++)
	{    
		if (i == 0)
		{//第一个进程   
			a[i].turnTime = a[i].runTime;
			a[i].endtime = a[i].startTime + a[i].turnTime;
		}
		else
		{
			if (a[i].startTime>a[i - 1].endtime)
			{
				a[i].turnTime = a[i].runTime;
				a[i].endtime = a[i].startTime + a[i].turnTime;
			}
			else
			{
				a[i].turnTime = a[i].runTime + a[i - 1].endtime - a[i].startTime;
				a[i].endtime = a[i].startTime + a[i].turnTime;
			}
		}
		a[i].DQZZ_Time = a[i].turnTime*1.0 / a[i].runTime;
	}
}

//最短作业优先，
void SJF(int n)
{
	int i, j, time1, time2;
	int b = 0, c = 0, d = 0;
	char temp[4];

	//先按到达时间排序
	for (i = 0; i<n - 1; i++)
	{
		for (j = 0; j<n - i - 1; j++)
			if (a[j].startTime>a[j + 1].startTime)
			{
				time1 = a[j].startTime;
				a[j].startTime = a[j + 1].startTime;
				a[j + 1].startTime = time1;

				time2 = a[j].runTime;
				a[j].runTime = a[j + 1].runTime;
				a[j + 1].runTime = time2;

				strcpy(temp, a[j].jobName);
				strcpy(a[j].jobName, a[j + 1].jobName);
				strcpy(a[j + 1].jobName, temp);
			}
	}

	a[0].endtime = a[0].startTime + a[0].runTime;

	for (i = 1; i<n; i++)
	{
		if (a[i].startTime<a[0].endtime)
			b++;      //作业到达但第0个作业还在运行时
					  //用b统计需等待作业0运行的作业个数
	}

	for (i = 1; i<b + 1; i++)
	{//已经到达的但要等待第0个作业运行完的作业按最短运行时间排序
		for (j = 1; j<b + 1 - 1; j++)
		{
			if (a[j].runTime>a[j + 1].runTime)
			{
				time1 = a[j].startTime;
				a[j].startTime = a[j + 1].startTime;
				a[j + 1].startTime = time1;
				time2 = a[j].runTime;
				a[j].runTime = a[j + 1].runTime;
				a[j + 1].runTime = time2;
				strcpy(temp, a[j].jobName);
				strcpy(a[j].jobName, a[j + 1].jobName);
				strcpy(a[j + 1].jobName, temp);
			}
		}
	}

	if (a[1].startTime>a[0].endtime) a[1].endtime = a[1].startTime + a[1].runTime;
	else a[1].endtime = a[0].endtime + a[1].runTime;

	for (i = 2; i<n; i++)
	{
		if (a[i].startTime<a[1].endtime)
			c++;      //作业到达但第1个作业还在运行时
					  //用c统计需等待作业1运行的作业个数
	}

	for (i = 2; i<c + 2; i++)
	{//已经到达的但要等待第1个作业运行完的作业按最短运行时间排序
		for (j = 2; j<c + 2 - 1; j++)
		{
			if (a[j].runTime>a[j + 1].runTime)
			{
				time1 = a[j].startTime;
				a[j].startTime = a[j + 1].startTime;
				a[j + 1].startTime = time1;
				time2 = a[j].runTime;
				a[j].runTime = a[j + 1].runTime;
				a[j + 1].runTime = time2;
				strcpy(temp, a[j].jobName);
				strcpy(a[j].jobName, a[j + 1].jobName);
				strcpy(a[j + 1].jobName, temp);
			}
		}
	}

	if (a[2].startTime>a[1].endtime) a[2].endtime = a[2].startTime + a[2].runTime;
	else a[2].endtime = a[1].endtime + a[2].runTime;

	for (i = 3; i<n; i++)
	{
		if (a[i].startTime<a[2].endtime)
			d++;      //作业到达但第2个作业还在运行时
					  //用d统计需等待作业2运行的作业个数
	}

	for (i = 3; i<d + 3; i++)
	{//已经到达的但要等待第2个作业运行完的作业按最短运行时间排序
		for (j = 3; j<d + 3 - 1; j++)
		{
			if (a[j].runTime>a[j + 1].runTime)
			{
				time1 = a[j].startTime;
				a[j].startTime = a[j + 1].startTime;
				a[j + 1].startTime = time1;
				time2 = a[j].runTime;
				a[j].runTime = a[j + 1].runTime;
				a[j + 1].runTime = time2;
				strcpy(temp, a[j].jobName);
				strcpy(a[j].jobName, a[j + 1].jobName);
				strcpy(a[j + 1].jobName, temp);
			}
		}
	}

	for (i = 0; i<n; i++)
	{
		if (a[i].startTime>a[i - 1].endtime)
		{
			a[i].endtime = a[i].startTime + a[i].runTime;
			a[i].turnTime = a[i].runTime;
		}
		else
		{
			a[i].endtime = a[i - 1].endtime + a[i].runTime;
			a[i].turnTime = a[i].endtime - a[i].startTime;
		}
		a[i].DQZZ_Time = a[i].turnTime*1.0 / a[i].runTime;
	}
}


void output(int n)
{

	int sum_Time = 0;//作业总周转时间
	double sum_DQ = 0;//作业总带权周转时间
	int i;
	printf("\tname  startTime  runTime  turnTime  endtime \tDQZZ_Time\n");
	for (i = 0; i<n; i++)
	{
		printf("%8s%10d%10d%10d%10d\t%10lf\n", a[i].jobName, a[i].startTime, a[i].runTime, a[i].turnTime, a[i].endtime, a[i].DQZZ_Time);
		sum_Time += a[i].turnTime;
		sum_DQ += a[i].DQZZ_Time;
	}
	printf("平均作业周转时间为:%.2lf\n", sum_Time*1.0 / n);
	printf("平均带权作业周转时间为:%.2lf\n", sum_DQ*1.0 / n);
	printf("\n");
}

int main()
{
	int n, i;
	printf("请输入进程数n:");
	scanf("%d", &n);
	input(n);
	output(n);
	while (1)
	{
		printf("1.先来先服务FCFS\n2.最短作业优先SJF\n3.最高响应比优先\n4.退出\n");
		scanf("%d", &i);
		if (i == 1)
		{
			printf("\t\t\t\t1.先来先服务FCFS\n");
			FCFS(n);
			output(n);
		}
		if (i == 2)
		{
			printf("\t\t\t\t2.最短作业优先SJF\n");
			SJF(n);
			output(n);
		}
		if (i == 3)
		{
			exit(0);
		}
	}
}