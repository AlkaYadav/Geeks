/*

 * QuickSortVector.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: user


#include<vector>
#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int partition(vector<int> &arr,int l,int h,int x){
	int j=l-1;
	int i;
	for(i=l;i<h;i++){
		if(arr[i]<=x){
			j++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[j+1],&arr[h]);
	return j+1;
}

void quickSort(vector<int> &arr,int l,int h){
	if(l<h){
	int x=arr[h];
	int p=partition(arr,l,h,x);
	quickSort(arr,l,p-1);
	quickSort(arr,p+1,h);
	}
}

int main(){
	vector<int> arr;
	int n,ele;
	cout<<"Enter the elements "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ele;
		arr.push_back(ele);
	}
	cout<<"After inserting "<<arr.size()<<endl;

	quickSort(arr,0,arr.size()-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
*/
