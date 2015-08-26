/*

 * MaximumIntervalOverlap.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: user

#include<limits.h>
#include<iostream>
using namespace std;

void printArray(int main_array[],int index){
	for(int i=0;i<index;i++){
		cout<<main_array[i]<<" ";
	}
	cout<<endl;
}
void maxIntervalOverlap(int arr[],int exit[],int n){
	int main_array[250];
	for(int i=0;i<250;i++){
		main_array[i]=0;
	}
	int index=0;
	for(int i=0;i<n;i++){
		int j,sum=0;
		for(j=arr[i];j<=exit[i];j++){
			main_array[j-1]=main_array[j-1]+1;
			sum=max(sum,main_array[j-1]);
			if(exit[i]>index){
				index=exit[i];
			}
			printArray(main_array,index);
		}
		//main_array[j-1]=sum-1;;
	}

	//Find max in main_array
	int max_main=INT_MIN;
	for(int k=0;k<index;k++){
		if(main_array[k]>max_main){
			max_main=main_array[k];
		}
	}

	cout<<"Maximum is "<<max_main<<endl;
}


int main(){
	int arr[] = {1, 2, 9, 5, 5};
	int exit[] = {4, 5, 12, 9, 12};
	    int n = sizeof(arr)/sizeof(arr[0]);
	    maxIntervalOverlap(arr,exit,n);
}
*/
