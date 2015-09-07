/*

 * ReverseString.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user


#include<stack>
#include<cstring>
#include<iostream>
using namespace std;

void reverseString(char input[],int n){
	stack<char> s;
	for(int i=0;i<n;i++){
		s.push(input[i]);
	}
	int index=0;
	while(!s.empty()){
		input[index++]=s.top();
		s.pop();
	}
input[index]='\0';
}

int main(){
	char input[]="abcdf";
	int n=strlen(input);
	reverseString(input,n);
	cout<<"REversed "<<input<<endl;
}
*/
