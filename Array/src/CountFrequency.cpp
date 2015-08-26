/*
 * CountFrequency.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user
 */

#include<iostream>
using namespace std;

void printArray(int a[],int n){
	cout<<"Array is "<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<"==============================================="<<endl;
}
void countFrequencyO1Time(int arr[],int n){
	int i=0,tmp;

	while(i<=n-1){
		if(arr[i]>0){
			int index=arr[i]-1;
			tmp=arr[index];
			if(tmp>0){
				arr[i]=tmp;
				arr[index]=-1;
			}
			else{
				arr[index]--;
				arr[i]=0;
				i++;
			}
		}

	else{
		i++;
	}
		printArray(arr,n);
	}

	//Print frequency
	for(int i=0;i<n;i++){
		cout<<"Frequency of "<<i+1<<" "<<-1*arr[i]<<endl;
	}
}


int main(){
	int arr[] = {2, 3, 3, 2, 5};
	cout<<"Initially..."<<endl;
	int n=sizeof(arr)/ sizeof(arr[0]);
	printArray(arr,n);
	countFrequencyO1Time(arr,n);
}
