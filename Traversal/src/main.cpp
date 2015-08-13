/*
 * main.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: user
 */
#include "LevelOrderTraversal.h"
#include "MorrisTraversal.h"
int main(){
	BinaryTree bt;
	bt.insertRandom();
	/*
	cout<<"Level order traversal is"<<endl;
    bt.levelOrderTraversal();
    bt.levelOrderTraversalUsingQueue();
    cout<<"Level traversal in spiral is below:"<<endl;
    bt.levelOrderTraversalInSpiral();
    cout<<"=================="<<endl;

    cout<<"Level traversal in spiral using stack is below:"<<endl;
    bt.levelOrderTraversalInSpiralUsingStack();
	*/
    MorrisTraversal mt;
    mt.insertRandom();
    mt.morrisTraversalInorder();
}
