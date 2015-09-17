/*

 * kDistanceDuplicate.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user


//Check if a given array contains duplicate elements within k distance from each other
#include<iostream>
#include<limits.h>
#include<map>
using namespace std;

bool kDistanceDuplicates(int a[],int n,int k){
	map<int,int> m;
	for(int i=0;i<=k;i++){
		if(m[a[i]]){
			return true;
		}
		m[a[i]]+=1;
	}

	for(int j=k+1;j<n;j++){
		m.erase(a[j-k-1]);

		if(m[a[j]]){
			return true;
		}
		m[a[j]]+=1;
	}
	return false;
}

int main(){
	int ar1[] = {1, 2, 9, 1, 4, 5};

	int n1=sizeof(ar1)/sizeof(ar1[0]);
	cout<<kDistanceDuplicates(ar1,n1,3)<<endl;
}
*/
