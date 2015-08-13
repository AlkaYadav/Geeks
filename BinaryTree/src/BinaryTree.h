/*
 * BinaryTree.h
 *
 *  Created on: Jul 30, 2015
 *      Author: user
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include<iostream>
#include<stdlib.h>
using namespace std;

class BinaryTreeNode{
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	int data;
	friend class BinaryTree;
};
class BinaryTree{
	BinaryTreeNode *root;
	BinaryTreeNode *root2;
	private:
	void inorderHelper(BinaryTreeNode *);
	int sizeHelper(BinaryTreeNode *node);
	int determineIfTwoTreesIdenticalHelper(BinaryTreeNode *rootone,BinaryTreeNode *roottwo);
	int heightBinaryTreeHelper(BinaryTreeNode *root);
	void deleteBinaryTreeHelper(BinaryTreeNode *);
	void mirrorBinaryTreeHelper(BinaryTreeNode *node);
	void swap(BinaryTreeNode **node1,BinaryTreeNode **node2);
	void printPathsRootToLeafOnePerLineHelper(BinaryTreeNode *root,int *a,int);
	void printArray(int *a,int len);
	int countLeafNodesHelper(BinaryTreeNode *);
	public:
		BinaryTree();
		BinaryTreeNode * insert(int data);
		void inorder();
		void insertRandom();
		int size();
		int determineIfTwoTreesIdentical();
		int heightBinaryTree();
		void deleteBinaryTree();
		void mirrorBinaryTree();
		void printPathsRootToLeafOnePerLine();
		int countLeafNodes();
};



#endif /* BINARYTREE_H_ */
