/*

 * removeHalfNodes.cpp
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

void inorder(struct Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

struct Node* removeHalfNodes(struct Node* root){
	if(root==NULL){
		return NULL;
	}

	root->left=removeHalfNodes(root->left);
	root->right=removeHalfNodes(root->right);
	if((root->left==NULL && root->right)){
			struct Node* r=root->right;
			delete root;
			return r;
		}
		if((root->left && root->right==NULL)){
			struct Node* l=root->left;
				delete root;
				return l;
			}
	return root;
}


int main() {
	struct Node* root=NULL;

	root=newNode(2);
	root->left=newNode(7);
	root->right=newNode(5);

	root->left->right=newNode(6);
	root->left->right->left=newNode(1);
	root->left->right->right=newNode(11);
	root->right->right=newNode(9);
	root->right->right->left=newNode(4);

	root=removeHalfNodes(root);
	cout<<"Inorder is "<<endl;
	inorder(root);
}

*/
