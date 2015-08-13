/*
 * MorrisTraversal.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: user
 */
#include "MorrisTraversal.h"

MorrisTraversal::MorrisTraversal(){
	root=NULL;
}

BinaryTreeNode * MorrisTraversal::insert(int newdata){
BinaryTreeNode *newnode = new BinaryTreeNode();
newnode->left = NULL;
newnode->right = NULL;
newnode->data = newdata;
cout<<"inserted data "<<newdata<<"successfully"<<endl;
return newnode;
}

void MorrisTraversal::insertRandom(){
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	root->right->right=insert(6);
	root->right->left=insert(7);
}

void MorrisTraversal::morrisTraversalInorder(){
	if(root==NULL){
		return;
	}
	BinaryTreeNode* current=root;
	BinaryTreeNode* pred;
	while(current){
		if(current->left==NULL){
			cout<<current->data<<"->";
			current=current->right;
		}
		/*Find inorder predecessor of current */
		else{
		pred=current->left;
		while(pred->right&& pred->right!=current){
			pred=pred->right;
		}
		if(pred->right==NULL){
			pred->right=current;

			current=current->left;
		}
		else{
			pred->right=NULL;
			cout<<current->data<<"->";
			current=current->right;
		}
	}
}
}
void MorrisTraversal::morrisTraversalPreorder(){
	if(root==NULL){
		return;
	}
	BinaryTreeNode* current=root;
	BinaryTreeNode* pred;
	while(current){
		if(current->left==NULL){
			cout<<current->data<<"->";
			current=current->right;
		}
		/*Find inorder predecessor of current */
		else{
		pred=current->left;
		while(pred->right&& pred->right!=current){
			pred=pred->right;
		}
		if(pred->right==NULL){
			pred->right=current;
			cout<<current->data<<"->";
			current=current->left;
		}
		else{
			pred->right=NULL;

			current=current->right;
		}
	}
}
}
