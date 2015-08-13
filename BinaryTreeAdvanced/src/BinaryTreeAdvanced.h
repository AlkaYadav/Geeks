/*
 * BinaryTreeAdvanced.h
 *
 *  Created on: Jul 31, 2015
 *      Author: user
 */

#ifndef BINARYTREEADVANCED_H_
#define BINARYTREEADVANCED_H_

#include <iostream>
#define MAX_SIZE 10
#include<cmath>
using namespace std;

class BinaryTreeNode{
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *next;   //Used for inorder successor
	int data;
	friend class BinaryTree;
	friend class treeFromTwoTraversals;
	friend class GeneralBinaryTree;
};
class BinaryTree{
	BinaryTreeNode *root;
	void printPathSumHelper(BinaryTreeNode *root,int sum,int a[],int len);
	void printPathArray(int a[],int len);
	int heightBinaryTreeHelper(BinaryTreeNode *root);
	int diameterHelper(BinaryTreeNode *root);
	int diameterOptimizedHelper(BinaryTreeNode *root,int *h);
	bool checkForChildSumPropertyHelper(BinaryTreeNode * root);
	void inorderHelper(BinaryTreeNode *);
	void convert(BinaryTreeNode *root);
	void increment(BinaryTreeNode * root,int diff);
	bool checkIfBTHeightBalancedHelper(BinaryTreeNode *);
	bool checkIfBTHeightBalancedOptimizedHelper(BinaryTreeNode *root,int *);
public:
	BinaryTree();
	BinaryTreeNode * insert(int data);
	void printPathSum(int sum);
	void insertRandom();
	int diameter();
	int diameterOptimized();
	bool checkForChildSumProperty();
	void inorder();
	void converttoChildSumTree();
	bool checkIfBTHeightBalanced();
	bool checkIfBTHeightBalancedOptimized();
};



#endif /* BINARYTREEADVANCED_H_ */
