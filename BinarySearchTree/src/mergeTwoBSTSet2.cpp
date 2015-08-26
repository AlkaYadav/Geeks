/*



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

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}

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

void printDLL(struct node* head,struct node* tail){
	if(head){
		cout<<head->data<<"<->";
		head=head->right;
	}
}

struct node* mergeTwoSortedDLL(struct node* curr1,struct node* curr2){
	struct node dummy;
	struct node* target=&dummy;
	target->left=NULL;
	target->right=NULL;


	while(curr1 && curr2){
		if(curr1->data<curr2->data){
			target->right=curr1;
			curr1->left=target;
			target=curr1;
			if(curr1->right){
			curr1->right->left=NULL;
			}
			curr1=curr1->right;
			target->right=NULL;
		}
		else
		{
			target->right=curr2;
			curr2->left=target;
			target=curr2;
			if(curr2->right){
			curr2->right->left=NULL;
			}
			curr2=curr2->right;
			target->right=NULL;
		}
	}
	if(curr1){
		target->right=curr1;
		curr1->left=target;
	}
	if(curr2){
		target->right=curr2;
		curr2->left=target;
	}
	cout<<"Printing target..."<<endl;
	while(target->right){
		cout<<target->data<<" ";
		target=target->right;
	}
	cout<<"Ending target..."<<endl;
	return target;
}

struct node* mergeTwoSortedDLL_Recursion(struct node* curr1,struct node* curr2){
	struct node* target=NULL;
	if(curr1==NULL){
		return curr2;
	}
	if(curr2==NULL){
		return curr1;
	}
	if(curr1->data<=curr2->data){

		target=curr1;
		curr1=curr1->right;
		if(curr1){
			curr1->left=NULL;
		}
		target->right=mergeTwoSortedDLL_Recursion(curr1,curr2);
	}
	else {
		target=curr2;

				curr2=curr2->right;
				if(curr2){
					curr2->left=NULL;
				}
				target->right=mergeTwoSortedDLL_Recursion(curr1,curr2);
	}
	return target;
}
int main(){
	struct node * root1=NULL;
	struct node *head1=NULL;
	struct node * tail1=NULL;
	struct node * target=NULL;
		struct node * root2=NULL;
		struct node * head2=NULL;
		struct node * tail2=NULL;
		root2 = insert(root2, 8);
			root2 = insert(root2, 2);
			root2 = insert(root2, 1);
			root2 = insert(root2, 10);
			root2 = insert(root2, 15);
			root2 = insert(root2, 13);
			root2 = insert(root2, 7);
			//inorder(root2);
			convertBSTToDLL(root2,head2,tail2);
			cout<<"LISt 2 Printing...."<<endl;
			printDLL(head2,tail2);

			cout<<endl;
			root1 = insert(root1, 3);
			root1 = insert(root1, 0);
			root1 = insert(root1, 9);
			root1 = insert(root1, 11);
			//inorder(root1);
			cout<<endl;

			convertBSTToDLL(root1,head1,tail1);
			cout<<"LISt 1"<<endl;
			printDLL(head1,tail1);

			//target=mergeTwoSortedDLL(head1,head2);
			target=mergeTwoSortedDLL_Recursion(head1,head2);
			while(target->right){
				cout<<target->data<<" ";
				target=target->right;
			}
}
*/
