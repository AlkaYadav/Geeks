/*

 * reverseInGroups.cpp
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
struct Node* reverseInKGroups(struct Node** head,int k){
	struct Node* current=*head;
	struct Node* prev=NULL;
	struct Node* next=NULL;
	int count=0;

		while(count<k && current){
			cout<<"Head data is "<<(*head)->data<<endl;
			printList(*head);
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;
			count++;
		}
		if(next!=NULL){
	(*head)->next=reverseInKGroups(&current,k);
		}
	return prev;
}

int main(){
	struct Node* head=NULL;
	for(int i=0;i<11;i++){
		insertAtFront(&head,i);
	}

	head=reverseInKGroups(&head,3);
	cout<<"Head data returned is "<<head->data<<endl;
	printList(head);

}

*/
