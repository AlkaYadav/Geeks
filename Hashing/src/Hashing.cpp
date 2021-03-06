/*
//============================================================================
// Name        : Hashing.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<map>
using namespace std;

void findSubset(int arr1[],int arr2[],int m,int n){
	//Create hash map for arr1
	map<int,int> mapHash;
	for(int i=0;i<m;i++){
		mapHash[arr1[i]]+=1;
	}
	map<int,int>::iterator it;
	for(it=mapHash.begin();it!=mapHash.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}

	for(int i=0;i<n;i++){
		if(!mapHash[arr2[i]]){
			cout<<"Not a subset";
		}
	}
}
int main() {
	int arr1[] = {11, 1, 13, 21, 3, 7};
	int arr2[] = {11, 3, 8, 1};
	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);
	findSubset(arr1,arr2,m,n);
	return 0;
}
*/
