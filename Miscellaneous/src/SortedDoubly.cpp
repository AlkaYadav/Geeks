/*

 * SortedDoubly.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: user



 * SortedDoubly.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: user




    Insert Node in a doubly sorted linked list
    After each insertion, the list should be sorted
   Node is defined as

#include<iostream>
#include<stdlib.h>
using namespace std;
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   };

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
    }
    else{
        //Case 1:Insert at head
    	Node* tmp=head;
        while(tmp){
            if(tmp->data>data){
                if(tmp->prev==NULL){
                	cout<<"Coming in 1"<<endl;
                    newnode->next=head;
                    head->prev=newnode;
                    newnode->prev=NULL;
                    head=newnode;
                    break;
                }
            }
            else if((tmp->next==NULL)&& tmp->data<=data){
                        	cout<<"Coming in "<<endl;
                            tmp->next=newnode;
                            newnode->prev=tmp;
                            newnode->next=NULL;

                            break;
                        }
            else if(tmp->next){
                if(tmp->data<=data && data<tmp->next->data){
                	cout<<"Coming in 2"<<endl;
                    Node* tmp_next=tmp->next;
                    tmp->next=newnode;
                    newnode->prev=tmp;
                    newnode->next=tmp_next;
                    tmp_next->prev=newnode;
                    break;
                }

            }

           tmp=tmp->next;
        }
        //Case 2:Insert at tail
        //Case 3:Normal insert
    }
    return head;
}
void printList(struct Node* head){
	while(head){
		cout<<head->data<<"->";
		head=head->next;
	}
}
int main(){
	struct Node* head=NULL;
	int data;
	for(int i=0;i<5;i++){
		cout<<"Enter data "<<endl;
		cin>>data;
		head=SortedInsert(head,data);
		cout<<"Printing list..."<<endl;
		printList(head);
	}

	return 0;
}



*/
