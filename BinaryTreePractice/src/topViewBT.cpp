/*

 * topViewBT.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<vector>
#include<map>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* newNode(int data){
	struct Node* new_n=(struct Node* )malloc(sizeof(struct Node));
	new_n->data=data;
	new_n->left=NULL;
	new_n->right=NULL;
	return new_n;
}

void printTopView(struct Node* root,int HD,map<int,int>& m){
	if(root==NULL){
		return;
	}
	printTopView(root->left,HD-1,m);
	printTopView(root->right,HD+1,m);
	m[HD]=root->data;
}

int main() {
	struct Node* root=NULL;

	root=newNode(1);
	root->left               = newNode(2);
	root->right              = newNode(3);
	root->left->right       = newNode(4);
	root->left->right->right       = newNode(5);
	root->left->right->right->right  = newNode(6);
	map<int,int> m;
	map<int,int>::iterator it;
	printTopView(root,0,m);
	for(it=m.begin();it!=m.end();it++){
		cout<<it->second<<" ";
	}

}
*/
