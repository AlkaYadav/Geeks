/*

 * iterativePostorder.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user


#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<stack>
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

void iterativePostorder(struct Node* root){
	struct Node* current=root;
	stack<struct Node* > s;
	while(true){
		if(current){
			if(current->right){
				s.push(current->right);
				//cout<<"Pushing "<<current->right->data<<" "<<endl;
			}
			s.push(current);
			//cout<<"Pushing "<<current->data<<" "<<endl;
			current=current->left;
		}
		else{
			if(!s.empty()){
			struct Node* top=s.top();
			//cout<<"Processing top data "<<top->data<<endl;
			s.pop();

			if(top->right && !s.empty()&&s.top()==top->right){
				//cout<<"Process right "<<top->right->data<<endl;
				current=top->right;
				s.pop();
				s.push(top);
			}

			else{
				cout<<top->data<<" ";
				current=NULL;
			}


		}
			else{
				break;
			}
	}
	}
}

	int main(){
		struct Node* root = newNode(1);
		    root->left = newNode(2);
		    root->right = newNode(3);
		    root->left->left = newNode(4);
		    root->left->right = newNode(5);
		    root->right->left = newNode(6);
		    root->right->right = newNode(7);
		    iterativePostorder(root);
	}

*/
