/*

 * segregateEvenOdd.cpp
 *
 *  Created on: Sep 10, 2015
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
void segregateEvenOdd(struct Node** head){
	struct Node* curr=*head;
	struct Node* tmp=curr;
	struct Node* next;
	struct Node* end=curr;
	struct Node* end_new;
	while(end->next){
		end=end->next;
	}
	end_new=end;
	while(curr!=end&& (curr->data)%2!=0){
		end_new->next=curr;
		end_new=end_new->next;
		curr=curr->next;
		end_new->next=NULL;
	}
	if(curr->data%2==0){
		*head=curr;
	}
	tmp=curr;
	curr=curr->next;
	while(curr!=end){
		if(curr->data%2!=0){
			next=curr->next;
			tmp->next=curr->next;
			end_new->next=curr;
			curr->next=NULL;
			end_new=curr;
			curr=next;
		}
		else{
			tmp=curr;
			curr=curr->next;
		}

	}

	if(curr->data%2!=0){
		tmp->next=curr->next;

		end_new->next=curr;
		end_new->next->next=NULL;
		end_new=end_new->next;
	}
	struct Node* new_head=*head;
	while(new_head!=end_new){
		cout<<new_head->data<<" ";
		new_head=new_head->next;
	}
}

int main(){
	struct Node* head=NULL;
	for(int i=0;i<8;i++){
		insertAtFront(&head,i);
	}
	insertAtFront(&head,11);
	cout<<"Before calling printing..."<<endl;
	printList(head);
	segregateEvenOdd(&head);
	cout<<"Printing LIST..."<<endl;
	printList(head);
}

*/
