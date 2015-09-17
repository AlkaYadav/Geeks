/*

 * MergeSortedLists.cpp
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
void printList(struct Node* head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void merge(struct Node* list1,struct Node* list2){
	struct Node* target;
	if(list1->data<=list2->data){
		target=list1;
		list1=list1->next;
	}
	else{
		target=list2;
		list2=list2->next;
	}
	printList(target);

	struct Node* copy=target;

	while(list1&& list2){
		cout<<"in list "<<endl;
		if(list1->data<=list2->data){

			target->next=list1;
			target=target->next;
			list1=list1->next;
		}
		else if(list2->data<list1->data){

			target->next=list2;
			target=target->next;
			list2=list2->next;
		}
	}

	if(list1){
		target->next=list1;
	}
	else if(list2){
		target->next=list2;
	}
	else{
		target->next=NULL;
	}

	while(copy){
		cout<<copy->data<<" ";
		copy=copy->next;
	}
}

int main(){
	struct Node* head1=NULL;
	for(int i=5;i>=0;i--){
		insertAtFront(&head1,i);
	}
	struct Node* head2=NULL;
		for(int i=5;i>=0;i--){
			insertAtFront(&head2,i+1);
		}
		printList(head1);
		printList(head2);
		cout<<"Insert done.."<<endl;
		merge(head1,head2);
}
*/
