/*

 * maxjMinusi.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: user


//Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<functional>
using namespace std;
void findMax(int a[],int n){
	int lMin[n];
	int rMax[n];
	lMin[0]=a[0];
	rMax[n-1]=a[n-1];
	for(int i=1;i<n;i++){
		lMin[i]=min(a[i],lMin[i-1]);
	}

	for(int i=n-2;i>=0;i--){
		rMax[i]=max(a[i],rMax[i+1]);
	}
	int i=0,j=0;
	int maxdist=INT_MIN;
	while(i<n&& j<n){
		if(lMin[i]<rMax[j]){
			maxdist=max(maxdist,j-i);
			j++;
		}
		else i++;
	}

}


*/
