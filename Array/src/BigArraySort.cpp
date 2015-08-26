/*

 * BigArraySort.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: user


//How to sort a big array with many repetitions?

#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	int count;
	Node* left;
	Node* right;
};

struct Node* newNode(int data){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->data=data;
	newnode->count=1;
	return newnode;
}

struct Node*  insert(struct Node* root,int data){
	if(root==NULL){
		return newNode(data);
	}
	if(data==root->data){
		root->count+=1;
		return root;
	}
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	else if(data>root->data)
		root->right=insert(root->right,data);
	return root;
}

void inorder(struct Node* root){
	if(root){
		inorder(root->left);
		for(int i=0;i<root->count;i++)
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void sortBigArrayRepetition(int arr[],int n){
	struct Node* root=NULL;
	for(int i=0;i<n;i++){
		root=insert(root,arr[i]);
	}
	inorder(root);
}

int main(){
	int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1};
	int len=sizeof(arr)/sizeof(arr[0]);
	sortBigArrayRepetition(arr,len);
}
*/
