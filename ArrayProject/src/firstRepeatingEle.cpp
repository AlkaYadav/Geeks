/*

 * firstRepeatingEle.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user


//Find the first repeating element in an array of integers
#include<iostream>
#include<limits.h>
#include<map>
using namespace std;
void findFirstRepeating(int arr[],int n){
	map<int,int> m;
	int min_i=INT_MAX;
	for(int i=0;i<n;i++){
		if(m[arr[i]]){
			min_i=min(min_i,m[arr[i]]-1);
			//break;
		}
		else m[arr[i]]=i+1;
	}
	cout<<"First epe "<<arr[min_i]<<endl;
}


int main(){
	int ar1[] = {10, 5, 3, 4, 3, 5, 6};

	int n1=sizeof(ar1)/sizeof(ar1[0]);


	findFirstRepeating(ar1,n1);
}
*/
