/*

 * pairSumArray.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user


//Construct an array from its pair-sum array
#include<iostream>
using namespace std;
int pairSum(int arr[],int n){
	int new_arr[n];
	new_arr[0]=(arr[0]+arr[1]-arr[n-1])/2;
	for(int i=0;i<n-1;i++){
		new_arr[i+1]=arr[i]-new_arr[0];
	}
	for(int i=0;i<n;i++){
		cout<<new_arr[i]<<" ";
	}
	return 0;
}

int main(){
	int arr[] = {14, 9, 10, 11, 12, 7};
	//int n=sizeof(arr)/sizeof(arr[0]);
	int n=4;
	cout<<"Index "<<pairSum(arr,n);
}


*/
