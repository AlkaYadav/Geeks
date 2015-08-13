/*
 * GeneralBinaryTree.h
 *
 *  Created on: Aug 3, 2015
 *      Author: user
 */

#ifndef GENERALBINARYTREE_H_
#define GENERALBINARYTREE_H_

#include<iostream>
#include "BinaryTreeAdvanced.h"
#include "limits.h"
#include <queue>
#include<stack>
using namespace std;

class GeneralBinaryTree{
	BinaryTreeNode* root;
	BinaryTreeNode* root2;          //For second tree
	BinaryTreeNode * insert(int newdata);
	void doubleTreeHelper(BinaryTreeNode*);
	void inorderHelper(BinaryTreeNode *);
	int heightBinaryTreeHelper(BinaryTreeNode *root);
	int maxWidthHelper(BinaryTreeNode *,int level);
	void maxWidthHelperPreorder(BinaryTreeNode *root,int level,int a[]);
	int getLevelOfNodeHelper(BinaryTreeNode* root,int data,int level);
	bool isFoldableHelper(BinaryTreeNode* node1,BinaryTreeNode* node2);
	void printNodesAtDistanceKFromRootHelper(BinaryTreeNode* root,int k);
	void printArray(int a[],int index);
	void printAncestorsOfNodeHelper(BinaryTreeNode* root,int data,int a[],int index);
	bool printAncestorsOfNodeHelperOther(BinaryTreeNode* root,int data);
	bool isSumTreeHelper(BinaryTreeNode* root);
	int sum(BinaryTreeNode* root);
	bool isLeaf(BinaryTreeNode* root);
	int sumOptimized(BinaryTreeNode* root);
	int convertToSumHelper(BinaryTreeNode* root);
	bool areIdentical(BinaryTreeNode* root,BinaryTreeNode* subtree);
	bool checkIfSubtreeHelper(BinaryTreeNode* root,BinaryTreeNode* subtree);
	void populateInorderSuccessorHelper(BinaryTreeNode* root);
	BinaryTreeNode* nextRight(BinaryTreeNode* root);
	void verticalSumHelper(BinaryTreeNode* root,int HD,int arr[]);
	bool printPath(BinaryTreeNode* root,BinaryTreeNode* target);
	void findMaximumSumRootToLeafPathHelper(BinaryTreeNode* root,BinaryTreeNode** target,int& max_sum,int);
	BinaryTreeNode* newNode(int data);
	void printLeftMostBoundary(BinaryTreeNode* root);
	void printLeaves(BinaryTreeNode* root);
	void printRightMostBoundary(BinaryTreeNode* root);
	bool isIsomorphicHelper(BinaryTreeNode* root,BinaryTreeNode* root2);

	public:

	GeneralBinaryTree();
	void insertRandom();
	void doubleTree();
	int maxWidth();
	int maxWidthPreorder();
	int getLevelOfNode(int data);
	bool isFoldable();
	void printNodesAtDistanceKFromRoot(int k);
	void printAncestorsOfNode(int data);
	bool ifSumTree();
	void convertToSum();
	bool checkIfSubtree();
	void populateInorderSuccessor();
	void connectNodesAtSameLevel();
	void connectNodesSameLevelConstantStorage();
	void verticalSum();
	void findMaximumSumRootToLeafPath();
	void constructTreeFromPreorder(int pre[],char preLn[],int size);
	BinaryTreeNode* constructTreeFromPreorderHelper(int pre[],char preLn[],int *preStart,int preEnd);
	bool isCompleteBinaryTree();
	void reverseLevelOrderTraversal();
	int iterativeHeight();
	void boundaryTraversal();
	bool isIsomorphic();
};


#endif /* GENERALBINARYTREE_H_ */
