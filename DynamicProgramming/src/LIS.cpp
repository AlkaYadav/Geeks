/*
//============================================================================
// Name        : DynamicProgramming.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Longest Increasing Subsequence
//============================================================================

#include <iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

int longestIncreaingSubsequence(int arr[],int n){
	int *lis,i,j,max=0,max_lis,*res;
	lis=new int[n];
	res=new int[n];
	for(i=0;i<n;i++){
		lis[i]=1;
		res[i]=-1;
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){

			if(arr[j]<arr[i] && lis[i]<lis[j]+1){
				lis[i]=lis[j]+1;
				res[i]=j;
			}
		}
	}
	for(i=0;i<n;i++){
		if(max<lis[i]){
			max=lis[i];
			max_lis=i;
		}
	}
	//Printing LIS

	cout<<"Printing LIS "<<endl;
	i=max_lis;
	while(res[i]!=-1){
		cout<<arr[i]<<"->";
		i=res[i];
	}
	cout<<arr[i]<<endl;
	delete lis;
	return max;
}
int main() {
	int arr_lis[]={10, 22, 9, 33, 21, 50, 41, 60, 80};
	cout<<"LIS is "<<longestIncreaingSubsequence(arr_lis,9);
	return 0;
}
*/
