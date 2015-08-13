/*

 * MaxSumIncrSubseq.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user


#include<limits.h>
#include<iostream>
using namespace std;
void maximumSumIncreasingSubseq(int arr[],int n){
	int mis[n];
	for(int i=0;i<n;i++){
		mis[i]=arr[i];
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]&& mis[i]<mis[j]+arr[i]){
				mis[i]=mis[j]+arr[i];
			}
		}
	}

	//Find max sum increasing subseq
	int max_sub=INT_MIN;
	for(int i=0;i<n;i++){
		if(mis[i]>max_sub){
			max_sub=mis[i];
		}
	}
	cout<<"MIS is "<<max_sub<<endl;
}

int main(){
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	maximumSumIncreasingSubseq(arr,n);
	return 0;
}



*/
