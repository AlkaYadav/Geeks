/*
 * inorderPredSucc.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user
 */


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

void inorderPredSucc(struct Node* root,int key,struct Node* &pred,struct Node* &succ){
	if(root==NULL){
		return ;
	}
	if(root->data <key){
		pred=root;
		inorderPredSucc(root->right,key,pred,succ);
	}
	if(root->data>key){
		succ=root;
		inorderPredSucc(root->left,key,pred,succ);
	}
	else if(root->data==key){
		if(root->left){
			pred=root->left;
			while(pred->right){
				pred=pred->right;
			}
		if(root->right){
			succ=root->right;
			while(succ->left){
				succ=succ->left;
			}
		}
		}
		return;
	}

}

int main()
{
    int key = 65;
    struct Node* root=NULL;
    struct Node* pred=NULL;
    struct Node* succ=NULL;
    root=newNode(50);
    root->left=newNode(30);
    root->right=newNode(70);
    root->left->left=newNode(20);
    root->left->right=newNode(40);
    root->right->left=newNode(60);
    root->right->right=newNode(80);

    inorderPredSucc(root,key,pred,succ);
    cout<<"Pred is "<<pred->data<<"and succ is "<<succ->data<<endl;
}
