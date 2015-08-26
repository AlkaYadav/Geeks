/*

 * BSTInorderPredSucc.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

void inorderPredSucc(struct node* root,struct node* &pred,struct node* &succ,int data){
	if(root==NULL){
		return;
	}

	if(root->data==data){
		if(root->left){
			pred=root->left;
			while(pred->right){
				pred=pred->right;
			}
		}

		if(root->right){
			succ=root->right;
			while(succ->left){
				succ=succ->left;
			}
		}

		return ;
	}

	else if(root->data>data){
		succ=root;
		inorderPredSucc(root->left,pred,succ,data);
	}
	else if(root->data<data){
			pred=root;
			inorderPredSucc(root->left,pred,succ,data);
		}
}

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
****************************************************************************************
 * Check if a binary tree is BST or not


bool isBST(struct node* root,int min,int max){
	if(root==NULL){
		return true;
	}
	if(root->data<=min || root->data>max){
		return false;
	}
	return isBST(root->left,min,root->data-1) && isBST(root->right,root->data+1,max);

}

//LCA in BST
struct node* lca_bst(struct node* root,int node1,int node2){
	if(root==NULL){
		return NULL;
	}
	if(node1<root->data && node2<root->data){
		return lca_bst(root->left,node1,node2);
	}
	if((node1<=root->data && node2>root->data) || (node2<=root->data && node1>root->data)){
		return root;
	}
	if(node1<root->data && node2<root->data){
		return	lca_bst(root->right,node1,node2);
	}
	return NULL;
}

//Sorted order printing of a given array
void printAscending(int arr[],int index,int n){
	if(index>=n){
		return;
	}
	else{
		printAscending(arr,2*index+1,n);
		cout<<arr[index]<<" ";
		printAscending(arr,2*index+2,n);
	}
}
int main(){
	struct node* root=NULL;
	struct node* pred=NULL;
	struct node* succ=NULL;
	int data;
	cout<<"Enter data to insert in BST"<<endl;
	for(int i=0;i<5;i++){
		cin>>data;
		root=insert(root,data);

	}
	inorder(root);
	cout<<endl<<"Enter the data for which inorder pred succ to be found"<<endl;
	cin>>data;
	inorderPredSucc(root,pred,succ,data);
	if(pred){
		cout<<"pred is "<<pred->data<<endl;
	}
	if(succ){
		cout<<"succ is "<<succ->data<<endl;
	}
	root=insert(root,20);
	root->left               = newNode(8);
	root->right              = newNode(22);
	root->left->left         = newNode(4);
	root->left->right        = newNode(12);
	root->left->right->left  = newNode(10);
	root->left->right->right = newNode(14);
	cout<<"Check if a binary tree is BST"<<isBST(root,INT_MIN,INT_MAX)<<endl;

	int node1,node2;
	cout<<"LCA for node1 "<<endl;
	cin>>node1;
	cout<<"node2"<<endl;
	cin>>node2;
	struct node* lca=lca_bst(root,node1,node2);
	cout<<"LCA is "<<lca->data;

	int arr[]={4,2,5,1,3};
	int n=sizeof(arr)/sizeof(int);
	printAscending(arr,0,n);

}

*/
