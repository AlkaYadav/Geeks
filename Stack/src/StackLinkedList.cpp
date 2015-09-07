/*

 * StackLinkedList.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user


//Implement stack using linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
struct stackNode{
	int data;
	struct stackNode* next;
};

struct stackNode* newNode(int data){
	struct stackNode* newnode=(struct stackNode*)malloc(sizeof(struct stackNode));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void push(struct stackNode*& head,int data){
	if(head==NULL){
		head=newNode(data);
	}
	else{
		struct stackNode* tmp=head;
		head=newNode(data);
		head->next=tmp;
	}
}

int pop(struct stackNode*& head){
	if(head==NULL){
		return -1;
	}
	else{
		struct stackNode* tmp=head;
		int data=tmp->data;
		head=head->next;
		free(tmp);
		return data;
	}
}

int top(struct stackNode* head){
	if(head==NULL){
			return -1;
		}
	else{
		return head->data;
	}
}

int main(){
	struct stackNode* head=NULL;
	push(head,1);
	cout<<"Top "<<top(head)<<endl;
	push(head,1);
	cout<<"Top "<<top(head)<<endl;
	push(head,2);
	cout<<"Top "<<top(head)<<endl;
	push(head,3);
	cout<<"Top "<<top(head)<<endl;

}
*/
