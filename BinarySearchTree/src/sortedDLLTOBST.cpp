/*

 * sortedDLLTOBST.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* newNode(int data){
	struct node* newinsnode=(struct node*)malloc(sizeof(struct node));
	newinsnode->data=data;
	newinsnode->next=NULL;
	newinsnode->prev=NULL;
	return newinsnode;
}


struct node* sortedDLLToBST(struct node* &head,int n){
	struct node* root;
	if(head==NULL||n<=0){
		return NULL;
	}

	struct node* left=sortedDLLToBST(head,n/2);

	root=head;
	root->prev=left;
	head=head->next;
	root->next=sortedDLLToBST(head,n-1-n/2);
	return root;
}

void inorder(struct node* root){
	if(root){
		inorder(root->prev);
		cout<<root->data<<" ";
		inorder(root->next);
	}

}
int main(){
	struct node* head=NULL;
	struct node* node1,*node2=NULL;
	head=newNode(1);
	node1=newNode(2);
	head->next=node1;
	node1->prev=head;

	node2=newNode(3);
		head->next->next=node2;
		node2->prev=head->next;
	head=sortedDLLToBST(head,3);
	inorder(head);
}


*/
