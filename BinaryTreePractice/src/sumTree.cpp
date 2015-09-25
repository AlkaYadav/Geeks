/*

 * sumTree.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<vector>
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

int convert(struct Node* root){
	if(root==NULL){
		return 0;
	}
	int old_data=root->data;
	int ls=convert(root->left);
	int rs=convert(root->right);
	root->data=ls+rs;
	return old_data+ls+rs;
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
	root=newNode(10);
	root->left = newNode(-2);
	  root->right = newNode(6);
	  root->left->left = newNode(8);
	  root->left->right = newNode(-4);
	  root->right->left = newNode(7);
	  root->right->right = newNode(5);
	  convert(root);
	  inorder(root);
}
*/
