/*

 * InfixToPostfix.cpp
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

int prec(char a){
	switch(a){
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 2;
	case '^':return 3;
	default: return 0;
	}
}
void infixToPostfix(char expr[],int n){
	int i=0,k=-1;
	struct Stack *s;
	s=createStack(n);

	for(i=0,k=-1;expr[i];++i){
		if(isOperand(expr[i])){
			expr[++k]=expr[i];
		}
		else if(isOperator(expr[i])){
			if(isEmpty(s)){
				push(s,expr[i]);
			}
			else{
				while(!isEmpty(s) && prec(top(s)) >= prec(expr[i])){
					expr[++k]=pop(s);
				}
				push(s,expr[i]);
			}
		}

		else if(expr[i]=='('){
			push(s,expr[i]);
		}
		else if(expr[i]==')'){
			while(!isEmpty(s) && top(s)!='('){
				expr[++k]=pop(s);
			}
			if(!isEmpty(s)&& top(s)!='('){
				return ;
			}
			else
			pop(s);
		}
	}

	while(!isEmpty(s)){
		expr[++k]=pop(s);
	}

expr[++k]='\0';

}

int main(){
	char expr[]="a+b*(c^d-e)^(f+g*h)-i";
	int n=strlen(expr);
	infixToPostfix(expr,n);
	cout<<"Postfix is "<<expr<<endl;

}
*/
