/*

 * StackUsingQueues.cpp
 *
 *  Created on: Aug 20, 2015
 *      Author: user

#include<queue>
#include<iostream>
using namespace std;

queue<int> q1;
queue<int> q2;
void push(int data){
	if(q1.empty()){
		q1.push(data);
	}
	else{
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(data);
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
	}
}

int pop(){
	if(!q1.empty()){
		int tmp=q1.front();
		q1.pop();
		return tmp;
	}
	return -1;
}

int top(){
	if(!q1.empty()){
		int tmp=q1.front();
		return tmp;
		}
	return -1;
}

int main(){
	push(1);
	cout<<"Top is "<<top()<<endl;
	push(3);
	pop();

	cout<<"Top is "<<top()<<endl;
	push(5);
	cout<<"Top is "<<top()<<endl;
	push(7);
	cout<<"Top is "<<top()<<endl;
}
*/
