/*
 * treeFromTwoTraversals.h
 *
 *  Created on: Jul 31, 2015
 *      Author: user
 */

#ifndef TREEFROMTWOTRAVERSALS_H_
#define TREEFROMTWOTRAVERSALS_H_
#include "BinaryTreeAdvanced.h"
#include<cstring>
#include<stack>
using namespace std;

class treeFromTwoTraversals{
	BinaryTreeNode*root;
	BinaryTreeNode *constructtreeFromInAndPreTraversals(int inorder[],int preorder[],int startIndx,int endIndx);
	BinaryTreeNode *constructtreeFromInAndPostTraversals(int inorder[],int postorder[],int startIndx,int endIndx);
	BinaryTreeNode *constructtreeFromInAndLevelTraversals(int inorder[],int levelorder[],int startIndx,int endIndx,int n);
	BinaryTreeNode *constructtreeFromPreAndPostTraversals(int preorder[],int postorder[],int startIndx,int endIndx,int n);
	int *extractKeys(int inorder[],int levelorder[],int startIndx,int endIndx,int n);
	BinaryTreeNode* newNode(int data);
	int search(int in[],int data,int startIndx,int endIndx);
	void inorderHelper(BinaryTreeNode *);
public:
    void constructtreeFromInAndPre(int in[],int pre[],int len);
    void constructtreeFromInAndPost(int in[],int post[],int len);
    void constructtreeFromInAndLevel(int in[],int level[],int len);
    void constructTreeFromPreAndPost(int pre[],int post[],int len);
    void inOrderTraversalWithoutRecursion();
    void preOrderTraversalWithoutRecursion();
    void postOrderTraversalWithoutRecursion();
    void postOrderTraversalUsingOneStack();
};



#endif /* TREEFROMTWOTRAVERSALS_H_ */
