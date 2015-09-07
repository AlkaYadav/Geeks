/*
 * main.cpp
 *
 *  Created on: Jul 30, 2015
 *      Author: user
 */

#include <iostream>
#include"BinaryTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int option;
	char choice;
	BinaryTree bt;
	do{
		cout<<"1.Binary Tree"<<endl;
		cout<<"2.Determine if two trees are identical"<<endl;
		cout<<"3.Height of binary tree"<<endl;
		cout<<"4.Delete binary tree"<<endl;
		cout<<"5. Mirror the binary tree"<<endl;
		cout<<"6. Print all paths from root to leaf line by line";
		cout<<"7.Count leaf nodes in a binary tree"<<endl;

		cout<<"Enter option"<<endl;
		cin>>option;
		switch(option){
			case 1:
			  bt.insertRandom();
			  cout<<"Print in vertical order "<<endl;
			  bt.printVerticalOrderUSingHashMap();
			  bt.inorder();
			  cout<<"size is"<<bt.size()<<endl;
			  break;
		    case 2:

			  cout<<"Result is"<<bt.determineIfTwoTreesIdentical()<<endl;
			  break;
			case 3:
			   cout<<"Height is"<<bt.heightBinaryTree()<<endl;
			   break;
			case 4:
			   bt.deleteBinaryTree();
			   bt.inorder();
			   break;
			case 5:
				bt.mirrorBinaryTree();
				break;
			case 6:
				bt.printPathsRootToLeafOnePerLine();
				break;
			case 7:
				cout<<"Number of leaf nodes is="<<bt.countLeafNodes()<<endl;
				break;
			default:
			  break;
		}
		cout<<endl<<"Do you want to continue"<<endl;
		cin>>choice;
	}while(choice=='y'|| choice=='Y');
	return 0;
}


