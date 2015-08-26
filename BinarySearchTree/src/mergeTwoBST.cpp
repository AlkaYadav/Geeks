/*

 * mergeTwoBST.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


#include<stack>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	struct node* newinsnode=(struct node*)malloc(sizeof(struct node));
	newinsnode->data=data;
	newinsnode->left=NULL;
	newinsnode->right=NULL;
	return newinsnode;
}

struct node* insert(struct node* root,int data){
	if(root==NULL){
		return newNode(data);
	}
	if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else if(data>root->data){
		root->right=insert(root->right,data);
	}
	return root;
}

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}

}
void merge(struct node* root1,struct node* root2){
	if(root1==NULL || root2==NULL){
		return;
	}
	stack<struct node*> s1,s2;
	struct node* current1=root1;
	struct node* current2=root2;
	struct node* top1;
	struct node*  top2;
	while(current1 || current2 ||!s1.empty()||!s2.empty()){
		while(current1){
			s1.push(current1);
			current1=current1->left;
		}
		while(current2){
			s2.push(current2);
			current2=current2->left;
		}
		if(!s1.empty()&& !s2.empty()){
		top1=s1.top();
		top2=s2.top();
		if(top1->data<top2->data){
			//cout<<"In top1<top2"<<endl;
			cout<<top1->data<<" ";

				current1=top1->right;
			s1.pop();
		}
		else{
			//cout<<"In top1>top2"<<endl;
			cout<<top2->data<<" ";

				current2=top2->right;

			s2.pop();
		}
		}//End of empty
		else if(!s1.empty()){
			//cout<<endl<<"Stack 2 empty"<<endl;
			while(!s1.empty()){
			top1=s1.top();
			s1.top()->left=NULL;

			inorder(s1.top());
			s1.pop();
			}
		}
		else if(!s2.empty()){
			//cout<<"Stack 1 empty"<<endl;
			while(!s2.empty()){
					top2=s2.top();
					s2.top()->left=NULL;

					inorder(s2.top());
					s2.pop();
				}
		}
		else break;
	}
}

int main(){
	struct node * root1=NULL;
	struct node * root=NULL;
	root = insert(root, 8);
		root = insert(root, 2);
		root = insert(root, 1);
		root = insert(root, 10);
		root = insert(root, 15);
		root = insert(root, 13);
		root = insert(root, 7);
		inorder(root);
		cout<<endl;
		root1 = insert(root1, 3);
		root1 = insert(root1, 0);
		root1 = insert(root1, 9);
		root1 = insert(root1, 11);
		inorder(root1);
		cout<<endl;
		merge(root1,root);

}
*/
