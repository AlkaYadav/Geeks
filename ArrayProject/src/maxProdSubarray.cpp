/*

 * maxProdSubarray.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: user


//Maximum Product Subarray for both +ve and -ve integers
//{6, -3, -10, 0, 2}
#include<iostream>
#include<limits.h>
using namespace std;
void max_product_subarray(int a[],int n){
	int max_ending_here=1;
	int min_ending_here=1;
	int max_product=INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i]>0){
			max_ending_here=max_ending_here*a[i];
			min_ending_here=min(1,min_ending_here*a[i]);
		}
		if(a[i]==0){
			max_ending_here=1;
			min_ending_here=1;
		}
		if(a[i]<0){
			int tmp=max_ending_here;
			max_ending_here=max(min_ending_here*a[i],1);
			min_ending_here=tmp*a[i];
		}
		if(max_ending_here>max_product){
			max_product=max_ending_here;
		}
	}

	cout<<"Maximum product subarray is "<<max_product<<endl;
}

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    max_product_subarray(arr,n);
    return 0;
}
*/
