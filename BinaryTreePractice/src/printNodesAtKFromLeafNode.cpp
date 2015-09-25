/*

 * printNodesAtKFromLeafNode.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: user

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
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

void printNodesAtDistanceKFromLeafNode(struct Node* root,int k,int path[],int indx,bool visited[]){
	if(root==NULL){
		return ;
	}
	path[indx]=root->data;

	//indx++;
	if(root->left==NULL && root->right==NULL){
		if(indx-k>=0){
			if(!visited[indx-k]){
				visited[indx-k]=true;
				cout<<path[indx-k]<<endl;
				return;
			}
		}
	}

	printNodesAtDistanceKFromLeafNode(root->left,k,path,indx+1,visited);
	printNodesAtDistanceKFromLeafNode(root->right,k,path,indx+1,visited);

}
int main() {
	struct Node* root=NULL;
	int path[20];
	int k;
	bool visited[20]={false};
	root=newNode(20);
	root->left=newNode(8);
	root->right=newNode(22);
	root->left->left=newNode(4);
	root->left->right=newNode(12);
	root->left->right->left=newNode(10);
	root->left->right->right=newNode(14);
	cin>>k;
	printNodesAtDistanceKFromLeafNode(root,k,path,0,visited);
}
*/
