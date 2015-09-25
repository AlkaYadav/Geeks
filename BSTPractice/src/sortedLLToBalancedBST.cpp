/*

 * sortedLLToBalancedBST.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<queue>
#include<map>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct LLNode{
	int data;
	struct LLNode* next;
};

struct Node* newNode(int data){
	struct Node* new_n=(struct Node* )malloc(sizeof(struct Node));
	new_n->data=data;
	new_n->left=NULL;
	new_n->right=NULL;
	return new_n;
}

struct LLNode* newNodeLL(int data){
	struct LLNode*  new_n=(struct LLNode* )malloc(sizeof(struct LLNode));
		new_n->data=data;
		new_n->next=NULL;

		return new_n;
}

struct Node* convertSortedLLToBalancedBST(struct LLNode* &head,int n){
	if(head==NULL){
		return NULL;
	}
	if(n<=0){
		return NULL;
	}
	struct Node* left=convertSortedLLToBalancedBST(head,n/2);
	struct Node* root=newNode(head->data);
	root->left=left;
	head=head->next;
	root->right=convertSortedLLToBalancedBST(head,n-n/2-1);
	return root;
}

void inorder(struct Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main(){
	struct LLNode* head = NULL;

	     Let us create a sorted linked list to test the functions
	     Created linked list will be 1->2->3->4->5->6->7
	head=newNodeLL(1);
	head->next=newNodeLL(2);
	head->next->next=newNodeLL(3);
	head->next->next->next=newNodeLL(4);
	head->next->next->next->next=newNodeLL(5);
	head->next->next->next->next->next=newNodeLL(6);
	head->next->next->next->next->next->next=newNodeLL(7);

	struct Node* root=convertSortedLLToBalancedBST(head,7);
	inorder(root);
}

*/
