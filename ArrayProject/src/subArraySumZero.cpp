/*

 * subArraySumZero.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

//Find if there is a subarray with 0 sum
#include<iostream>
#include<limits.h>
#include<map>
using namespace std;
void subArray(int a[],int n){
	map<int,int> m;
	int sum,start=-1,end=-1;
	for(int i=0;i<n;i++){
		if(i==0){

			sum=a[0];

		}
		else{

			sum+=a[i];

		}
		if(sum==0){
			start=0;
			end=i;
			break;
		}
		if(a[i]==0){
			start=i;
			end=i;
			break;
		}
		if(m[sum]){

			start=m[sum];
			end=i;
			break;
		}
		m[sum]=i+1;

	}


	cout<<"Subarray Sum "<<endl;
	cout<<"Start "<<start<<" and end :"<<end<<endl;
}

int main(){
	int ar1[] = {-3, 2, 3, 1, 6};

	int n1=sizeof(ar1)/sizeof(ar1[0]);
	subArray(ar1,n1);
}



*/
