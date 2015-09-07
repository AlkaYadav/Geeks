/*

 * SortedPivotedArraySearch.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: user


#include<iostream>
using namespace std;

int findPivot(int arr[],int start,int end){
	if(start>end){
			return -1;
		}
	if(start==end){
		return start;
	}
	int mid=(start+end)/2;
	if(arr[mid]>arr[mid+1]){
		return mid;
	}
	if(arr[mid-1]>arr[mid]){
		return mid-1;
	}
	if(arr[start]>=arr[mid])
		findPivot(arr,start,mid-1);
	else{
		return findPivot(arr,mid+1,end);
	}
	return -1;
}

int binarySearch(int arr[],int ele,int start,int end){
	int mid=(start+end)/2;
	if(start>end){
		return -1;
	}
	if(arr[mid]==ele){
		return mid;
	}
	if(arr[mid]>ele){
		return binarySearch(arr,ele,start,mid-1);
	}
	else{
		return binarySearch(arr,ele,mid+1,end);
	}

}
void sortedPivotedSearch(int arr[],int n,int ele){
	int pivot=findPivot(arr,0,n-1);
	cout<<"Pivot is "<<pivot<<endl;
	int index;
	if(pivot==-1){
		index=binarySearch(arr,ele,0,n-1);
	}
	else{
		if(arr[0]<=ele){
			index=binarySearch(arr,ele,0,pivot);
		}
		else{
			index=binarySearch(arr,ele,pivot+1,n-1);
		}
	}
	cout<<"Elemenet found at index "<<index<<endl;
}


int main(){
	int arr[]={5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int ele=7;
	sortedPivotedSearch(arr,n,ele);
}
*/
