/*

 * sortedSubseqSize3.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: user


//Find a sorted subsequence of size 3 in linear time
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;
void sortedSub(int a[],int n){
	int leftSmaller[n];
	int rightGreater[n];
	for(int i=0;i<n;i++){
	    leftSmaller[i]=-1;
	    rightGreater[i]=-1;
	}
	int min_left=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>min_left){
			leftSmaller[i]=min_left;
		}
		else{
			min_left=a[i];
		}
	}

	int max_right=a[n-1];
	for(int i=n-2;i>=0;i--){
		if(a[i]<max_right){
			rightGreater[i]=max_right;
		}
		else{
			max_right=a[i];
		}
	}

	for(int i=1;i<n-1;i++){
		if(leftSmaller[i]!=-1 && rightGreater[i]!=-1){
			cout<<leftSmaller[i]<<" "<<a[i]<<" "<<rightGreater[i]<<endl;
		}
	}
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortedSub(arr, n);
    return 0;
}

*/
