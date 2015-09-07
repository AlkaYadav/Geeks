/*
 * getMidStack.cpp
 *
 *  Created on: Aug 20, 2015
 *      Author: user
 */

#include<iostream>
#include<stdlib.h>
using namespace std;

//Design a stack with operations on middle element

struct DLLNode{
	struct DLLNode* next;
	struct DLLNode* prev;
	int data;
};
struct Stack{
	struct DLLNode* head;
	struct DLLNode* mid;
	int count;
};

struct Stack* createStack(){
	struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack));
	st->count=0;
	st->head=NULL;
	st->mid=NULL;
	return st;
}

struct DLLNode* createNode(int data){
	struct DLLNode* dllnode=(struct DLLNode* )malloc(sizeof(struct DLLNode));
	dllnode->next=NULL;
	dllnode->prev=NULL;
	dllnode->data=data;
	return dllnode;
}
void push(struct Stack* s,int data){
	if(s->head==NULL){
		s->head=createNode(data);
		s->count=1;
		s->mid=s->head;
	}
	else{
		struct DLLNode* dllnode=createNode(data);
		dllnode->next=s->head;
		s->head->prev=dllnode;
		s->head=dllnode;
		s->count+=1;
		if(s->count&1){
			s->mid=s->mid->prev;
		}
	}
}

int pop(struct Stack* s){
	if(s->head==NULL){
		return -1;
	}
	else{
		struct DLLNode* dllnode=s->head;
		s->head=s->head->next;
		int data=dllnode->data;
		free(dllnode);
		s->count--;
		if(s->count%2==0){
			s->mid=s->mid->next;
		}
		return data;
	}
}


int main(){
	struct Stack* s=createStack();
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	//push(s,5);
	//cout<<pop(s)<<endl;;
	cout<<"Middle is "<<s->mid->data<<endl;
}

