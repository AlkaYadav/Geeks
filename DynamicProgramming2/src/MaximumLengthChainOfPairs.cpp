/*

 * MaximumLengthChainOfPairs.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user


#include<limits.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct pairs{
	int a;
	int b;
};

void maximumLengthChainOfPairs(struct pairs a[],int n){
	int lis[n],maxlis=INT_MIN;
	for(int i=0;i<n;i++){
		lis[i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j].b<a[i].a && lis[j]+1>lis[i]){
				lis[i]=lis[j]+1;
			}
		}
	}

	//Finding maxlis
	for(int i=0;i<n;i++){
		if(lis[i]>maxlis){
			maxlis=lis[i];
		}
	}

	cout<<"Maximum Length Chain Of Pairs using LIS is "<<maxlis<<endl;
}


int main(){
	struct pairs a[]={
			{5, 24}, {15, 25},
			{27, 40}, {50, 60}
	};
	int n=sizeof(a)/sizeof(a[0]);
	maximumLengthChainOfPairs(a,n);
	return 0;
	}

*/
