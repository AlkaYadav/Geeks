/*


 * ReverseUsingRecursion.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user

#include<stack>
#include<iostream>
using namespace std;

void insertAtBottom(stack<int> &s,int ele){
	if(s.empty()){
		s.push(ele);
	}
	else{
		int top1=s.top();
		s.pop();
		insertAtBottom(s,ele);
		s.push(top1);
	}
}
void reverseStackUsingRecursion(stack<int>& s){
	if(!s.empty()){
		int ele=s.top();
		s.pop();
		reverseStackUsingRecursion(s);
		insertAtBottom(s,ele);

	}
}

int main(){
	stack<int> s;
	s.push(5);
	s.push(2);
	s.push(3);
	s.push(4);
	reverseStackUsingRecursion(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
*/
