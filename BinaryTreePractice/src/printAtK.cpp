/*

 * printAtK.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newnode(int data){
	struct Node* new_n=(struct Node* )malloc(sizeof(struct Node));
	new_n->data=data;
	new_n->left=NULL;
	new_n->right=NULL;
	return new_n;
}

void printNodesDown(struct Node* root,int k){
	if(root==NULL||k<0){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printNodesDown(root->left,k-1);
	printNodesDown(root->right,k-1);
}

int printNodes(struct Node* root,struct Node* target,int k){
	if(root==NULL){
		return -1;
	}
	if(root==target){
		printNodesDown(root,k);
		return 0;
	}
	int dl=printNodes(root->left,target,k);
	if(dl!=-1){
		if(dl+1==k){
			cout<<"dl is "<<dl<<" and k is "<<k<<endl;
			cout<<root->data<<" ";
		}
		else{
			if(root->right)
			cout<<"Going down for "<<root->right->data<<endl;
			printNodesDown(root->right,k-dl-2);
		}
		return 1+dl;
	}

	int dr=printNodes(root->right,target,k);
		if(dr!=-1){
			if(dr+1==k){
				cout<<root->data<<" ";
			}
			else{
				printNodesDown(root->left,k-dr-2);
			}
			return 1+dr;
		}
		return -1;
}
int main() {
	struct Node* root=NULL;
	int k=2;
	root=newnode(20);
	root->left = newnode(8);
	    root->right = newnode(22);
	    root->left->left = newnode(4);
	    root->left->right = newnode(12);
	    root->left->right->left = newnode(10);
	    root->left->right->right = newnode(14);
	    printNodes(root,root->left->right,k);
}



*/
