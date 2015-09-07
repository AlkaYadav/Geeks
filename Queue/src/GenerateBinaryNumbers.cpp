/*
 * GenerateBinaryNumbers.cpp
 *
 *  Created on: Aug 20, 2015
 *      Author: user
 */

#include<queue>
#include<iostream>
#include<string>
using namespace std;
//An Interesting Method to Generate Binary Numbers from 1 to n

void generateBinaryNumbers(int n){
	queue<string> q;
	q.push("1");
	while(n--){
		string s1=q.front();
		q.pop();
		cout<<s1<<endl;
		string s2=s1;
		s1.append("0");
		q.push(s1);
		s2.append("1");
		q.push(s2);
	}
}

int main(){
	generateBinaryNumbers(9);
}
