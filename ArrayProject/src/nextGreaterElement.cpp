/*

 * nextGreaterElement.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: user


#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<functional>
using namespace std;

void nextGreaterEle(int a[],int n){
	stack<int> s;
	s.push(a[0]);
	int next;
	for(int i=1;i<n;i++){
		 next=a[i];
		if(!s.empty()){
			int ele=s.top();
			s.pop();
			while(ele<next){
				cout<<ele<<" "<<next<<endl;
				if(!s.empty()){
					ele=s.top();
					s.pop();
				}
				else break;
			}
			if(ele>next){
				s.push(ele);
			}
			s.push(next);
		}
	}
	next=-1;
	while(!s.empty()){
		cout<<s.top()<<" "<<next<<endl;
		s.pop();
	}
}

int main()
{
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreaterEle(arr, n);
    getchar();
    return 0;
}
*/
