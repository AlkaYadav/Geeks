/*

 * constructCompleteFromLL.cpp
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


struct Node* newNode(int data){
	struct Node* new_n=(struct Node* )malloc(sizeof(struct Node));
	new_n->data=data;
	new_n->left=NULL;
	new_n->right=NULL;
	return new_n;
}

struct LLNode{
	int data;
	struct LLNode* next;
};
struct LLNode* newLLNode(int data){
	struct LLNode* new_n=(struct LLNode* )malloc(sizeof(struct LLNode));
	new_n->data=data;
	new_n->next=NULL;

	return new_n;
}



void constructCompleteBTFromLL(struct LLNode* head,struct Node*& root){
	queue<struct Node*> q;
	if(head==NULL){
		return;
	}
	q.push(newNode(head->data));

	while(!q.empty()){
		struct Node* top=q.front();
		if(root==NULL){
			root=top;
		}
		q.pop();
		if(head->next){
			struct Node* tmp=newNode(head->next->data);
			top->left=tmp;
			q.push(tmp);
			head=head->next;
		}
		if(head->next){
			struct Node* tmp2=newNode(head->next->data);
			top->right=tmp2;
			q.push(tmp2);
			head=head->next;
		}

	}
}


void inorder(struct Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main()
{
    // create a linked list shown in above diagram
    struct LLNode* head = NULL;
    struct Node* root=NULL;
    head=newLLNode(36);   Last node of Linked List
    head->next=newLLNode(30);
    head->next->next=newLLNode(25);
    head->next->next->next=newLLNode(15);
    head->next->next->next->next=newLLNode(12);
    head->next->next->next->next->next=newLLNode(10);
    constructCompleteBTFromLL(head,root);
    inorder(root);
}


*/
