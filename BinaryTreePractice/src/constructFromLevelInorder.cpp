/*

 * constructFromLevelInorder.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user


//Construct a tree from Inorder and Level order traversals
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

int findInInorder(int item,int in[],int start,int end){
	for(int i=start;i<=end;i++){
		if(in[i]==item){
			return i;
		}
	}
	return -1;
}

int *extractKeys(int in[],int start,int end,int level[],int n){
	int *ll=new int[end-start+1];
	int j=0;
	for(int i=0;i<n;i++){
		if(findInInorder(level[i],in,start,end)!=-1){
			ll[j++]=level[i];
		}
	}
	return ll;
}
//n is size of level order
struct Node* constructFromLevelIn(int in[],int level[],int start,int end,int n){
	if(start>end){
		return NULL;
	}
	struct Node* root=newNode(level[0]);
	if(start==end){
		return root;
	}

	int inIndx=findInInorder(level[0],in,start,end);
	int *left_level=extractKeys(in,start,inIndx-1,level,n);
	int *right_level=extractKeys(in,inIndx+1,end,level,n);
	root->left=constructFromLevelIn(in,left_level,start,inIndx-1,n);
	root->right=constructFromLevelIn(in,right_level,inIndx+1,end,n);
	return root;
}

void inorder(struct Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main()
{
    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    Node *root = constructFromLevelIn(in,level,0,n-1,n);
    inorder(root);
}
*/
