/*
//============================================================================
// Name        : LIS.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Longest Increasing Subsequence
//============================================================================

#include <iostream>
#include<limits.h>
using namespace std;

void lis(int arr[],int n){
	int lis[n];
	int res[n];//For Printing
	int index_lis;
	for(int i=0;i<n;i++){
		lis[i]=1;
		res[i]=-1;
	}
	//Filling lis
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]&& lis[j]+1>lis[i]){
				lis[i]=lis[j]+1;
				res[i]=j;
			}
		}
	}

	int max_lis=INT_MIN;
	for(int i=0;i<n;i++){
		if(lis[i]>max_lis){
			max_lis=lis[i];
			index_lis=i;
		}
	}
	cout<<"REs is"<<endl;
	for(int i=0;i<n;i++){
		cout<<res[i]<<" ";
	}
	cout<<"Index is "<<index_lis<<endl;

	while(index_lis!=-1){
		cout<<arr[index_lis]<<" ";
		index_lis=res[index_lis];
	}


	cout<<"MAximum LIS length is "<<max_lis<<endl;
}


int main() {
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	  int n = sizeof(arr)/sizeof(arr[0]);
	  lis(arr,n);
	return 0;
}
*/
