/*

 * InorderSuccessor.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

//Using Parent pointers
struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node* newNode(int data){
	struct node* newinsnode=(struct node*)malloc(sizeof(struct node));
	newinsnode->data=data;
	newinsnode->left=NULL;
	newinsnode->right=NULL;
	newinsnode->parent=NULL;
	return newinsnode;
}

struct node* insert(struct node* root,int data){
	if(root==NULL){
		return newNode(data);
	}
	struct node* tmp;
	if(data<=root->data){

		root->left=insert(root->left,data);
		root->left->parent=root;
	}
	else if(data>root->data){

		tmp=insert(root->right,data);
		root->right=tmp;
						tmp->parent=root;
	}
	return root;
}

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<"(p ";
		if(root->parent){
			cout<<root->parent->data<<")";
		}
		inorder(root->right);
	}
}

void inOrderSuccessor(struct node* root,int data,struct node* &succ){
	if(root==NULL){
		return;
	}
	if(data==root->data){
		if(root->right){
			succ=root->right;
			while(succ->left){
				succ=succ->left;
			}
		}
		return;
	}
	if(data<root->data){
		succ=root;
		inOrderSuccessor(root->left,data,succ);
	}
	if(data>root->data){
		inOrderSuccessor(root->right,data,succ);
	}

}

void inOrderSuccUsingParent(struct node* root,struct node* node,struct node* &succ){
	if(node->right){
		succ=node->right;
		while(succ->left){
			succ=succ->left;
		}
	}
	else{
		while(node->parent){
			if(node->parent->parent){
			if(node->parent->parent->left!=node->parent){
				node=node->parent;
			}

			else{
				succ=node->parent->parent;
				break;
			}
	}

}
}
}

//Find kth smallest element
void kthSmallestElement(struct node* root,int k,int &ele){
	static int count=0;
	if(root){
		kthSmallestElement(root->left,k,ele);
		count++;
		if(count==k){
			ele=root->data;
		}
		kthSmallestElement(root->right,k,ele);
	}
}


int main(){
	struct node* root=NULL;
	struct node* succ=NULL;
	int data;
	cout<<"Enter data to insert in BST"<<endl;
	for(int i=0;i<8;i++){
		cin>>data;
		root=insert(root,data);

	}
	inorder(root);
	cout<<endl<<"Enter the data for which inorder pred succ to be found"<<endl;
	cin>>data;
	//inOrderSuccessor(root,data,succ);
	inOrderSuccUsingParent(root,root->left->right->right,succ);
	if(succ){
		cout<<"succ is "<<succ->data<<endl;
	}

	int k,ele=0;
	cout<<"Find kth smallest element"<<endl;
	cin>>k;
	kthSmallestElement(root,k,ele);
	cout<<"Element is "<<ele<<endl;
}
*/
