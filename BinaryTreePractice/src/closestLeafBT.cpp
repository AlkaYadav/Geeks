/*

 * closestLeafBT.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<vector>
#include<queue>
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

void printAncestors(vector<struct Node* > ancestors){
	vector<struct Node* >::iterator it;
	for(it=ancestors.begin();it!=ancestors.end();it++){
		struct Node*tmp=*it;
		cout<<tmp->data<<" ";
	}
	cout<<endl;
}
void storeInVector(struct Node* ancestors[],vector<struct Node*>& v_ancest,int indx){
	for(int i=0;i<=indx;i++){
		v_ancest.push_back(ancestors[i]);
	}
	cout<<"In func "<<endl;
	printAncestors(v_ancest);
}

void storeAncestorArray(struct Node* root,int key,struct Node* ancestors[],int indx,vector<struct Node*>& v_ancest){
	if(root==NULL){
		return ;
	}
	ancestors[indx]=root;
	if(root->data==key){
		storeInVector(ancestors,v_ancest,indx);
		return ;
	}
	storeAncestorArray(root->left,key,ancestors,indx+1,v_ancest);
	storeAncestorArray(root->right,key,ancestors,indx+1,v_ancest);


}

int findClosestDown(struct Node* root){
	if(root==NULL){
		return INT_MAX;
	}
	if(root->left==NULL&& root->right==NULL){
		return 0;
	}
	int l=findClosestDown(root->left);
	int r=findClosestDown(root->right);
	return 1+min(l,r);

}

void closestLeafBT(struct Node* root,int key){
	struct Node* ancestors[40];
	int indx=0;
	vector<struct Node*> v_ancest;
	vector<struct Node*>::iterator it;
	storeAncestorArray(root,key,ancestors,indx,v_ancest);
	cout<<"Ancestors are "<<endl;
	printAncestors(v_ancest);
	struct Node* target=v_ancest[v_ancest.size()-1];
	v_ancest.pop_back();
	int dist=findClosestDown(target);
	int i=1;
	cout<<"Distance from target "<<target->data<<" is "<<dist<<endl;
	for(it=v_ancest.begin();it!=v_ancest.end();it++){
		dist=min(dist,i+findClosestDown(*it));
	}
	cout<<"Minimum dist is "<<dist<<endl;

}

int main() {
	struct Node* root=NULL;

	root=newNode(1);
	root->left               = newNode(2);
	root->right              = newNode(3);
	root->right->left        = newNode(5);
	root->right->right       = newNode(6);
	root->right->left->left  = newNode(7);
	root->right->left->left->left  = newNode(9);
	root->right->left->left->right = newNode(8);
	root->right->right->right      = newNode(4);
	root->right->right->right->left = newNode(10);

	    closestLeafBT(root,4);
	    closestLeafBT(root,7);
	    closestLeafBT(root,2);
}
*/
