/*

 * peakEle.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

#include<iostream>
using namespace std;
//Find a peak element
int findPeak(int a[],int low,int high){
	if(low>=high){
		return low;
	}
	int mid=(low+high)/2;
	if(mid==low && a[mid]>a[mid+1]){
		return mid;
	}
	if(mid==high && a[mid-1]<a[mid]){
		return mid;
	}
	if(mid<high && a[mid]>a[mid+1] && mid>low && a[mid]>a[mid-1]){
		return mid;
	}
	if(a[mid]<a[mid-1]){
		findPeak(a,low,mid-1);
	}
	return findPeak(a,mid+1,high);
}

int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Index of a peak point is "<< findPeak(arr,0, n-1);
    return 0;
}
*/
