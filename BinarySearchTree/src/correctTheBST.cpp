/*

 * correctTheBST.cpp
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

void correctTheBST(struct node* root,struct node** prev,struct node** first,struct node** last,struct node** mid){
	if(root==NULL){
		return;
	}
	correctTheBST(root->left,prev,first,last,mid);
	if(*prev){
		if((*prev)->data>root->data){
			if(!*first){
				*first=*prev;
				*mid=root;
			}
			else{
				*last=root;
			}
		}
	}

		*prev=root;


		correctTheBST(root->right,prev,first,last,mid);
}

int main(){

	struct node *root = newNode(6);
	root->left        = newNode(10);
	    root->right       = newNode(2);
	    root->left->left  = newNode(1);
	    root->left->right = newNode(3);
	    root->right->right = newNode(12);
	    root->right->left = newNode(7);

	    struct node* prev=NULL,*first=NULL,*last=NULL,*mid=NULL;
	    correctTheBST(root,&prev,&first,&last,&mid);
	    cout<<first->data<<" first"<<endl;
	    cout<<last->data<<" last"<<endl;

}



*/
