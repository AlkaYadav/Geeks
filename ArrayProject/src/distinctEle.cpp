/*

 * distinctEle.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

//Print All Distinct Elements of a given integer array
#include <map>
#include<iostream>
using namespace std;
void printDistinct(int arr[],int n){
	map<int,int> m;
	for(int i=0;i<n;i++){
		m[arr[i]]+=1;
	}
	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout<<it->first<<" ";
	}
}


int main(){
	int arr[] = {12, 10, 9, 45, 2, 10, 10, 45};
	int n=sizeof(arr)/sizeof(arr[0]);
	printDistinct(arr,n);
}
*/
