#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct PCB {
	char name[2];
	int priority;
	int acquiretime;
	char status;
	PCB *next;
};//定义PCB的五种属性

PCB Head;
Head.next = NULL;
void Insert(PCB a){
    if (Head.next == NULL){
        a.next = NULL;
        Head.next = a;
    }else{
        PCB temp = Head.next;
        PCB tem2;//保留上一个
        while(a.priority<temp.priority&&temp.next!=NULL){
            temp2 = temp;
            temp = temp.next;
        }
        if(temp.next==NULl){
            a.next = NULL;
            temp.next = a;
        }else{
            a.next = temp;
            temp2.next = a;
        }
    }
}