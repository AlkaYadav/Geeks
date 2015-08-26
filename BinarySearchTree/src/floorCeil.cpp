/*
 * floorCeil.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: user
 */

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	struct node* newinsnode=(struct node*)malloc(sizeof(struct node));
	newinsnode->data=data;
	newinsnode->left=NULL;
	newinsnode->right=NULL;
	return newinsnode;
}

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int ceil(struct node* root,int data){
	if(root==NULL){
		return -1;
	}
	if(data==root->data){
		return data;
	}
	if(data>root->data){
		return ceil(root->right,data);
	}

		int c= ceil(root->left,data);
		return c>=data?c:root->data;
}

int main(){
	node *root = newNode(8);

	    root->left = newNode(4);
	    root->right = newNode(12);

	    root->left->left = newNode(2);
	    root->left->right = newNode(6);

	    root->right->left = newNode(10);
	    root->right->right = newNode(14);

	    for(int i = 0; i < 16; i++)
	        cout<<i<<"  "<<ceil(root, i)<<endl;

	        return 0;
}

