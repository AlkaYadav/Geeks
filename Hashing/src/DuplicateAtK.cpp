
/*

 * DuplicateAtK.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: user


#include<map>
#include<iostream>
using namespace std;

void duplicateAtK(int arr[],int k,int n){
	map<int,int> map1;
	int count=0;
	for(int i=0;i<n;i++){
		if(map1[arr[i]]!=0){
			cout<<"Duplicate for number exists for "<<arr[i]<<endl;
		}
		if(i>=k){
			map1[arr[i-k]]=0;
			count=0;
		}

			map1[arr[i]]=1;
			count++;

	}
	cout<<"No duplicate"<<endl;
}

int main(){
	int  k = 3, arr[] = {1, 2, 3,1, 4, 1, 2, 3, 4};
	int n=sizeof(arr)/sizeof(arr[0]);
	duplicateAtK(arr,k,n);
}
*/
