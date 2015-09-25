/*

 * morrisPreorder.cpp
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

void morrisPreorder(struct Node* root){
	struct Node* current=root;
	struct Node* pred=NULL;
	while(current){
		if(current->left){
			pred=current->left;
			while(pred->right && pred->right!=current){
				pred=pred->right;
			}
			if(pred->right==NULL){
				pred->right=current;
				cout<<current->data<<" ";
				current=current->left;
			}
			else if(pred->right==current){
				pred->right=NULL;
				current=current->right;
			}
		}
		else{
			cout<<current->data<<" ";
			current=current->right;
		}
	}
}

int main() {
	struct Node* root=NULL;

	root = newNode(1);
	    root->left = newNode(2);
	    root->right = newNode(3);

	    root->left->left = newNode(4);
	    root->left->right = newNode(5);

	    root->right->left = newNode(6);
	    root->right->right = newNode(7);

	    root->left->left->left = newNode(8);
	    root->left->left->right = newNode(9);

	    root->left->right->left = newNode(10);
	    root->left->right->right = newNode(11);

	    morrisPreorder(root);
}
*/
