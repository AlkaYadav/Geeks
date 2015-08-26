/*

 * convertToBalancedBST.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


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

struct node* sortedArrayToBalancedBST(int arr[],int start ,int end){
if(start==end){
	return newNode(arr[start]);
}
if(start>end){
	return NULL;
}
int mid=(start+end)/2;
struct node* root=newNode(arr[mid]);
root->left=sortedArrayToBalancedBST(arr,start,mid-1);
root->right=sortedArrayToBalancedBST(arr,mid+1,end);
return root;
}

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";

		inorder(root->right);
	}
}

//Largest BST subtree in a given BT
int size(struct node* root){
	if(root==NULL){
		return 0;
	}
	return size(root->left)+size(root->right)+1;
}
bool isBSTHelper(struct node* root,int min,int max){
	if(root==NULL){
		return true;
	}
	if(root->data<min || root->data>max){
		return false;
	}
	return isBSTHelper(root->left,min,root->data-1) && isBSTHelper(root->right,root->data+1,max);
}
bool isBST(struct node* root){
	if(root){
		return isBSTHelper(root,INT_MIN,INT_MAX);
	}
	return true;
}
int largestBSTinBT(struct node* root){
	if(root==NULL){
		return 0;
	}
	if(isBST(root)){
		return size(root);
	}
	return max(largestBSTinBT(root->left),largestBSTinBT(root->right));
}

//Add all greater values to every node in a given BST
void modifyTree(struct node* &root){
	static int sum=0;
	if(root){
		modifyTree(root->right);
		sum+=root->data;
		root->data=sum;
		modifyTree(root->left);
	}
}

//Remove BST keys outside a given range
struct node *removeBSTKeysOutsideRange(struct node* root,int minrange,int maxrange){
	if(root==NULL){
		return NULL;
	}
	root->left=removeBSTKeysOutsideRange(root->left,minrange,maxrange);
	root->right=removeBSTKeysOutsideRange(root->right,minrange,maxrange);
	if(root->data<minrange){
		struct node* noderight=root->right;
		root->left=NULL;
		free(root);
		return noderight;
	}
	if(root->data>maxrange){
		struct node* nodeleft=root->left;
		root->right=NULL;
		free(root);
		return nodeleft;
	}
	return root;
}

//Given Preorder check if each internal node has exactly one child
bool preorderInternalNode(int pre[],int n){
	for(int i=0;i<n-1;i++){
		int first=pre[i]-pre[i+1];
		int last=pre[i]-pre[n-1];
		if(first* last<0){
			return false;
		}
	}
	return true;
}
int main(){
	struct node* root=NULL;
	int arr[]={1,2,3,4,5};
	int len=sizeof(arr)/sizeof(int);
	root=sortedArrayToBalancedBST(arr,0,len-1);

	inorder(root);
	cout<<endl<<"Size of largest BST in BT is "<<largestBSTinBT(root)<<endl;
	cout<<"====================================================================="<<endl;
	//modifyTree(root);
	cout<<"====================================================================="<<endl;
	int minrange=0;
	int maxrange=3;
	cout<<"Remove BST keys outside the given range"<<endl;
	root=removeBSTKeysOutsideRange(root,minrange,maxrange);
	inorder(root);
	cout<<"====================================================================="<<endl;
	cout<<endl<<"Given Preorder check if each internal node has exactly one child"<<endl;
	int pre[]={20, 10, 11, 12,13, 9};
	len=sizeof(pre)/sizeof(int);
	cout<<"Result: "<<preorderInternalNode(pre,len)<<endl;
}
*/
