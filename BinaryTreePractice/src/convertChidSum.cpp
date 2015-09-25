/*

 * convertChidSum.cpp
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

void increment(struct Node* root,int diff){
	if(root){
		root->data+=diff;
		if(root->left){
			increment(root->left,diff);
		}
		else if(root->right){
			increment(root->right,diff);
		}
	}
}
void convertChildSum(struct Node* root){
	if(root==NULL){
		return ;
	}
	if(root->left==NULL&& root->right==NULL){
		return ;
	}
	convertChildSum(root->left);
	convertChildSum(root->right);
	int ls=root->left==NULL?0:root->left->data;
	int rs=root->right==NULL?0:root->right->data;
	int diff=ls+rs-root->data;
	if(diff>=0){
		root->data=ls+rs;
	}
	if(diff<0){
		increment(root,-diff);
	}

}


*/
