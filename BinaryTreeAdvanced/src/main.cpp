/*
 * main.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: user
 */

#include "BinaryTreeAdvanced.h"
#include "treeFromTwoTraversals.h"
#include "GeneralBinaryTree.h"

int main(){
	BinaryTree bt;
	treeFromTwoTraversals tree;
	GeneralBinaryTree gbt;
/*
	bt.insertRandom();
	bt.printPathSum(20);
	cout<<"Diamter of binary tree is "<<bt.diameter()<<endl;
	cout<<"Diamter of binary tree using optimized method is "<<bt.diameterOptimized()<<endl;

	cout<<"Check for Child sum property "<<bt.checkForChildSumProperty()<<endl;
	cout<<"Convert"<<endl;
	bt.converttoChildSumTree();
	bt.inorder();
	cout<<endl<<"Check if tree is height balanced "<< bt.checkIfBTHeightBalanced()<<endl;
	cout<<endl<<"Check if tree is height balanced using optimized"<< bt.checkIfBTHeightBalancedOptimized()<<endl;

	//int inorder[6]={4,2,5,1,6,3};
	int inorder[7]={4,8,10,12,14,20,22};
	int levelorder[7] = {20,8,22,4,12,10,14};
	int preorder[6]={1,2,4,5,3,6};
	int postorder[6]={4,5,2,6,3,1};
	//int levelorder[6]={1,2,3,4,5,6};
	//tree.constructtreeFromInAndPre(inorder,preorder,6);

	cout<<"Printing..."<<endl;
	tree.constructtreeFromInAndPost(inorder,postorder,6);

	cout<<"Construct tree from in and level"<<endl;
	tree.constructtreeFromInAndLevel(inorder,levelorder,7);
	cout<<"Inorder traversal without recursion"<<endl;
	tree.inOrderTraversalWithoutRecursion();
	cout<<"Preorder traversal without recursion"<<endl;
	tree.preOrderTraversalWithoutRecursion();
	cout<<"Postorder traversal without recursion"<<endl;
	tree.postOrderTraversalWithoutRecursion();
	cout<<"Postorder traversal without recursion using only one stack"<<endl;
		tree.postOrderTraversalUsingOneStack();
		*/

	cout<<endl<<"Construct tree from preorder and postorder traversal"<<endl;
	int pre[]={1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[]={8, 9, 4, 5, 2, 6, 7, 3, 1};
	//int pre[]={1, 2,3};
	//	int post[]={2, 3, 1};
	tree.constructTreeFromPreAndPost(pre,post,9);
	tree.inOrderTraversalWithoutRecursion();

	cout<<"GeneralBinaryTree Operations ..."<<endl;
/*
	gbt.insertRandom();
	/*
	gbt.doubleTree();
	cout<<endl<<"Max width of binary tree is "<<gbt.maxWidth()<<endl;
	cout<<endl<<"Max width of binary tree using preorder is "<<gbt.maxWidthPreorder()<<endl;
	cout<<endl<<"Level of a node in a binary tree with provided data is "<<gbt.getLevelOfNode(6)<<endl;
	cout<<endl<<"Check if a binary tree is foldable "<<gbt.isFoldable()<<endl;

	cout<<endl<<"Print nodes at distance k from root "<<endl;
	gbt.printNodesAtDistanceKFromRoot(2);
	cout<<endl<<"Print ancestors of a node"<<endl;
	gbt.printAncestorsOfNode(9);

	cout<<endl<<"Check if binary tree is sum tree "<<gbt.ifSumTree()<<endl;
	cout<<endl<<"Convert a binary tree to sum tree "<<endl;

	cout<<endl<<"Check if a binary tree is a subtree of another "<<gbt.checkIfSubtree()<<endl;
	gbt.convertToSum();

	cout<<endl<<"Populating inorder successor "<<endl;
	gbt.populateInorderSuccessor();

	cout<<endl<<"Connect nodes at same level "<<endl;
	gbt.connectNodesAtSameLevel();

	cout<<endl<<"Connect nodes at same level with constant storage"<<endl;
	gbt.connectNodesSameLevelConstantStorage();

	cout<<endl<<"Vertical sum in a binary tree "<<endl;
	gbt.verticalSum();
	cout<<endl<<"Find the maximum sum path from root to leaf in a binary tree "<<endl;
	gbt.findMaximumSumRootToLeafPath();

	cout<<endl<<"Construct a special binary tree from  given preorder traversal"<<endl;
	int pre[] = {10, 30, 20, 5, 15};
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
		gbt.constructTreeFromPreorder(pre,preLN,5);

	cout<<endl<<"Check if a binary tree is complete"<<gbt.isCompleteBinaryTree()<<endl;
	cout<<endl<<"Print reverse level order traversal"<<endl;
	gbt.reverseLevelOrderTraversal();

	cout<<endl<<"Iterative height of binary tree "<<gbt.iterativeHeight()<<endl;

	cout<<endl<<"Boundary traversal of binary tree "<<endl;
	gbt.boundaryTraversal();
	*/

//	cout<<"is Isomorphic "<<gbt.isIsomorphic()<<endl;

}

