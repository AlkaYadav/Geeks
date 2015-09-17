/*

 * isPalindromeList.cpp
 *
 *  Created on: Sep 9, 2015
 *      Author: user


#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};

Node* newNode(int data){
	struct Node* tmp=(struct Node*)malloc(sizeof(struct Node));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}
void insertAtFront(struct Node** head,int data){
	if(*head==NULL){
		*head=newNode(data);

	}
	else{
		Node*tmp=newNode(data);
		tmp->next=*head;
		*head=tmp;
	}
}
bool isPAlindromeList(struct Node* head){
	stack<int> s;
	struct Node* curr=head;
	while(head){
		s.push(head->data);
		head=head->next;
	}
	while(curr){
		if(curr->data==s.top()){
			s.pop();
			curr=curr->next;
		}
		else
			return false;
	}
	return true;
}

void reverse_Iterative(struct Node** head){
	struct Node* prev=NULL;
	struct Node* tmp=*head;
	struct Node* next;
	while(tmp){
		next=tmp->next;
		tmp->next=prev;
		prev=tmp;
		tmp=next;
	}
	*head=prev;
}

bool isPalindrome_ByReverse(struct Node* head){
//Find middle of list
	struct Node* slow_ptr=head;
	struct Node* fast_ptr=head;
	while(slow_ptr&& fast_ptr&& fast_ptr->next){
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
	}
	//Now mid node is at slowptr;
	reverse_Iterative(&slow_ptr);
	//Now check for palindrome
	struct Node* mid=slow_ptr;
	int flag=1;
	while(slow_ptr){
		if(head->data==slow_ptr->data){
			head=head->next;
			slow_ptr=slow_ptr->next;
		}
		else{
			flag=0;
			cout<<"Not Palindrome ...";
			break;
		}
	}

	reverse_Iterative(&mid);
	if(flag==1){
		cout<<"Is a Palindrome"<<endl;
		return true;
	}
	else{
		return false;
	}

}
int main(){
	struct Node* head=NULL;
	insertAtFront(&head,1);
	insertAtFront(&head,3);
	insertAtFront(&head,3);
	insertAtFront(&head,3);
	insertAtFront(&head,2);
	insertAtFront(&head,1);
cout<<isPalindrome_ByReverse(head)<<endl;
}



*/
