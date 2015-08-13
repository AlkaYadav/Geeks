/*
 * LevelOrderTraversal.h
 *
 *  Created on: Jul 31, 2015
 *      Author: user
 */

#ifndef LEVELORDERTRAVERSAL_H_
#define LEVELORDERTRAVERSAL_H_

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;

class BinaryTreeNode{
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	int data;
	friend class BinaryTree;
	friend class MorrisTraversal;
};
class BinaryTree{
	BinaryTreeNode *root;
	void levelOrderTraversalUsingHeight(BinaryTreeNode *);
	int heightBinaryTreeHelper(BinaryTreeNode *root);
	int heightBinaryTree();
	void printLevelTraversal(BinaryTreeNode *root,int level);
	BinaryTreeNode * insert(int newdata);
	void levelOrderTraversalInSpiralHelper(BinaryTreeNode *root);
	void printLevelTraversalInSpiral(BinaryTreeNode *root,int level,bool lefttoright);
	void levelOrderTraversalInSpiralUsingStackHelper(BinaryTreeNode *root);
public:
	BinaryTree();
	void insertRandom();
	void levelOrderTraversal();
	void levelOrderTraversalUsingQueue();
	void levelOrderTraversalUsingQueueHelper(BinaryTreeNode *root);
	void levelOrderTraversalInSpiral();
	void levelOrderTraversalInSpiralUsingStack();
};




#endif /* LEVELORDERTRAVERSAL_H_ */
