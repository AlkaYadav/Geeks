/*
//============================================================================
// Name        : Stack.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;

//Stack Implementation using array
struct Stack{
	int top;
	unsigned int capacity;
	int *arr;
};

struct Stack * createStack(int c){
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity=c;
	stack->top=-1;
	stack->arr=(int *)malloc(c*sizeof(int));
	return stack;
}

bool isFull(struct Stack *s){
	return (s->top==s->capacity-1);
}

bool isEmpty(struct Stack *s){
	return s->top==-1;
}
void push(struct Stack *s,int data){
if(!isFull(s)){
	s->top=s->top+1;
	s->arr[s->top]=data;
}
}

int pop(struct Stack *s){
	if(!isEmpty(s)){
		return s->arr[s->top--];
	}
	return -1;
}

int top(struct Stack *s){
	if(!isEmpty(s)){
		return s->arr[s->top];
	}
	return -1;
}
int main() {
	struct Stack* s;
	s=createStack(20);
	push(s,1);
	cout<<"Top: "<<top(s)<<endl;
	push(s,2);
	cout<<"Top: "<<top(s)<<endl;
	push(s,3);
	cout<<"Top: "<<top(s)<<endl;

	cout<<"Pop: "<<pop(s)<<endl;
	cout<<"Pop: "<<pop(s)<<endl;
	cout<<"Pop: "<<pop(s)<<endl;
	cout<<"Pop: "<<pop(s)<<endl;
	return 0;
}
*/
