/*
//============================================================================
// Name        : ArrayProject.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Find the closest pair from two sorted arrays
//============================================================================

#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

void merge(int arr3[],int ar1[],int ar2[],int arr1_size,int arr2_size,int bool_type[]){
	int i=0;
	int j=0;
	int k=0;
	while(i<arr1_size&& j<arr2_size){
		if(ar1[i]<ar2[j]){
			arr3[k]=ar1[i];
			bool_type[k]=1;
			i++;
			k++;
		}
		else{
			arr3[k]=ar2[j];
			bool_type[k]=2;
			j++;
			k++;
		}
	}

	if(i<arr1_size){
		arr3[k]=ar1[i];
		bool_type[k]=1;
					i++;
					k++;
	}
	if(j<arr2_size){
		arr3[k]=ar2[j];
		bool_type[k]=2;
					j++;
					k++;
	}
}

void findClosestPair(int ar1[],int ar2[],int ar1_size,int ar2_size,int x){
	int min_diff=INT_MAX;
	int i=0;
	int j=ar2_size-1;
	int indx_i,indx_j;
	while(i<ar1_size && j>=0){

		if(abs(ar1[i]+ar2[j]-x)<min_diff){
			min_diff=abs(ar1[i]+ar2[j]-x);
			indx_i=i;
			indx_j=j;
		}
		if(ar1[i]+ar2[j]<x){
			i++;
		}
		else{
			j--;
		}
	}
	cout<<"Min diff "<<min_diff<<endl;
	cout<<"Min i index "<<indx_i<<"and j "<<indx_j<<endl;
}
int main() {
	int ar1[] = {1, 4, 5, 7};
	int ar2[] = {10, 20, 30, 40};
	int x = 32;
	int arr1_size=sizeof(ar1)/sizeof(ar1[0]);
	int arr2_size=sizeof(ar2)/sizeof(ar2[0]);

	//merge(ar3,ar1,ar2,arr1_size,arr2_size,bool_type);
	findClosestPair(ar1,ar2,arr1_size,arr2_size,x);
	return 0;
}
*/
