/*

 * BSTDelete.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: user

#include<iostream>
#include<stdio.h>
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
struct node* insert(struct node* root,int data){
	if(root==NULL){
		return newNode(data);
	}
	if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else if(data>root->data){
		root->right=insert(root->right,data);
	}
	return root;
}

struct node* findNextRightNode(struct node* root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

struct node*  deleteBSTNode(struct node* root,int data){
	if(data<root->data){
		root->left=deleteBSTNode(root->left,data);
	}
	else if(data>root->data){
		root->right=deleteBSTNode(root->right,data);
	}
	else{
		if(data==root->data){
			//Root is leaf node
			if(root->left==NULL && root->right==NULL){
				root=NULL;
				return NULL;
			}
			else if(root->left==NULL && root->right){
				return root->right;
			}
			else if(root->left && root->right==NULL){
				return root->left;
			}
			else{
				struct node* findNextRight=findNextRightNode(root->right);
				root->data=findNextRight->data;
				root->right= deleteBSTNode(root->right,findNextRight->data);
			}
		}
	}
	return root;
}

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
struct node*  minimumValue(struct node* root){
	struct node* mini=root;
	while(mini->left){
		mini=mini->left;
	}
	return mini;
}
int main(){
	struct node* root=NULL;
	int data;
	cout<<"Enter data to insert in BST"<<endl;
	for(int i=0;i<5;i++){
		cin>>data;
		root=insert(root,data);

	}
	inorder(root);
	//deleteBSTNode(root,1);
	struct node* mini=minimumValue(root);
	cout<<"Minimum value "<<mini->data<<endl;
	return 0;
}
*/
