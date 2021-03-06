/*
 * treeFromTwoTraversals.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: user
 */

#include "treeFromTwoTraversals.h"

void treeFromTwoTraversals::constructtreeFromInAndPre(int in[],int pre[],int len){
	if(len>0){
	root=constructtreeFromInAndPreTraversals(in,pre,0,len-1);
	inorderHelper(root);
	}
}


void treeFromTwoTraversals::inorderHelper(BinaryTreeNode *node){
	    if(node){
		inorderHelper(node->left);
		cout<<node->data<<"->";
		inorderHelper(node->right);
	}
}
BinaryTreeNode* treeFromTwoTraversals::newNode(int data){
	BinaryTreeNode * node=new BinaryTreeNode();
	node->data=data;
	node->right=NULL;
	node->left=NULL;
	cout<<"Constructed node"<<data<<endl;
	return node;
}
BinaryTreeNode *treeFromTwoTraversals::constructtreeFromInAndPreTraversals(int inorder[],int preorder[],int startIndx,int endIndx){
	static int preIndx=0;
	if(startIndx>endIndx){
		return NULL;
	}
	BinaryTreeNode* tNode=newNode(preorder[preIndx++]);
	if(startIndx==endIndx){
		return tNode;
	}
	int inIndx=search(inorder,tNode->data,startIndx,endIndx);
	tNode->left=constructtreeFromInAndPreTraversals(inorder,preorder,startIndx,inIndx-1);
	tNode->right=constructtreeFromInAndPreTraversals(inorder,preorder,inIndx+1,endIndx);
	return tNode;
}

int treeFromTwoTraversals::search(int in[],int data,int startIndx,int endIndx){
	for(int i=startIndx;i<=endIndx;i++){
		if(in[i]==data){
			return i;
		}
	}
	return -1;
}
/********************************************************************************************
 * Start Construct tree from inorder and postorder traversal
 ********************************************************************************************/
void treeFromTwoTraversals::constructtreeFromInAndPost(int in[],int post[],int len){
	if(len>0){
	root=constructtreeFromInAndPostTraversals(in,post,0,len-1);
	inorderHelper(root);
	}
}

BinaryTreeNode *treeFromTwoTraversals::constructtreeFromInAndPostTraversals(int inorder[],int postorder[],int startIndx,int endIndx){
	static int postIndx=endIndx;
	if(startIndx>endIndx){
		return NULL;
	}
	BinaryTreeNode* tNode=newNode(postorder[postIndx--]);
	if(startIndx==endIndx){
		return tNode;
	}
	int inIndx=search(inorder,tNode->data,startIndx,endIndx);

	tNode->right=constructtreeFromInAndPostTraversals(inorder,postorder,inIndx+1,endIndx);
	tNode->left=constructtreeFromInAndPostTraversals(inorder,postorder,startIndx,inIndx-1);
	return tNode;
}
/********************************************************************************************
 * End Construct tree from inorder and postorder traversal
 ********************************************************************************************/

/********************************************************************************************
 * Start Construct tree from inorder and level order traversals
 *******************************************************************************************/
int *treeFromTwoTraversals::extractKeys(int inorder[],int levelorder[],int startIndx,int endIndx,int n){
	int *arr=new int[endIndx-startIndx+1];
	int j=0;
	for(int i=0;i<n;i++){
		if(search(inorder,levelorder[i],startIndx,endIndx)!=-1){
			arr[j++]=levelorder[i];
		}
	}
	return arr;
}
void treeFromTwoTraversals::constructtreeFromInAndLevel(int in[],int level[],int len){
	if(len>0){
		root=constructtreeFromInAndLevelTraversals(in,level,0,len-1,len);
		cout<<"Inorder faft"<<endl;
		inorderHelper(root);
		cout<<"Ending"<<endl;
	}
}

BinaryTreeNode *treeFromTwoTraversals::constructtreeFromInAndLevelTraversals(int inorder[],int levelorder[],int startIndx,int endIndx,int n){
	if(startIndx>endIndx){
		return NULL;
	}
	BinaryTreeNode* tNode=newNode(levelorder[0]);
	if(startIndx==endIndx){
		return tNode;
	}
	int inIndx=search(inorder,tNode->data,startIndx,endIndx);
	int *leftlevelorder=extractKeys(inorder,levelorder,startIndx,inIndx-1,n);
	int *rightlevelorder=extractKeys(inorder,levelorder,inIndx+1,endIndx,n);
	tNode->left=constructtreeFromInAndLevelTraversals(inorder,leftlevelorder,startIndx,inIndx-1,n);
	tNode->right=constructtreeFromInAndLevelTraversals(inorder,rightlevelorder,inIndx+1,endIndx,n);
	delete []leftlevelorder;
	delete []rightlevelorder;
	return tNode;
}

