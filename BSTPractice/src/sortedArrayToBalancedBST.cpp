/*
//============================================================================
// Name        : BSTPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<queue>
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

struct Node* sortedArrayToBalancedBST(int arr[],int start,int end){
	int mid=(start+end)/2;

	if(start>end){
		return NULL;
	}
	struct Node* root=newNode(arr[mid]);
	root->left=sortedArrayToBalancedBST(arr,start,mid-1);
	root->right=sortedArrayToBalancedBST(arr,mid+1,end);
	return root;
}

void inorder(struct Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Node* root=NULL;

    root = sortedArrayToBalancedBST(arr, 0, n-1);
   inorder(root);

    return 0;
}
*/
