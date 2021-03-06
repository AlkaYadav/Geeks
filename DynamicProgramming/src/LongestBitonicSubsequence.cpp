/*

 * LongestBitonicSubsequence.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user

#include<iostream>
using namespace std;
void longestBitonicSubsequence(int arr[],int n){
	int lis[n];
	int lds[n];
	for(int i=0;i<n;i++){
		lis[i]=1;
		lds[i]=1;
	}

	//Computing Longest Increasing Subsequece
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]&& lis[j]+1>lis[i]){
				lis[i]=lis[j]+1;
			}
		}
	}

	//Computing Longest Decreasing Subsequece
		for(int i=n-2;i>=0;i++){
			for(int j=n-1;j>i;j--){
				if(arr[j]<arr[i]&& lds[j]+1>lds[i]){
					lds[i]=lds[j]+1;
				}
			}
		}
	//Computing max
		int max=lis[0]+lds[0]-1;
		for(int i=1;i<n;i++){
			if(lis[i]+lds[i]-1>max){
				max=lis[i]+lds[i]-1;
			}
		}
	cout<<"Longest bitonic subsequence is "<<max<<endl;
}

int main(){
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	  int n = sizeof(arr)/sizeof(arr[0]);
	  longestBitonicSubsequence(arr,n);
}


*/
