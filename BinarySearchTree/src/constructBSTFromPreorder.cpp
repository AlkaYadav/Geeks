/*

 * constructBSTFromPreorder.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


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

struct node* constructBSTFromPreorder(int pre[],int start,int end){
	static int preIndex=0;
	if(start>end|| preIndex>end){
		return NULL;
	}

	//Find index of next higher number from root
	struct node* root=newNode(pre[preIndex++]);
	if(start==end){
		return root;
	}
	int i;
	for(i=start;i<end;i++){
		if(pre[i]>root->data){
			break;
		}
	}

	root->left=constructBSTFromPreorder(pre,preIndex,i-1);
	root->right=constructBSTFromPreorder(pre,i,end);
	return root;
}

int main(){
	struct node* root=NULL;
	int pre[]={10, 5, 1, 7, 40, 50};
	int len=sizeof(pre)/sizeof(int);
	root=constructBSTFromPreorder(pre,0,len-1);
	inorder(root);
}
*/
