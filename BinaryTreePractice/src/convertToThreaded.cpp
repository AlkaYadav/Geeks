/*

 * convertToThreaded.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user



#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	bool isThreaded;
};

struct Node* newNode(int data){
	struct Node* new_n=(struct Node* )malloc(sizeof(struct Node));
	new_n->data=data;
	new_n->left=NULL;
	new_n->right=NULL;
	new_n->isThreaded=false;
	return new_n;
}

struct Node* leftMost(struct Node* root){
	while(root && root->left){
		root=root->left;
	}
	return root;
}
void inorderThreadedBT(struct Node* root){
	struct Node* curr=leftMost(root);
	while(curr){
		cout<<curr->data<<" ";

			if(curr->isThreaded){
				curr=curr->right;
			}
			else{
				curr=leftMost(curr->right);
			}

	}
}
void convertToThreaded(struct Node* root){
	static struct Node* prev=NULL;
	if(root==NULL){
		return;
	}
	convertToThreaded(root->right);
	if(root->right==NULL)
	{
		if(root->data==6){
			cout<<"Prev is "<<prev->data<<endl;
		}
	root->right=prev;
	root->isThreaded=true;
	}
	prev=root;
	convertToThreaded(root->left);
}

void inorder(struct Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main() {
	struct Node* root=NULL;
	root=newNode(1);
	root->left = newNode(2);
	    root->right = newNode(3);
	    root->left->left = newNode(4);
	    root->left->right = newNode(5);
	    root->right->left = newNode(6);
	    root->right->right = newNode(7);
	    inorder(root);
	    cout<<endl;
	    convertToThreaded(root);
	    inorderThreadedBT(root);

}
*/
