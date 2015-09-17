/*

 * onesSortedArray.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

//Count 1’s in a sorted binary array
#include<iostream>
using namespace std;
int countOnes(int arr[],int low,int high){
	int mid=(low+high)/2;
	if(low>high){
		return -1;
	}
	if((arr[mid]==1) && (arr[mid+1]==0 || mid==high)){
		return mid+1;
	}
	if(arr[mid]==1){
		return countOnes(arr,mid+1,high);
	}
	else
		return countOnes(arr,low,mid-1);
}

int main(){
	int arr[] = {1, 1, 1, 1, 1, 1, 1};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Index "<<countOnes(arr,0,n-1);
}


*/
