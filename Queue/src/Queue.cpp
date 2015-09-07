/*
//============================================================================
// Name        : Queue.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;

struct Queue{
	int front,rear;
	int capacity;
	int size;
	int *arr;
};

struct Queue* creatQueue(int capacity){
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->capacity=capacity;
	q->size=0;
	q->front=-1;
	q->rear=-1;
	q->arr=new int[capacity];
	return q;
}

bool isFull(struct Queue* q){
	if(q->rear==q->capacity-1 || q->front==q->rear+1){
		return true;
	}
	return false;
}

bool isEmpty(struct Queue* q){
	if(q->front==-1 && q->rear==-1){
		cout<<"Queue empty"<<endl;
		return true;
	}
	return false;
}
void enqueue(struct Queue* q,int data){
	if(!isFull(q)){
		if(q->rear==q->capacity-1){
			q->rear=0;
		}
		else q->rear++;
		q->arr[q->rear]=data;
		if(q->front==-1){
			q->front=0;
		}
	}
	else{
		cout<<"Queue Full.."<<endl;
	}
}

int dequeue(struct Queue* q){
	if(!isEmpty(q)){
		int item=q->arr[q->front];
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
		}
		else if(q->front==q->capacity-1){
			q->front=0;
		}
		else{
			q->front++;
		}

		return item;
	}
	return -1;
}


int main(){
	struct Queue *q=creatQueue(3);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	//cout<<"Dequeue..."<<dequeue(q)<<endl;
	enqueue(q,4);
	cout<<"Dequeue..."<<dequeue(q)<<endl;
	cout<<"Dequeue..."<<dequeue(q)<<endl;
	cout<<"Dequeue..."<<dequeue(q)<<endl;
}
*/
