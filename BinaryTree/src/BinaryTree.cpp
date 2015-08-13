//============================================================================
// Name        : BinaryTree.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BinaryTree.h"
#define SIZE 20
BinaryTree::BinaryTree(){
	root=NULL;
	root2=NULL;
}
void BinaryTree::insertRandom(){
	root=insert(7);
	root->left=insert(8);
	root->right=insert(2);
	root->left->left=insert(9);
	root->left->right=insert(6);

	//Insert for tree two
	root2=insert(7);
	root2->left=insert(8);
	root2->right=insert(2);
	root2->left->left=insert(9);
	//root2->left->right=insert(6);
}
BinaryTreeNode * BinaryTree::insert(int newdata){
	BinaryTreeNode *newnode = new BinaryTreeNode();
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = newdata;
	cout<<"inserted data "<<newdata<<"successfully"<<endl;
	return newnode;
}

void BinaryTree::inorder(){
	if(root){
		inorderHelper(root);
	}
	else{
		cout<<"tree empty";
	}
}

void BinaryTree::inorderHelper(BinaryTreeNode *node){
	    if(node){
		inorderHelper(node->left);
		cout<<node->data<<"->";
		inorderHelper(node->right);
	}
}

int BinaryTree::size(){
	return sizeHelper(root);
}

int BinaryTree::sizeHelper(BinaryTreeNode *node){
	if(node){
		return 1+sizeHelper(node->left)+sizeHelper(node->right);
	}
	else return 0;
}

int BinaryTree::determineIfTwoTreesIdentical(){
	return determineIfTwoTreesIdenticalHelper(root,root2);
}

int BinaryTree::determineIfTwoTreesIdenticalHelper(BinaryTreeNode *rootone,BinaryTreeNode *roottwo){
	if(rootone==NULL && roottwo==NULL){
		return 1;
	}
	else if(rootone && roottwo){
		return (rootone->data==roottwo->data) && determineIfTwoTreesIdenticalHelper(rootone->left,roottwo->left) &&
		        determineIfTwoTreesIdenticalHelper(rootone->right,roottwo->right);
	}
	return 0;
}

int BinaryTree::heightBinaryTree(){
	return heightBinaryTreeHelper(root);
}

int BinaryTree::heightBinaryTreeHelper(BinaryTreeNode *root){
	if(root == NULL){
		return 0;
	}
	int lheight=heightBinaryTreeHelper(root->left);
	int rheight=heightBinaryTreeHelper(root->right);
	if(lheight>rheight){
		return lheight+1;
	}
	else return rheight+1;
}

void BinaryTree::deleteBinaryTree(){
	deleteBinaryTreeHelper(root);
	root=NULL;
}

void BinaryTree::deleteBinaryTreeHelper(BinaryTreeNode *node){
	if(node){
		deleteBinaryTreeHelper(node->left);
		deleteBinaryTreeHelper(node->right);
		free(node);
	}
}

void BinaryTree::mirrorBinaryTree(){
	mirrorBinaryTreeHelper(root);
	inorder();
}

void BinaryTree::mirrorBinaryTreeHelper(BinaryTreeNode *node){
	if(node){
		mirrorBinaryTreeHelper(node->left);
		mirrorBinaryTreeHelper(node->right);
		swap(&(node->left),&(node->right));
		/*BinaryTreeNode *tmp;
			tmp=node->left;
			node->left=node->right;
			node->right=tmp;*/
	}
}

void BinaryTree::swap(BinaryTreeNode **node1,BinaryTreeNode **node2){
	BinaryTreeNode *tmp;
	tmp=*node1;
	*node1=*node2;
	*node2=tmp;
}

void BinaryTree::printPathsRootToLeafOnePerLine(){
	if(root){
		int a[SIZE];
		printPathsRootToLeafOnePerLineHelper(root,a,0);
	}
}

void BinaryTree::printPathsRootToLeafOnePerLineHelper(BinaryTreeNode *root,int *a,int len){
	if(root==NULL){
		return;
	}
	if(root->left==NULL && root->right==NULL){
		a[len]=root->data;
		printArray(a,len+1);
	}
	else{
		a[len]=root->data;
		printPathsRootToLeafOnePerLineHelper(root->left,a,len+1);
		printPathsRootToLeafOnePerLineHelper(root->right,a,len+1);
	}

}

void BinaryTree::printArray(int *a,int len){
	for(int i=0;i<len;i++){
		cout<<a[i]<<"=>";
	}
	cout<<endl;
}

int BinaryTree::countLeafNodes(){
	if(root){
		return countLeafNodesHelper(root);
	}
	else return 0;
}

int BinaryTree::countLeafNodesHelper(BinaryTreeNode *root){
	if(root->left==NULL && root->right==NULL){
		return 1;
	}
	return countLeafNodesHelper(root->left)+
			countLeafNodesHelper(root->right);
}
