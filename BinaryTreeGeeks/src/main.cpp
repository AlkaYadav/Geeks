/*
 * main.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: user
 */
#include "BinaryTreeGeeks.h"
int main(){
	LinkedListToCompleteBinaryTree llcb;
	llcb.insertRandomLinkedList();
	llcb.linkedListToCompleteBinaryTree();
	/*
	cout<<"Converting binary tree to doubly linked list"<<endl;
	llcb.convertBinaryTreeToDoubly();
	cout<<"Converting binary tree to doubly linked list Set2"<<endl;
	llcb.convertBinaryTreeToDoublySet2();

	cout<<endl<<"Converting binary tree to doubly linked list Set1"<<endl;
	llcb.convertBinaryTreeToDoublySet1();
	llcb.insertCompleteBinaryTree();
	cout<<"Largest independent set is"<<llcb.LISS();

	cout<<"Lowest common Ancestor "<<endl;
	llcb.LCAPrint(10,55);
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<endl<<"Find distance between two given nodes in binary tree "<<llcb.findDist(36,15)<<endl;
	llcb.findSum();

	cout<<endl<<"Remove all nodes which don’t lie in any path with sum>= k"<<endl;
	llcb.removeAllPathsSumLessThanK(9);

	cout<<endl<<"Print ancestors of a node without recursion"<<endl;
	llcb.printAncestorsWithoutRecursion(6);

	cout<<endl<<"Difference between odd and even levels of a binary tree "<<llcb.diff()<<endl;
	cout<<endl<<"Depth of deepest odd level left leaf node a binary tree"<<endl;
	llcb.depthLeftLeaf();

	cout<<endl<<"Check if all leaves are at same level in a binary tree="<<llcb.checkLeavesLevel()<<endl;

	cout<<endl<<"Extract Leaves of a Binary Tree in a Doubly Linked List "<<endl;
	llcb.extractLeaves();

	cout<<endl<<"Check if a given Binary Tree is height balanced like a Red-Black Tree "<<llcb.isBalancedLikeRedBlackHelper();

	cout<<endl<<"Print all nodes at distance k from a given node "<<endl;
	llcb.printAllNodesAtK(8,5);

	cout<<endl<<"Print in Vertical Order"<<endl;
	llcb.printInVerticalOrder();

	cout<<endl<<"Maximum path sum between two leaves "<<endl;
	llcb.maxSumPathBetweenLeavesHelper();

	cout<<endl<<"Reverse alternate levels of a perfect BT "<<endl;
	llcb.reverseAlternateLevelsPerfectBT();
	cout<<endl<<"Check if two nodes are cousins in a Binary Tree"<<llcb.areCousins(7,5)<<endl;

	cout<<endl<<"Sum of all left leaves in a Binary Tree"<<endl;
	llcb.sumLeftLeavesBT();

	cout<<endl<<"Maximum in BT"<<endl;
	llcb.findMax();

	cout<<endl<<"Find the closest leaf distance in a Binary Tree."<<llcb.findClosestLeafDistance(8)<<endl;

	cout<<endl<<"Remove all half nodes "<<endl;
	llcb.removeAllHalfNodes();

	cout<<endl<<"Convert left-right representation of a binary tree to down-right"<<endl;
	llcb.convertToDownRight();

	cout<<endl<<"Convert a Binary Tree to Threaded binary tree"<<endl;
	llcb.convertToThreadedBT();
	*/
	cout<<endl<<"PerfectBT specific level order traversal"<<endl;
	llcb.perfectBTSpecificLevelOrder();
}


