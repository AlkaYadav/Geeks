/*

 * removeNodesLessThank.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: user



#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<vector>
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

struct Node* removeNodesPathLessThanK(struct Node* root,int k,int len){
	if(root==NULL){
		return NULL;
	}
	root->left=removeNodesPathLessThanK(root->left,k,len+1);
	root->right=removeNodesPathLessThanK(root->right,k,len+1);
	if(len<k && root->left==NULL && root->right==NULL){
		return NULL;
	}
	return root;
}

void inorder(struct Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main() {
	struct Node* root=NULL;

	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->left->left->left=newNode(7);
	root->right->right=newNode(6);
	root->right->right->left=newNode(8);
	root=removeNodesPathLessThanK(root,4,1);
	cout<<"Inorder is "<<endl;
	inorder(root);
}


*/
