/*
 * MorrisTraversal.h
 *
 *  Created on: Aug 3, 2015
 *      Author: user
 */

#ifndef MORRISTRAVERSAL_H_
#define MORRISTRAVERSAL_H_
#include "LevelOrderTraversal.h"
class MorrisTraversal{
	BinaryTreeNode *root;
	BinaryTreeNode * insert(int newdata);
public:
	MorrisTraversal();
	void insertRandom();
	void morrisTraversalInorder();
	void morrisTraversalPreorder();
};



#endif /* MORRISTRAVERSAL_H_ */
