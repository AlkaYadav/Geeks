/*
 * GreatTreeListRecursion.h
 *
 *  Created on: Jul 30, 2015
 *      Author: user
 */

#ifndef GREATTREELISTRECURSION_H_
#define GREATTREELISTRECURSION_H_
#include<iostream>
using namespace std;

class BSTNode{
	BSTNode* left;
	BSTNode* right;
	int data;
	friend class BST;
};

class BST{
	BSTNode* root;
	BSTNode * insert(int newdata);
	void printCircularLinkedList(BSTNode *head);
	BSTNode * append(BSTNode* node1,BSTNode* node2);
	BSTNode* convertTreeToCircularLinkedListHelper(BSTNode *root);
public:
	BST();
	void insertRandom();
	void convertTreeToCircularLinkedList();
};




#endif /* GREATTREELISTRECURSION_H_ */
