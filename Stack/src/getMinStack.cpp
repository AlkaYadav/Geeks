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
#include<stack>
using namespace std;

//Stack Implementation using array

stack<int> minstack;
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

int getMin(){
	if(!minstack.empty()){
		return minstack.top();
	}
	return INT_MAX;
}
void push(struct Stack *s,int data){
if(!isFull(s)){
	s->top=s->top+1;
	s->arr[s->top]=data;
	if(data<getMin()){
		cout<<"Pushing data to minstack "<<data<<"as minimum currently is "<<getMin()<<endl;
		minstack.push(data);
	}
	else{
		minstack.push(minstack.top());
	}
}
}

int top(struct Stack *s){
	if(!isEmpty(s)){
		return s->arr[s->top];
	}
	return -1;
}
int pop(struct Stack *s){
	if(!isEmpty(s)){
		cout<<"Popping Min stack data "<<minstack.top()<<"and stack top is "<<top(s)<<endl;

			cout<<"Min stack data pop "<<minstack.top()<<endl;
			minstack.pop();

		return s->arr[s->top--];
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
	//cout<<"Minimum element is "<<getMin()<<endl;
	cout<<"Again Top: "<<top(s)<<endl;
	cout<<"Pop 3: "<<pop(s)<<endl;
	cout<<"Pop 2: "<<pop(s)<<endl;
	cout<<"Pop 1: "<<pop(s)<<endl;
	//cout<<"Pop: "<<pop(s)<<endl;
	return 0;
}


*/
