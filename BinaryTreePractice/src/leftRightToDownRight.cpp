/*

 * leftRightToDownRight.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<vector>
#include<queue>
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

void preorder(struct Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";


	preorder(root->right);
	preorder(root->left);
}

void convertLeftRightToDownRight(struct Node* root){
	if(root==NULL|| (root->left==NULL && root->right==NULL)){
		return ;
	}
	queue<struct Node*> q;
	q.push(root);
	struct Node* firstNode=root;

	while(!q.empty()){
		int tmp_size=q.size();
		struct Node* prev=NULL;

		while(tmp_size){
			struct Node* top=q.front();
			q.pop();
			if(top->left){
				q.push(top->left);
			}
			if(top->right){
				q.push(top->right);
			}

			if(prev==NULL){
				prev=top;
				firstNode->left=top;
				firstNode=top;
			}
			else{
				top->left=NULL;
				prev=top;
			}

			if(tmp_size==1){
				top->right=NULL;
			}
			else{
				struct Node* top1=q.front();
				top->right=top1;
			}
			tmp_size--;
		}
	}

	cout<<"Preorder is"<<endl;
	preorder(root);
}

int main() {
	struct Node* root=NULL;

	root=newNode(1);
	root->left = newNode(2);
	    root->right = newNode(3);
	    root->right->left = newNode(4);
	    root->right->right = newNode(5);
	    root->right->left->left = newNode(6);
	    root->right->right->left = newNode(7);
	    root->right->right->right = newNode(8);

	convertLeftRightToDownRight(root);
}

*/
