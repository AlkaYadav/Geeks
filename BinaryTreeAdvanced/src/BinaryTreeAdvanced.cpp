//============================================================================
// Name        : BinaryTreeAdvanced.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BinaryTreeAdvanced.h"
/********************************************
 * Start Print Path sum
 ********************************************/
void BinaryTree::printPathSum(int sum){
	if(root==NULL||sum==0){
		return;
	}
	else{
		int a[MAX_SIZE];
		printPathSumHelper(root,sum,a,0);
	}
}

void BinaryTree::printPathSumHelper(BinaryTreeNode *root,int sum,int a[],int len){
	if(root==NULL){
		return;
	}
	a[len++]=root->data;
	int subsum=sum-root->data;
	if(root->left==NULL && root->right==NULL &&subsum==0){
		printPathArray(a,len);
	}
	else{
		printPathSumHelper(root->left,subsum,a,len);
		printPathSumHelper(root->right,subsum,a,len);
	}
}

void BinaryTree::printPathArray(int a[],int len){
	for(int i=0;i<len;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
/********************************************
 * End Print Path sum
 ********************************************/
BinaryTree::BinaryTree(){
	root=NULL;
}
void BinaryTree::insertRandom(){
	root=insert(50);
	root->left=insert(8);
	root->right=insert(2);
	root->left->left=insert(3);
	root->left->right=insert(5);
	root->right->left=insert(1);
	root->right->right=insert(30);
}
BinaryTreeNode * BinaryTree::insert(int newdata){
	BinaryTreeNode *newnode = new BinaryTreeNode();
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->next = NULL;
	newnode->data = newdata;
	cout<<"inserted data "<<newdata<<"successfully"<<endl;
	return newnode;
}

/********************************************
 * Start Diameter of Binary Tree
 ********************************************/
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

int BinaryTree::diameter(){
	if(root==NULL){
		return 0;
	}
	else {
		return diameterHelper(root);
	}
}

int BinaryTree::diameterHelper(BinaryTreeNode *root){
	if(root==NULL){
		return 0;
	}
	int lheight=heightBinaryTreeHelper(root->left);
	int rheight=heightBinaryTreeHelper(root->right);
	return max(lheight+rheight+1,max(diameterHelper(root->left),diameterHelper(root->right)));
}
/********************************************
 * End Diameter of Binary Tree
 ********************************************/
/********************************************
 * Start Diameter of Binary Tree Optimized
 ********************************************/
int BinaryTree::diameterOptimized(){
	if(root==NULL){
		return 0;
	}
	else {
		int height=0;
		return diameterOptimizedHelper(root,&height);
	}
}

int BinaryTree::diameterOptimizedHelper(BinaryTreeNode *root,int *height){
	if(root==NULL){
		*height=0;
		return 0;
	}
	int lh=0,rh=0;
	int ldiameter=0,rdiameter=0;
	ldiameter=diameterOptimizedHelper(root->left,&lh);
	rdiameter=diameterOptimizedHelper(root->right,&rh);
	*height=max(lh,rh)+1;
	return max(lh+rh+1,max(ldiameter,rdiameter));
}
/********************************************
 * End Diameter of Binary Tree Optimized
 ********************************************/

/********************************************
 * Start  Check for child sum property in Binary Tree
 ********************************************/
bool BinaryTree::checkForChildSumProperty(){
	if(root==NULL){
			return true;
		}
		else{
			return checkForChildSumPropertyHelper(root);
		}
}

bool BinaryTree::checkForChildSumPropertyHelper(BinaryTreeNode * root){
	if(root==NULL||(root->left==NULL && root->right==NULL)){
		return true;
	}
	else{
		int ldata=0,rdata=0;
		if(root->left){
			ldata=root->left->data;
		}
		if(root->right){
			rdata=root->right->data;
		}
		return ((root->data==ldata+rdata) && checkForChildSumPropertyHelper(root->left) &&
				checkForChildSumPropertyHelper(root->right));
	}
}

/********************************************
 * End  Check for child sum property in Binary Tree
 ********************************************/

/********************************************
 * Start  Convert an arbitrary Binary Tree to follow child sum property
 ********************************************/
void BinaryTree::converttoChildSumTree(){
	if(root){
		convert(root);
	}
}
void BinaryTree::convert(BinaryTreeNode *root){
	if(root==NULL || (root->right==NULL && root->left==NULL)){
		return;
	}
	convert(root->left);
	convert(root->right);
	int diff,ldata=0,rdata=0;
	if(root->left){
		ldata=root->left->data;
	}
	if(root->right){
		rdata=root->right->data;
	}
	diff=ldata+rdata-root->data;
	if(diff==0){
		return;
	}
	else if(diff>0){
		root->data=ldata+rdata;
	}
	else{
		increment(root,-diff);
	}
}

void BinaryTree::increment(BinaryTreeNode * root,int diff){
	if(root->left){
		root->left->data+=diff;
		increment(root->left,diff);
	}
	else if(root->right){
		root->right->data+=diff;
		increment(root->left,diff);
	}
}
/********************************************
 * End  Convert an arbritrary Binary Tree to follow child sum property
 ********************************************/

/********************************************
 * Start  Inorder traversal Binary Tree
 ********************************************/
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

/********************************************
 * Start  Inorder traversal Binary Tree
 ********************************************/

bool BinaryTree::checkIfBTHeightBalanced(){
	if(root){
			return checkIfBTHeightBalancedHelper(root);
		}
	return true;
}

bool BinaryTree::checkIfBTHeightBalancedHelper(BinaryTreeNode *root){
	if(root==NULL || (root->left==NULL && root->right==NULL)){
		return true;
	}
	else{
		int lheight=heightBinaryTreeHelper(root->left);
		int rheight=heightBinaryTreeHelper(root->right);
		return (abs((lheight-rheight)<=1) && checkIfBTHeightBalancedHelper(root->left)
				&& checkIfBTHeightBalancedHelper(root->right));
	}
}
/****************************************************
 *
 */
bool BinaryTree::checkIfBTHeightBalancedOptimized(){
	if(root){
			int height=0;
			return checkIfBTHeightBalancedOptimizedHelper(root,&height);
		}
	return true;
}

bool BinaryTree::checkIfBTHeightBalancedOptimizedHelper(BinaryTreeNode *root,int * height){
	if(root==NULL){
		*height=0;
		return true;
	}
	int lh=0,rh=0;
	int l=0,r=0;
	l=checkIfBTHeightBalancedOptimizedHelper(root->left,&lh);
	r=checkIfBTHeightBalancedOptimizedHelper(root->right,&rh);
	*height=max(lh,rh)+1;
	if((lh-rh)>=2){
		return false;
	}
	return l&r;
}
/********************************************
 * End  Inorder traversal Binary Tree
 ********************************************/
