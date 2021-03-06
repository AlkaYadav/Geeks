
/*
 * BinaryTreeGeeks.h
 *
 *  Created on: Aug 6, 2015
 *      Author: user
 */

#ifndef BINARYTREEGEEKS_H_
#define BINARYTREEGEEKS_H_
#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<cstring>
using namespace std;

class SinglyLinkedNode{
	SinglyLinkedNode* next;
	int data;
	friend class LinkedListToCompleteBinaryTree;
};

class BinaryTreeNode{
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	int data;

	friend class LinkedListToCompleteBinaryTree;
};

class LinkedListToCompleteBinaryTree{
	SinglyLinkedNode* head;
	BinaryTreeNode* root;
	BinaryTreeNode* subtree;
	//queue<BinaryTreeNode*> q;
	BinaryTreeNode* linkedListToCompleteBinaryTree(SinglyLinkedNode* head);
	SinglyLinkedNode* insertLinked(int data);
	BinaryTreeNode * insert(int newdata);
	void inorderHelper(BinaryTreeNode *);
	void insertCompleteBinaryTreeHelper(queue<BinaryTreeNode*> &q,int data);
	int LISSHelper(BinaryTreeNode* root);
	void convertBinaryTreeToDoublyHelper(BinaryTreeNode* root,BinaryTreeNode** head);
	void printList(BinaryTreeNode* head);

	void fixLeftPtr(BinaryTreeNode* root,BinaryTreeNode** head);
	void fixRightPtr(BinaryTreeNode* root);
	BinaryTreeNode* convertBinaryTreeToDoublySet1(BinaryTreeNode* root);
	BinaryTreeNode* findLCA(int n1,int n2);
	bool findPath(BinaryTreeNode* root,int node1);
	BinaryTreeNode* findLCAHelper(BinaryTreeNode* root,int n1,int n2,bool &b1,bool &b2);
	int findDistHelper(BinaryTreeNode* root,int node,int dist);
	BinaryTreeNode* findDistLCAHelper(BinaryTreeNode* root,int n1,int n2,int& d1,int& d2,int& dist,int lvl);
	void sumHelper(BinaryTreeNode* root,int &sum,int digit);

	BinaryTreeNode* removeAllPathsSumLessThanKHelper(BinaryTreeNode* root,int* sum,int k);
	BinaryTreeNode* removeAllPathsSumLessThanKHelper2(BinaryTreeNode* root,int k);
	int diffHelper(BinaryTreeNode* root);
	void depthLeftLeafHelper(BinaryTreeNode* root,int lvl,int *maxlvl,bool isLeft);
	bool checkLeavesLevelHelper(BinaryTreeNode* root,int lvl,int *samelevel);
	BinaryTreeNode* extractLeavesHelper(BinaryTreeNode* root,BinaryTreeNode** head);
	bool isBalancedLikeRedBlackHelper(BinaryTreeNode* root,int &minh,int &maxh);
	void printAllNodesDown(BinaryTreeNode* root,int k);
	int printAllNodesAtKHelper(BinaryTreeNode* root,int node,int k);
	void printHDValues(BinaryTreeNode* root,int HD);
	void findMinMaxHD(BinaryTreeNode* root,int& maxhd,int& minhd,int HD);
	int maxSumPathBetweenLeavesHelper(BinaryTreeNode* root,int &maxsum);
	void inorderStoreAlternateLevel(BinaryTreeNode* root,int arr[],int& index,int level);
	void reverseArray(int arr[],int len);
	void inorderModifyAndStoreAlternateLevel(BinaryTreeNode* root,int arr[],int& index,int level);
	bool areSiblings(BinaryTreeNode* root,int node1,int node2);
	int levelNode(BinaryTreeNode* root,int node,int lvl);

	void sumLeftLeaves(BinaryTreeNode* root,int& sum,bool isLeft);
	void maximum(BinaryTreeNode* root,int& maxi);

	void isSubtreeStoreArray(BinaryTreeNode* root,char preS[],int& index);
	void isSubtreeStoreInorderArray(BinaryTreeNode* root,char inS[],int& index);
	bool isSubtreeHelper(BinaryTreeNode* subtree,BinaryTreeNode* root);

	int closestLeaf(BinaryTreeNode* root,BinaryTreeNode* ancestors[],int index,int key);
	int closestLeafDown(BinaryTreeNode* root);
	int getMin(int a,int b);
	BinaryTreeNode* removeHalfNodes(BinaryTreeNode* root);

	void storeInorder(BinaryTreeNode* root,BinaryTreeNode* in[],int& index);
	void retrieveInorderAndConvertThreaded(BinaryTreeNode* root,BinaryTreeNode* in[],int& index,int);

public:
	LinkedListToCompleteBinaryTree();
	void insertRandomLinkedList();
	BinaryTreeNode* linkedListToCompleteBinaryTree();
	void insertCompleteBinaryTree();
	int LISS();
	void convertBinaryTreeToDoubly();
	void convertBinaryTreeToDoublySet2();
	void convertBinaryTreeToDoublySet1();
	void LCAPrint(int n1,int n2);
	int findDist(int n1,int n2);
	void findSum();
	void removeAllPathsSumLessThanK(int k);
	void printAncestorsWithoutRecursion(int key);
	int diff();
	void depthLeftLeaf();
	bool checkLeavesLevel();
	void extractLeaves();
	bool isBalancedLikeRedBlackHelper();

	void printAllNodesAtK(int node,int k);
	void printInVerticalOrder();
	void maxSumPathBetweenLeavesHelper();
	void reverseAlternateLevelsPerfectBT();
	bool areCousins(int node1,int node2);
	void sumLeftLeavesBT();
	void findMax();
	bool isSubtree();
	int findClosestLeafDistance(int key);
	void removeAllHalfNodes();
	void convertToDownRight();
	void convertToThreadedBT();
	void perfectBTSpecificLevelOrder();
};

#endif /* BINARYTREEGEEKS_H_ */
