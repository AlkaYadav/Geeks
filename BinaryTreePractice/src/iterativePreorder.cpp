/*

 * iterativePreorder.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<stack>
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

void iterativePreorder(struct Node* root){
	struct Node* current=root;
	stack<struct Node* > s;
	if(root==NULL){
		return;
	}
	while(true){
		if(current){
			cout<<current->data<<" ";
			s.push(current);
			current=current->left;
		}
		else{
			if(!s.empty()){
				struct Node* top=s.top();
				s.pop();
				current=top->right;
			}
			else{
				break;
			}
		}
	}
}

int main(){
	struct Node *root = newNode(10);
	root->left        = newNode(8);
	  root->right       = newNode(2);
	  root->left->left  = newNode(3);
	  root->left->right = newNode(5);
	  root->right->left = newNode(2);
	  iterativePreorder(root);
}

*/
