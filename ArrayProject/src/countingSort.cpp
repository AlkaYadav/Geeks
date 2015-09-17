/*

 * countingSort.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

#include<iostream>
#include<limits.h>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
void countingSort(int a[],int n,int k,int exp){
	int count[k];
	int output[n];
	for(int i=0;i<k;i++){
		count[i]=0;
	}
	for(int i=0;i<n;i++){
		count[(a[i]/exp)%10]++;
	}
	for(int i=1;i<k;i++){
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--){
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	for(int i=0;i<n;i++){
		a[i]=output[i];
	}
}

int findMax(int a[],int n){
	int max_ele=INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i]>max_ele){
			max_ele=a[i];
		}
	}
	return max_ele;
}
void radixSort(int a[],int n){
	int max_ele;
	int k=10;
	max_ele=findMax(a,n);
	for(int exp=1;max_ele/exp>0;exp*=10){
		countingSort(a,n,k,exp);
	}
}
int main(){
	int ar1[] = {170, 45, 75, 90, 802, 24, 2, 66};

	int n1=sizeof(ar1)/sizeof(ar1[0]);
 radixSort(ar1,n1);
	for(int i=0;i<n1;i++){
			cout<<ar1[i]<<" ";
		}
}
*/
