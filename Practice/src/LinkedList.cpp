/*

 * LinkedList.cpp
 *
 *  Created on: Sep 9, 2015
 *      Author: user

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};

Node* newNode(int data){
	struct Node* tmp=(struct Node*)malloc(sizeof(struct Node));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}
void insertAtFront(struct Node** head,int data){
	if(*head==NULL){
		*head=newNode(data);

	}
	else{
		Node*tmp=newNode(data);
		tmp->next=*head;
		*head=tmp;
	}
}

int count(struct Node* head){
if(head==NULL){
	return 0;
}
return 1+count(head->next);
}

void deleteGivenNode(struct Node** given_ptr){
	struct Node* next_node=(*given_ptr)->next;
	if(next_node){
		(*given_ptr)->data=next_node->data;
		(*given_ptr)->next=next_node->next;

		free(next_node);
	}
	else{

		*given_ptr=NULL;
		free(*given_ptr);

	}
}

void printMiddle(struct Node* head){
	struct Node* slow_ptr=head;
	struct Node* fast_ptr=head;
	while(fast_ptr && fast_ptr->next){
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
	}
	cout<<slow_ptr->data<<endl;
}

void reverse_Iterative(struct Node** head){
	struct Node* prev=NULL;
	struct Node* tmp=*head;
	struct Node* next;
	while(tmp){
		next=tmp->next;
		tmp->next=prev;
		prev=tmp;
		tmp=next;
	}
	*head=prev;
}

void reverse_recursive(struct Node** head,struct Node* current,struct Node* prev){
	if(current->next==NULL){
		*head=current;
		current->next=prev;
		return;
	}

	struct Node* next=current->next;
	current->next=prev;
	prev=current;
	reverse_recursive(head,next,prev);
}
int main(){
	struct Node* head=NULL;
	for(int i=0;i<8;i++){
		insertAtFront(&head,i);
	}
	insertAtFront(&head,11);
	cout<<count(head)<<endl;
	struct Node* dele_node=head->next->next->next->next;
	deleteGivenNode(&dele_node);
	printMiddle(head);
	//reverse_Iterative(&head);
	reverse_recursive(&head,head,NULL);
	while(head){
			cout<<head->data<<" ";
			head=head->next;
		}
}
*/
