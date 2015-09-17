/*

 * countOccurenceSortedArray.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user


//Count the number of occurrences in a sorted array
#include<iostream>
#include<limits.h>
#include<map>
using namespace std;
int first(int a[],int low,int high ,int ele){
	int mid=(low+high)/2;
	if(low>high){
		return -1;
	}
	if((a[mid]==ele)&&(a[mid-1]<ele || mid==0 || mid==high)){
		return mid;
	}
	if(a[mid]<ele){
		return first(a,mid+1,high,ele);

	}
	else{
		return first(a,low,mid-1,ele);
	}
	return -1;
}


int last(int a[],int low,int high ,int ele){
	int mid=(low+high)/2;
	if(low>high){
		return -1;
	}
	if((a[mid]==ele)&&(a[mid+1]>ele || mid==0 || mid==high)){
		return mid;
	}
	if(a[mid]>ele){
		return last(a,low,mid-1,ele);
	}
	else{
		return last(a,mid+1,high,ele);
	}
	return -1;
}

int main(){
	int ar1[] = {1, 1, 2, 2, 2, 2, 3,};

	int n1=sizeof(ar1)/sizeof(ar1[0]);
int ele=2;

	int ft=first(ar1,0,n1-1,ele);
	int lt=last(ar1,0,n1-1,ele);
	cout<<"first "<<ft<<endl;
	cout<<"last "<<lt<<endl;
	cout<<"Occurences are "<<lt-ft+1;
}

*/
