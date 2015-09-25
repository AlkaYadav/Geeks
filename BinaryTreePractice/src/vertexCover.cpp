/*

 * vertexCover.cpp
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

int vertexCover(struct Node* root){
	if(root==NULL){
		return 0;
	}
	int incl=1+vertexCover(root->left)+vertexCover(root->right);

	int excl=0;
	if(root->left){
		excl+=1+vertexCover(root->left->left)+vertexCover(root->left->right);
	}
	if(root->right){
		excl+=1+vertexCover(root->right->left)+vertexCover(root->right->right);
	}
	return min(incl,excl);
}

int main() {
	struct Node* root=NULL;

	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->left->right->left=newNode(7);
	root->left->right->right=newNode(9);
	root->right->right=newNode(6);


	cout<<"Vertex cover is "<<vertexCover(root);
}



*/
