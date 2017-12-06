#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
#define MAX 100

const int MEMORY = 1024;
const int TAPE = 5;

struct JCB{
    string userName;
    string jobName;
    string status;
    int startTime;
	int runTime;
	int endTime;
    int turnTime;
    int memory;   //内存
    int tape;   //磁带
    JCB *next;
    JCB &operator=(JCB &a){//重载
        this->userName = a.userName;
        this->jobName = a.jobName;
        this->status = a.status;
        this->startTime = a.startTime;
        this->runTime = a.runTime;
        this->turnTime = a.turnTime;
        this->endTime = a.endTime;
        this->memory = a.memory;
        this->tape = a.tape;
        this->next = a.next;
    }
};

JCB *head = NULL;
void input(int N){
    JCB *currentJob = new JCB;
    head->next = currentJob;
    cout << "用户名：";
    cin >> currentJob->userName;

    cout << "作业名：";
    cin >> currentJob->jobName;

    cout << "到达时间：";
    cin >> currentJob->startTime;

    cout << "运行时间：";
    cin >> currentJob->runTime;

    cout << "内存：";
    cin >> currentJob->memory;

    cout<<"磁带：";
    cin >> currentJob->tape;
    currentJob->next = NULL;
    while(N-1>0){
        while(currentJob->next!=null){
            currentJob = currentJob->next;
        }
        JCB *newJob = new JCB;

        cout << "用户名：";
        cin >> newJob->userName;

        cout << "作业名：";
        cin >> newJob->jobName;

        cout << "到达时间：";
        cin >> newJob->startTime;

        cout << "运行时间：";
        cin >> newJob->runTime;

        cout << "内存：";
        cin >> newJob->memory;

        cout<<"磁带：";
        cin >> newJob->tape;
        
        currentJob->next = newJob;
        newJob->next = NULL;
    }
}

void FCFS(){//先来先服务
    JCB *currentJob = head->next;
    JCB *nHead = NULL;
    while(currentJob->next!=NULL){//按startTime排序
    }


    currentJob->turnTime = currentJob->runTime;
    currentJob->endTime = currentJob->startTime + currentJob->turnTime;
    while(currentJob->next!=NULL){
        JCB *lastJob = currentJob;
        currentJob = currentJob->next;
        if(currentJob->startTime>lastJob->endTime){
            currentJob->turnTime = currentJob->runTime;
            currentJob->endTime = lastJob->endTime + currentJob->turnTime;
        }
        else{
            currentJob->turnTime = lastJob->endTime + currentJob->runTime - currentJob->startTime;
            currentJob->endTime = lastJob->endTime + currentJob->turnTime;
        }
    }
}