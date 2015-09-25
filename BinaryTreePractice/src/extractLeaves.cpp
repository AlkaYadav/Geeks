/*

 * isSubtree.cpp
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

struct Node* extractLeaves(struct Node* root,struct Node* &head){
	static struct Node* prev=NULL;
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL&& root->right==NULL){
		root->left=prev;
		if(prev){
			prev->right=root;
		}
		prev=root;
		if(head==NULL){
			head=prev;
		}
		return NULL;
	}
	root->left=extractLeaves(root->left,head);
	root->right=extractLeaves(root->right,head);
	return root;
}

void print(struct Node *root)
{
    if (root != NULL)
    {
         print(root->left);
         printf("%d ",root->data);
         print(root->right);
    }
}

void printList(struct Node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}

int main()
{
     struct Node *head = NULL;
     struct Node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);

     root=extractLeaves(root,head);
     printList(head);
}
*/
