/*

 * OddAppearing.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: user

********************************************************************************
 * Find the odd appearing element in O(Log n) time
Given an array where all elements appear even number of times except one.
All repeating occurrences of elements appear in pairs and these pairs are not adjacent
(there cannot be more than two consecutive occurrences of any element). Find the element that appears odd number of times.


#include<iostream>
using namespace std;
void oddAppearing(int arr[],int l,int r){
	if(l>r){
		cout<<"Element not found"<<endl;
		return;
	}
	if(l==r){
		cout<<"Element found "<<arr[l]<<endl;
		return;
	}
	int mid=(l+r)/2;
	if(mid%2==0){
		cout<<"Mid value is "<<mid<<endl;
		if(arr[mid]==arr[mid+1]){
			oddAppearing(arr,mid+2,r);
		}
		else{
			oddAppearing(arr,l,mid);
		}
	}

	else{
		cout<<"Mid value is "<<mid<<endl;
		if(arr[mid]==arr[mid-1]){
			oddAppearing(arr,mid-2,r);
		}
		else{
			oddAppearing(arr,l,mid-1);
		}
	}
	return ;
}

int main(){
	int arr[] = {1, 1, 2, 4, 4, 5, 5, 6, 6};
	int len = sizeof(arr)/sizeof(arr[0]);
	oddAppearing(arr,0,len-1);
}

*/
