/*
//============================================================================
// Name        : BinaryTreePractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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

bool findPath(struct Node* root,int node1,vector<int>& path){
	if(root==NULL){
		return false;
	}
	path.push_back(root->data);
	if(root->data==node1){
		return true;
	}
	if(findPath(root->left,node1,path) || findPath(root->right,node1,path)){
		return true;
	}
	path.pop_back();
	return false;
}

int findLCA(vector<int> path,vector<int> path2){
	vector<int>::iterator it1,it2;
	int lca;
	cout<<"Print path1"<<endl;
	for(it1=path.begin();it1!=path.end();it1++){
		cout<<*it1<<" ";
	}
	cout<<endl;

	cout<<"Print path2"<<endl;
		for(it2=path2.begin();it2!=path2.end();it2++){
			cout<<*it2<<" ";
		}
		cout<<endl;

	for(it1=path.begin(),it2=path2.begin();it1!=path.end()&& it2!=path2.end();it1++,it2++){
		if(*it1==*it2){
			lca=*it1;
		}
		else{
			break;
		}
	}
	return lca;
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

	if(findPath(root,node1,path) && findPath(root,node2,path2)){
		int lca=findLCA(path,path2);
		cout<<lca<<endl;
	}
	return 0;
}
*/
