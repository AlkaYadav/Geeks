/*

 * Jumps.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: user



//Find the minimum no. of jumps to reach end of array
//l is low value ,h is high value
#include<limits.h>
#include<iostream>
using namespace std;
int minJumps(int arr[],int l,int h){
	if(arr[l]==0){
		return INT_MAX;
	}
	if(h==l){
		return 0;
	}
	int jumps=INT_MAX;
	int mjumps;
	for(int i=l+1;i<=h && i<=l+arr[l];i++){
		mjumps=minJumps(arr,i,h);
	if(mjumps!=INT_MAX && mjumps+1<jumps){
		jumps=1+mjumps;
	}
	}
	return jumps;
}

int main(){
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Minimum number of jumps to reach end is "<<minJumps(arr,0,n-1)<<endl;
	return 0;
}

*/
