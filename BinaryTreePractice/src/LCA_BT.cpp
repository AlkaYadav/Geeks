/*
 * LCA_BT.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: user
 */

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
bool findPath(struct Node* root,int node1){
	if(root==NULL){
		return false;
	}

	if(root->data==node1){
		return true;
	}
	if(findPath(root->left,node1) || findPath(root->right,node1)){
		return true;
	}

	return false;
}

struct Node* findLCAHelper(struct Node* root,int node1,int node2,bool &v1,bool& v2){
	if(root==NULL){
		return NULL;
	}
	if(root->data==node1){
		v1=true;
		return root;
	}
	if(root->data==node2){
			v2=true;
			return root;
	}
	struct Node* left_lca=0;
	struct Node* right_lca=0;
	left_lca=findLCAHelper(root->left,node1,node2,v1,v2);
	right_lca=findLCAHelper(root->right,node1,node2,v1,v2);

	if(left_lca&& right_lca){
		return root;
	}
	return left_lca==NULL?right_lca:left_lca;
}

struct Node* findLCA(struct Node* root,int node1,int node2){
	bool v1=false;
	bool v2=false;
	struct Node* lca=findLCAHelper(root,node1,node2,v1,v2);
	if((v1&&v2) || (v1&&findPath(lca,node2)) || (v2&&findPath(lca,node1))){
		return lca;
	}
	return NULL;
}
int main() {
	struct Node* root=NULL;
	vector<int> path,path2;
	int node1,node2;
	root=newNode(20);
	root->left=newNode(8);
	root->right=newNode(22);
	root->left->left=newNode(4);
	root->left->right=newNode(12);
	root->left->right->left=newNode(10);
	root->left->right->right=newNode(14);
	cin>>node1>>node2;

	struct Node* lca=findLCA(root,node1,node2);
	if(lca){
		cout<<lca->data<<endl;
	}
	else{
		cout<<"No LCA"<<endl;
	}
}

