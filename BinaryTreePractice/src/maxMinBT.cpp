/*

 * maxMinBT.cpp
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

void findmaxMinBT(struct Node* root,int& min ,int& max){
	if(root==NULL){
		return;
	}

	if(root->data<min){
		min=root->data;
	}
	if(root->data>max){
		max=root->data;
	}
	findmaxMinBT(root->left,min,max);
	findmaxMinBT(root->right,min,max);
}

int main() {
	struct Node* root=NULL;

	root=newNode(20);
	root->left=newNode(8);
	root->right=newNode(22);
	root->left->left=newNode(4);
	root->left->right=newNode(12);
	root->left->right->left=newNode(10);
	root->left->right->right=newNode(14);
	int min=INT_MAX;
	int max=INT_MIN;

	findmaxMinBT(root,min,max);
	cout<<"Min is "<<min<<endl;
	cout<<"Min is "<<max<<endl;
}

*/
