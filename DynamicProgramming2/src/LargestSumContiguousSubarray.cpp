/*

 * LargestSumContiguousSubarray.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user


#include<iostream>
using namespace std;
void largestSumContiguousSubarray(int arr[],int n){
	int max_ending_here=0;
	int max_so_far=0;

	for(int i=0;i<n;i++){
		max_ending_here+=arr[i];
		if(max_ending_here<0){
			max_ending_here=0;
		}
		if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
		}
	}

	cout<<"Max so far is "<<max_so_far<<endl;
}

//Largest Contiguous Subarray for negative numbers
void largestSumContiguousSubarray_negative(int a[],int n){
	int curr_sum=a[0];
	int max_so_far=a[0];
	for(int i=1;i<n;i++){
		curr_sum=max(a[i],a[i]+curr_sum);
		max_so_far=max(max_so_far,curr_sum);
	}
	cout<<"Max so far is "<<max_so_far<<endl;
}
int main(){
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	largestSumContiguousSubarray(a,n);
	largestSumContiguousSubarray_negative(a,n);
}
*/
