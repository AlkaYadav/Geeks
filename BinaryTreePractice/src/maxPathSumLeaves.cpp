/*

 * maxPathSumLeaves.cpp
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

int maxSumPathLeaves(struct Node* root,int& maxsum){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	int ls=maxSumPathLeaves(root->left,maxsum);
	int rs=maxSumPathLeaves(root->right,maxsum);
	int curr_sum=ls+rs+root->data;
	if(curr_sum>maxsum){
		maxsum=curr_sum;
	}
	return root->data+max(ls,rs);
}


int main() {
	struct Node* root=NULL;

	root=newNode(-15);
	 root->left = newNode(5);
	    root->right = newNode(6);
	    root->left->left = newNode(-8);
	    root->left->right = newNode(1);
	    root->left->left->left = newNode(2);
	    root->left->left->right = newNode(6);
	    root->right->left = newNode(3);
	    root->right->right = newNode(9);
	    root->right->right->right= newNode(0);
	    root->right->right->right->left= newNode(4);
	    root->right->right->right->right= newNode(-1);
	    root->right->right->right->right->left= newNode(10);
	    int maxsum=INT_MIN;
	    cout<<maxSumPathLeaves(root,maxsum);
	    cout<<"Maxsum is "<<maxsum<<endl;
}

*/
