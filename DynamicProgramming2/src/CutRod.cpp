/*

 * CutRod.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user

#include<iostream>
#include<limits.h>
using namespace std;
int cutRod(int price[],int n){
	if(n<=0){
		return 0;
	}
	int max_val=INT_MIN;
	for(int i=1;i<=n;i++){
		max_val= max(max_val,price[i-1]+cutRod(price,n-i));
	}
	return max_val;
}

void cutRod_DP(int price[],int n){
	int cutRod[n+1];
	for(int i=1;i<=n;i++){
		cutRod[i]=INT_MIN;
	}
	cutRod[0]=0;
	int max_val;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			max_val=price[j-1]+cutRod[i-j];
			if(max_val>cutRod[i]){
				cutRod[i]=max_val;
			}
		}

	}
	cout<<"Cut Rod is "<<cutRod[n]<<endl;
}
int main(){
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Maximum profit is"<<cutRod(arr,size);
	cutRod_DP(arr,size);
	return 0;
}
*/