/*********************************************************************************************
 * Start Inorder traversal without recursion
 ********************************************************************************************/
void treeFromTwoTraversals::inOrderTraversalWithoutRecursion(){
	BinaryTreeNode * current=root;
	stack<BinaryTreeNode*> s;
	bool done=0;
	while(!done){
		while(current!=NULL){
			s.push(current);
			current=current->left;
		}

					{
					if(!s.empty()){
					BinaryTreeNode* top=s.top();
					s.pop();
					cout<<top->data;
					current=top->right;
				}
				else{
					done=1;
		}
	}
	}
	}
/*********************************************************************************************
 * End Inorder traversal without recursion
 ********************************************************************************************/

/*********************************************************************************************
 * Start Preorder traversal without recursion
 ********************************************************************************************/
void treeFromTwoTraversals::preOrderTraversalWithoutRecursion(){
	if(root==NULL){
		return;
	}
	stack<BinaryTreeNode*> s;
	s.push(root);
	while(!s.empty()){
		BinaryTreeNode* top=s.top();
		s.pop();
		cout<<top->data<<"->";
		if(top->right){
			s.push(top->right);
		}
		if(top->left){
			s.push(top->left);
		}
	}
}
/*********************************************************************************************
 * End Preorder traversal without recursion
 ********************************************************************************************/

/*********************************************************************************************
 * Start Postorder traversal without recursion
 ********************************************************************************************/
void treeFromTwoTraversals::postOrderTraversalWithoutRecursion(){
	stack<BinaryTreeNode*> s1,s2;
	if(root==NULL){
		return;
	}
	s1.push(root);
	while(!s1.empty()){
		BinaryTreeNode * top1=s1.top();
		s1.pop();
		s2.push(top1);
		if(top1->left){
			s1.push(top1->left);
		}
		if(top1->right){
					s1.push(top1->right);
				}
	}
	while(!s2.empty()){
		BinaryTreeNode * top2=s2.top();
		s2.pop();
		cout<<top2->data<<"->";
	}
}
/*********************************************************************************************
 * End Postorder traversal without recursion
 ********************************************************************************************/

/*********************************************************************************************
 * Start Postorder traversal using one stack(INCOMPLETE)
 ********************************************************************************************/
void treeFromTwoTraversals::postOrderTraversalUsingOneStack(){
	BinaryTreeNode* current=root;
	stack<BinaryTreeNode*> s;
	if(current==NULL){
		return;
	}
do{
	while(current){
		if(current->right){
			s.push(current->right);
		}
			s.push(current);
			current=current->left;
	}
	current=s.top();
	s.pop();
	if(current->right && s.top()==current->right){
		s.pop();
		s.push(current);
		current=current->right;
	}
	else{
		cout<<current->data<<"->";
		current=NULL;
	}
}while(!s.empty());
}
/*********************************************************************************************
 * End Postorder traversal using one stack(INCOMPLETE)
 ********************************************************************************************/

/*********************************************************************************************
 * Start Construct Full Binary tree from given preorder and postorder traversals
 ********************************************************************************************/
void treeFromTwoTraversals::constructTreeFromPreAndPost(int pre[],int post[],int len){
	if(len>0){
		int startIndx=0;
		root=constructtreeFromPreAndPostTraversals(pre,post,startIndx,len-1,len);
	}
}

BinaryTreeNode *treeFromTwoTraversals::constructtreeFromPreAndPostTraversals(int preorder[],int postorder[],int startIndx,int endIndx,int n){
	static int preIndx=startIndx;

	if(startIndx>endIndx || preIndx>=n){
		return NULL;
	}
	BinaryTreeNode* tNode=newNode(preorder[preIndx]);
	++preIndx;
	if(endIndx==startIndx){
		return tNode;
	}
	if(preIndx<=endIndx){
	int postIndx=search(postorder,preorder[preIndx],startIndx,endIndx);
	if(postIndx!=-1){
	tNode->left=constructtreeFromPreAndPostTraversals(preorder,postorder,startIndx,postIndx,n);
	tNode->right=constructtreeFromPreAndPostTraversals(preorder,postorder,postIndx+1,endIndx,n);
	}
	}
	return tNode;
}
