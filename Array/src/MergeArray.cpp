/*
 * MergeArray.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: user
 */
#include<iostream>
using namespace std;
#define NA -1
//Merge an array of size n into another array of size m+n

void mergeArray(int arrSmall[],int arrBig[],int m,int n){
	//Shift all elements of bigArray to right end
	int i,j=m+n-1;
	for(int i=j;i>=0;i--){
		if(arrBig[i]!=-1){
			arrBig[j--]=arrBig[i];
		}
	}

	//Merge arrays
	i=n;
	j=0;
	int k=0;
	while(i<=m+n-1 || j<=n-1){
		if(i<=m+n-1 && j<=n-1){
			if(arrBig[i]<=arrSmall[j]){
				arrBig[k++]=arrBig[i];
				i++;
			}
			else{
				arrBig[k++]=arrSmall[j];
				j++;
			}
		}
		else if(i<=m+n-1){
			arrBig[k++]=arrBig[i];
			i++;
		}
		else if(j<=n-1){
			arrBig[k++]=arrSmall[j];
			j++;
		}
	}

	//Print all elements of sorted array
	cout<<"Print all elements of sorted array..."<<endl;
	for(k=0;k<=m+n-1;k++){
		cout<<arrBig[k]<<" ";
	}
}

int main(){
	int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
	  int N[] = {5, 7, 9, 25};
	  int n = sizeof(N)/sizeof(N[0]);
	  int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
	  mergeArray(N,mPlusN,m,n);
}

