/*

 * TripletBST.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


//Find if there is a triplet in a Balanced BST that adds to zero

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

//Step1:Convert BST to Sorted DLL with head and tail pointers
void convertBSTToDLL(struct node* root,struct node* &head,struct node* &tail){
	if(root==NULL){
		return;
	}
	convertBSTToDLL(root->left,head,tail);

	if(head==NULL){
		head=root;
	}
	else{
		tail->right=root;
		root->left=tail;
	}
	tail=root;
	convertBSTToDLL(root->right,head,tail);
}

//Print converted DLL
void printDLL(struct node* head,struct node* tail){
	while(head){
		cout<<head->data<<"<->";
		head=head->right;
	}
}

bool hasSum(struct node* head,int sum,struct node* tail){
	while(head!=tail){
		int subsum=head->data+tail->data;
		if(subsum==sum){
			return true;
		}
		else{
			if(subsum<sum){
				head=head->right;
			}
			else{
				tail=tail->left;
			}
		}
	}

	return false;
}

//Is triplet present
bool isTripletPresent(struct node* head,struct node* tail){
	while(head->right!=tail){
		if(head->data<0 && hasSum(head->right,-1*(head->data),tail)){
			return true;
		}
		else{
			head=head->right;
		}
	}
	return false;
}
int main(){
	struct node* root = NULL;
	struct node* head=NULL;
	struct node* tail=NULL;
	root = insert(root, 6);
	root = insert(root, -13);
	root = insert(root, 14);
	root = insert(root, -8);
	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 7);

	root = insert(root, 3);
				root = insert(root, 0);
				root = insert(root, 9);
				root = insert(root, 11);


	convertBSTToDLL(root,head,tail);
	printDLL(head,tail);
	cout<<"Triplet present "<<isTripletPresent(head,tail)<<endl;
}
*/
