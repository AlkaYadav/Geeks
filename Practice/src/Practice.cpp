/*
//============================================================================
// Name        : Practice.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
#include<stack>
using namespace std;
//Convert infix to postfix

bool isOperand(char a){
	if((a>='a' && a<='z') || (a>='A' && a<='Z')){
		return true;
	}
	return false;
}

bool isOperator(char a){
	if(a=='+'|| a=='-' || a=='*' ||a=='/' || a=='^'){
		return true;
	}
	return false;
}

int prec(char a){
	switch(a){
	case '+':
	case '-':
		     return 1;
	case '*':
	case '/':
		     return 2;
	case '^':
		     return 3;
	default:
		    return 0;
	}
}
void convertInfixToPostfix(char expr[]){
	int n=strlen(expr);
	int k=-1;
	stack<char> s;
	for(int i=0;i<n;i++){
		if(isOperand(expr[i])){
			expr[++k]=expr[i];
		}
		else if(expr[i]=='('){
			expr[++k]=expr[i];
		}
		else if(expr[i]==')'){
			while(!s.empty() && s.top()!='('){
				expr[++k]=s.top();
				s.pop();
			}
			if(s.empty()&& s.top()!='('){
				return;
			}
			s.pop();
		}
		else if(isOperator(expr[i])){
			while(!s.empty() && prec(s.top())>=prec(expr[i])){
				expr[++k]=s.top();
				s.pop();
			}
			s.push(expr[i]);
		}
	}
while(!s.empty()){
	expr[++k]=s.top();
	s.pop();
}
	expr[++k]='\0';
}

int evaluatePostfix(char expr[]){
	int n=strlen(expr);
	stack<int> s;
	for(int i=0;i<n;i++){
		if(isdigit(expr[i])){
			s.push(expr[i]-'0');
		}
		else if(isOperator(expr[i])){
			int top2=s.top();
			s.pop();
			int top1=s.top();
			s.pop();
			int val;
			switch(expr[i]){
			case '+':
				val=top1+top2;
				s.push(val);
				break;
			case '-':
				val=top1-top2;
				s.push(val);
				break;
			case '*':
							val=top1*top2;
							s.push(val);
							break;
			case '/':
							val=top1/top2;
							s.push(val);
							break;

			}
		}
	}

	cout<<"Result is "<<s.top()<<endl;
	return s.top();
}

//Reverse a stack using recursion
void pushAtBottom(stack<int> &s,int item){
	if(s.empty()){
		s.push(item);
	}
	else{
		int tmp=s.top();
		s.pop();
		pushAtBottom(s,item);
		s.push(tmp);
	}
}
void reverse(stack<int> &s){
	if(!s.empty()){
		int tmp=s.top();
		s.pop();
		reverse(s);
		pushAtBottom(s,tmp);
	}
}

int main(){
	char expr[]="a+b*c/e";
	convertInfixToPostfix(expr);
	cout<<"Postfix is "<<expr<<endl;
	char expr[]="425*5/+";
	evaluatePostfix(expr);

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	reverse(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
*/
