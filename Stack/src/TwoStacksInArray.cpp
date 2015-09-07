/*

 * TwoStacksInArray.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user

//Implement two stacks in an array

#include<stack>
#include<cstring>
#include<iostream>
using namespace std;

const int n=3;
int top1=-1;
int top2=n;
int a[n];

void push1(int data){
	if((top1+1)!=top2){
		a[++top1]=data;
	}
	return;
}

void push2(int data){
	if((top2-1)!=top1){
		a[--top2]=data;
	}
	return;
}

int pop1(){
	if(top1>=0){
		return a[top1++];
	}
	return -1;
}

int pop2(){
	if(top2<n){
			return a[top2--];
		}
		return -1;
}

int top_1(){
	if(top1>=0){
		return a[top1];
	}
	return -1;
}

int top_2(){
	if(top2<n){
		return a[top2];
	}
	return -1;
}

int main(){
	push1(1);
	cout<<"top 1 "<<top_1()<<endl;
	push1(2);
	cout<<"top 1 "<<top_1()<<endl;
	push2(5);
	cout<<"top 2 "<<top_2()<<endl;
	push2(7);
	cout<<"top 2 "<<top_2()<<endl;
}
*/
