/*

 * sumLeftLeaves.cpp
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

void sumLeftLeaves(struct Node* root,int& sum){
	if(root==NULL){
		return;
	}
	if(root->left){
		if(root->left->left==NULL && root->left->right==NULL){
			sum+=root->left->data;
		}
	}

	sumLeftLeaves(root->left,sum);
	sumLeftLeaves(root->right,sum);
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
	int sum=0;
	sumLeftLeaves(root,sum);
	cout<<"Sum is "<<sum<<endl;
}

*/
