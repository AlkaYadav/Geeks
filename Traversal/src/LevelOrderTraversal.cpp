//============================================================================
// Name        : LevelOrderTraversal.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "LevelOrderTraversal.h"
using namespace std;

BinaryTree::BinaryTree(){
	root=NULL;
}

void BinaryTree::insertRandom(){
	/*
	root=insert(7);
	root->left=insert(8);
	root->right=insert(2);
	root->left->left=insert(9);
	root->left->right=insert(6);
	*/
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);

}

BinaryTreeNode * BinaryTree::insert(int newdata){
	BinaryTreeNode *newnode = new BinaryTreeNode();
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = newdata;
	cout<<"inserted data "<<newdata<<"successfully"<<endl;
	return newnode;
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

void BinaryTree::levelOrderTraversal(){
	cout<<"hi"<<endl;
	if(root){
		cout<<"hi"<<endl;
		levelOrderTraversalUsingHeight(root);
	}
	else{
		cout<<"Tree is empty"<<endl;
		return;
	}
}

void BinaryTree::levelOrderTraversalUsingHeight(BinaryTreeNode *root){
	int h=heightBinaryTree();
	for(int i=1;i<=h;i++){
		printLevelTraversal(root,i);
	}
	cout<<endl;
}

void BinaryTree::printLevelTraversal(BinaryTreeNode *root,int level){
	if(root==NULL){
		return;
	}
	if(level==1){
		cout<<root->data<<"->";
	}
	else{
		printLevelTraversal(root->left,level-1);
		printLevelTraversal(root->right,level-1);
	}
}
/*******************************************************
 * Start levelOrderTraversalUsingQueue
 ********************************************************/
void BinaryTree::levelOrderTraversalUsingQueue(){
	if(root){
		levelOrderTraversalUsingQueueHelper(root);
	}
	else{
		return;
	}
}

void BinaryTree::levelOrderTraversalUsingQueueHelper(BinaryTreeNode *root){
	queue<BinaryTreeNode*> q;
	if(root==NULL){
		return;
	}
	q.push(root);
	while(!q.empty()&& root){
		BinaryTreeNode* top=q.front();
		cout<<top->data<<"->";
		q.pop();
		if(top->left){
		q.push(top->left);
		}
		if(top->right){
		q.push(top->right);
		}
	}
	cout<<endl;
}
/*******************************************************
 * End levelOrderTraversalUsingQueue
 ********************************************************/

/*******************************************************
 * Start levelOrderTraversal in spiral
 ********************************************************/
void BinaryTree::levelOrderTraversalInSpiral(){
	if(root){
			levelOrderTraversalInSpiralHelper(root);
		}
		else{
			return;
		}
}

void BinaryTree::levelOrderTraversalInSpiralHelper(BinaryTreeNode *root){
	int h=heightBinaryTree();
	bool ltr=false;
		for(int i=1;i<=h;i++){
			printLevelTraversalInSpiral(root,i,ltr);
			ltr=!ltr;
		}
		cout<<endl;
}

void BinaryTree::printLevelTraversalInSpiral(BinaryTreeNode *root,int level,bool lefttoright){
	//cout<<"value of "<<lefttoright<<endl;
	if(root==NULL){
		return;
	}
	if(level==1){
		cout<<root->data<<"->";
	}
	else if(level>1){
						if(lefttoright){
							printLevelTraversalInSpiral(root->left,level-1,lefttoright);
							printLevelTraversalInSpiral(root->right,level-1,lefttoright);
						}
						else{
							printLevelTraversalInSpiral(root->right,level-1,lefttoright);
							printLevelTraversalInSpiral(root->left,level-1,lefttoright);
						}
                    }
}
/*******************************************************
 * End levelOrderTraversal in spiral
 ********************************************************/

/*******************************************************
 * Start levelOrderTraversal in spiral using stack(Iterative version)
 ********************************************************/
void BinaryTree::levelOrderTraversalInSpiralUsingStack(){
	if(root){
			levelOrderTraversalInSpiralUsingStackHelper(root);
		}
		else{
			return;
		}
}

void BinaryTree::levelOrderTraversalInSpiralUsingStackHelper(BinaryTreeNode *root){
	stack<BinaryTreeNode*> s1;
	stack<BinaryTreeNode*> s2;
	if(root==NULL){
		return;
	}
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			BinaryTreeNode *top1=s1.top();
			cout<<top1->data<<"->";
			s1.pop();
			if(top1->left){
				s2.push(top1->left);
			}
			if(top1->right){
				s2.push(top1->right);
			}
		}

		while(!s2.empty()){
					BinaryTreeNode *top2=s2.top();
					cout<<top2->data<<"->";
					s2.pop();
					if(top2->left){
						s1.push(top2->left);
					}
					if(top2->right){
						s1.push(top2->right);
					}
				}
	}
	}
/*******************************************************
 * Start levelOrderTraversal in spiral using stack(Iterative version)
 ********************************************************/
