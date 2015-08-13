//============================================================================
// Name        : GreatTreeListRecursion.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GreatTreeListRecursion.h"

BST::BST(){
	root = NULL;
}

void BST::insertRandom(){
	root=insert(5);
	root->left=insert(2);
	root->right=insert(10);
	root->left->left=insert(1);
	root->left->right=insert(3);
}

BSTNode * BST::insert(int newdata){
	BSTNode *newnode = new BSTNode();
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = newdata;
	cout<<"inserted data "<<newdata<<"successfully"<<endl;
	return newnode;
}

void BST::convertTreeToCircularLinkedList(){
	BSTNode *head=convertTreeToCircularLinkedListHelper(root);
	printCircularLinkedList(head);
}

BSTNode* BST::convertTreeToCircularLinkedListHelper(BSTNode *root){
	if(root==NULL){
		return NULL;
	}
	BSTNode* aList=convertTreeToCircularLinkedListHelper(root->left);
	BSTNode* bList=convertTreeToCircularLinkedListHelper(root->right);
	root->left=root;
	root->right=root;
	aList=append(aList,root);
	aList=append(aList,bList);
	return aList;
}

BSTNode * BST::append(BSTNode* node1,BSTNode* node2){
	if(node1 ==NULL){
		return node2;
	}
	if(node2==NULL){
		return node1;
	}
	BSTNode *node1_last=node1->left;
	BSTNode *node2_last=node2->left;
    node1->left=node2_last;
    node2_last->right=node1;
    node1_last->right=node2;
    node2->left=node1_last;
    return node1;
}

void BST::printCircularLinkedList(BSTNode *head){
	BSTNode *tmp;
	do{
		cout<<tmp->data<<"->";
		tmp=tmp->right;
	}while(tmp!=head);
}
