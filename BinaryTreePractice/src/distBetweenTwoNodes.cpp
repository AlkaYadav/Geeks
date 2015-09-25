/*

 * distBetweenTwoNodes.cpp
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

struct Node* findDistHelper(struct Node* root,int node1,int node2,int &d1,int& d2,int lvl,int& dist){
	if(root==NULL){
		return NULL;
	}
	if(root->data==node1){
		d1=lvl;
		return root;
	}
	if(root->data==node2){
			d2=lvl;
			return root;
	}
	struct Node* left_lca=findDistHelper(root->left,node1,node2,d1,d2,lvl+1,dist);
	struct Node* right_lca=findDistHelper(root->right,node1,node2,d1,d2,lvl+1,dist);
	if(left_lca&& right_lca){
		dist=d1+d2-2*lvl;
		return root;
	}
	return (left_lca != NULL)? left_lca: right_lca;
}
int findLvl(struct Node* root,int node2,int lvl){
	if(root==NULL){
		return -1;
	}
	if(root->data==node2){
		return lvl;
	}
	int l=findLvl(root->left,node2,lvl+1);
	if(l==-1){
		return findLvl(root->right,node2,lvl+1);
	}
	return l;
}
int findDist(struct Node* root,int node1,int node2){
	int d1=-1,d2=-1;
	int lvl=1,dist=-1;
	struct Node* lca=findDistHelper(root,node1,node2,d1,d2,lvl,dist);
	if(d1!=-1 && d2!=-1){
		return dist;
	}
	if(d1!=-1){
		dist=findLvl(lca,node2,1);

	}
	if(d2!=-1){
			dist=findLvl(lca,node1,1);
		}
	return dist;
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
	int dist=findDist(root,node1,node2);
	cout<<dist<<endl;
}


*/
