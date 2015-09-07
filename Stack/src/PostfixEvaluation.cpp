/*

 * PostfixEvaluation.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user


#include<cstring>
#include<stdlib.h>
#include<iostream>
using namespace std;

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

bool isOperand(char a){
	if((a>='a'&& a<='z')||(a>='A' && a<='Z')){
		return true;
	}
	return false;
}

bool isOperator(char a){
	if(a=='^' || a=='*' || a=='+' || a=='-' || a=='/' ){
		return true;
	}
	return false;
}

int postfixEvaluation(char expr[],int n){
	struct Stack* s=createStack(n);
	for(int i=0;i<n;i++){
		if(isdigit(expr[i])){
			push(s,expr[i]-'0');
		}
		else if(isOperator(expr[i])){
			int val1=pop(s);
			int val2=pop(s);
			switch(expr[i]){
			case '+':
				push(s,val1+val2);
				break;
			case '-':
							push(s,val2-val1);
							break;
			case '*':
							push(s,val1*val2);
							break;
			case '/':
							push(s,val2/val1);
							break;
			case '^':
							push(s,val2^val1);
							break;
			default:
				break;

			}
		}
	}

	int result=pop(s);
	if(!isEmpty(s)){
		return -1;
	}
	return result;
}


int main(){
	char expr[]="231*+9-";
	int n=strlen(expr);
	cout<<"Result is :"<<postfixEvaluation(expr,n);
}

*/
