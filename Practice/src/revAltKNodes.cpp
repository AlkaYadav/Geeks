/*

 * revAltKNodes.cpp
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
struct Node* revAltKNodes(struct Node* head,int k){
	struct Node* curr=head;
	struct Node* next=NULL;
	struct Node* prev=NULL;
	int cnt=0;
	while(curr&& cnt<k){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		cnt++;
	}

	if(head)
	head->next=curr;
	cnt=0;
	while(cnt<k-1&& curr){
		curr=curr->next;
		cnt++;
	}
	if(curr){
		curr->next=revAltKNodes(curr->next,k);
	}
return prev;
}
struct Node* reverse(struct Node** head){
	struct Node* current=*head;
	struct Node* prev=NULL;
	struct Node* next=NULL;
	int count=0;

		while(current){

			next=current->next;
			current->next=prev;
			prev=current;
			current=next;

		}

	return prev;
}
void deleteGreaterRightNodes(struct Node** head){
	*head=reverse(head);
	cout<<"List after reversing "<<endl;
	printList(*head);
	struct Node* tmp=*head;
	int maxnode=(*head)->data;
	tmp=(*head)->next;
	struct Node* prev=*head;
	while(tmp){
		if(tmp->data<maxnode){
			prev->next=tmp->next;
			struct Node* del=tmp;
			tmp=tmp->next;
			free(del);
		}
		else{
			maxnode=tmp->data;
			prev=tmp;
			tmp=tmp->next;
		}
	}

	*head=reverse(head);
}
int main(){
	struct Node* head=NULL;
	for(int i=0;i<8;i++){
		insertAtFront(&head,i);
	}
	insertAtFront(&head,1);
	cout<<"Original List "<<endl;
	printList(head);
	deleteGreaterRightNodes(&head);
	while(head){
			cout<<head->data<<" ";
			head=head->next;
		}
}
*/
