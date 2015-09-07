/*

 * QueueLinkedList.cpp
 *
 *  Created on: Aug 20, 2015
 *      Author: user


#include<iostream>
#include<stdlib.h>
using namespace std;

struct DLLNode{
	int data;
	struct DLLNode* next;
	struct DLLNode* prev;
};

struct DLLNode* createNode(int data){
	struct DLLNode* newNode=(struct DLLNode* )malloc(sizeof(struct DLLNode));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
struct Queue{
	struct DLLNode* front;
	struct DLLNode* rear;
};

void enqueue(struct Queue* &q,int data){
	struct DLLNode* newNode=createNode(data);
	if(q->rear==NULL){
		q->rear=newNode;
		q->front=q->rear;
	}
	else{
		q->rear->next=newNode;
		newNode->prev=q->rear;
		q->rear=newNode;
	}
}

int dequeue(struct Queue* &q){
	if(q->front==NULL){
		cout<<"Queue empty"<<endl;
	}
	else if(q->front->next==NULL){
		struct DLLNode* node=q->front;
		int data=node->data;
		free(node);
		q->front=NULL;
		q->rear=NULL;
		return data;
	}
	else{
		struct DLLNode* node=q->front;
		int data=node->data;
		q->front=q->front->next;
		free(node);
		return data;
	}
	return -1;
}

int main(){
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=NULL;
	q->rear=NULL;
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
	return 0;
}


*/
