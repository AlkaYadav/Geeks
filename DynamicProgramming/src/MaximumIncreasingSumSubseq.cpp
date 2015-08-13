/*

 * MaximumIncreasingSumSubseq.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user

#include<limits.h>
#include<iostream>
using namespace std;
void maximumIncreasingSumSubsequence(int arr[],int n){
	int maxlis[n+1];
	for(int i=0;i<n;i++){
		maxlis[i]=arr[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i] && maxlis[i]<maxlis[j]+arr[i]){
				maxlis[i]=maxlis[j]+arr[i];
			}
		}
	}

	int max_lis=INT_MIN;
	for(int i=0;i<n;i++){
		if(maxlis[i]>max_lis){
			max_lis=maxlis[i];
		}
	}

	cout<<"MaximumIncreasingSumSubseq length is "<<max_lis<<endl;
}



int main()
{
  int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  maximumIncreasingSumSubsequence(arr,n);

  getchar();
  return 0;
}
*/
