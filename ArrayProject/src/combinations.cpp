/*

 * combinations.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: user


#include<iostream>
using namespace std;
//Print all possible combinations of r elements in a given array of size n

void combinations(int a[],int data[],int n,int r,int index,int i){
	if(index==r){
		for(int j=0;j<r;j++){
			cout<<data[j]<<" ";

		}
		cout<<endl;
		return;

	}
	if(i>=n){
		return;
	}
	data[index]=a[i];
	combinations(a,data,n,r,index+1,i+1);
	while(a[i]==a[i+1]){
			i++;
		}
	combinations(a,data,n,r,index,i+1);

}


int main(){
	int arr[] = {1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int r=3;
	int data[r];
	combinations(arr,data,n,r,0,0);
}
*/
