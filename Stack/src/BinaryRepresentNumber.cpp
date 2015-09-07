/*

 * BinaryRepresentNumber.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user


#include<stack>
#include<cstring>
#include<iostream>
using namespace std;
//Print binary representation of a number

void binary(int num){
	stack<int> s;
	while(num>0){
		s.push(num%2);
		num=num/2;
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}


int main(){
	binary(16);

}
*/
