/*

 * MaximumPairProduct.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: user


//Find a pair with maximum product in array of Integers
#include<stdlib.h>
#include<limits.h>
#include<iostream>
using namespace std;

int compare(const void * a,const void * b){
	return (*(int*)a-*(int*)b);
}
int maximumProduct(int arr[],int n){
	qsort(arr,n,sizeof(arr[0]),compare);
	int prod1=INT_MIN,prod2;
	if(arr[0]<0){
		prod1=arr[0]*arr[1];
	}
	prod2=arr[n-1]*arr[n-2];
	return max(prod1,prod2);
}

int main(){
	int arr[] = {1, 4, -3, -6, 7, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<maximumProduct(arr,n);
}
*/
