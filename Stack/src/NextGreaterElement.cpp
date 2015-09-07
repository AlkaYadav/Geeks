/*

 * NextGreaterElement.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user


#include<stack>
#include<iostream>

using namespace std;

//The Next greater Element for an element x is the first greater element on the right side of x in array.
void nextGreaterRightElement(int a[],int n){
	stack<int> s;
	int next;
	for(int i=0;i<n;i++){
		s.push(a[i]);
	}
	next=s.top();
	int prev_popped=s.top();
	s.pop();
	cout<<"Next is "<<next<<endl;
	while(!s.empty()){

		//cout<<" Element "<<top1<<" and next grater :"<<next;

		if(s.top()<prev_popped){
			cout<<" Element "<<s.top()<<" and next grater :"<<prev_popped<<endl;
		}
		else{
			if(next>s.top())
			cout<<" Element "<<s.top()<<" and no next grater :"<<next<<endl;
		}
		prev_popped=s.top();
		if(prev_popped>next){
			next=prev_popped;
		}
		s.pop();
	}
}


int main(){
	int arr[]= {11, 13, 21, 17,9,4,25,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	nextGreaterRightElement(arr,n);
}

*/
