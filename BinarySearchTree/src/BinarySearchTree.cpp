//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

struct Node* search(struct Node* root,int data){
	if(root==NULL){
		return NULL;
	}
	if(data==root->data){
		return root;
	}
	else if(data<root->data){
		return search(root->left,data);
	}
	else
		return search(root->right,data);
}
struct Node* newNode(int data){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->data=data;
	return newnode;
}
struct Node*  insert(struct Node* root,int data){
	if(root==NULL){
		return newNode(data);
	}
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	else if(data>root->data)
		root->right=insert(root->right,data);
	return root;
}

void inorder(struct Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

//Lowest Common Ancestor
struct Node* lca(struct Node* root,int n1,int n2){
	if(root==NULL)
		return NULL;
	if(root->data>n1 && root->data>n2){
		return lca(root->left,n1,n2);
	}
	if(root->data<n1 && root->data<n2){
			return lca(root->right,n1,n2);
	}
	return root;
}

int main() {
	struct Node* root=NULL;
	root=insert(root,20);
	root->left               = newNode(8);
	root->right              = newNode(22);
	root->left->left         = newNode(4);
	root->left->right        = newNode(12);
	root->left->right->left  = newNode(10);
	root->left->right->right = newNode(14);
	inorder(root);
	struct Node* l=lca(root,10,22);
	cout<<"LCA is "<<l->data;
	return 0;
}
