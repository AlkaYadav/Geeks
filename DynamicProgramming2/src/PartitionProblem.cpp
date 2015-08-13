/*
 * PartitionProblem.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user
 */
#include<iostream>
using namespace std;
/*****************************************************************************
 * Start Partition Problem Recursive
 ****************************************************************************/
bool isPartition(int arr[],int n,int sum);
bool partitionProblem(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	if(sum%2!=0){
		return false;
	}
	return isPartition(arr,n,sum/2);
}


bool isPartition(int arr[],int n,int sum){
	if(n==0&& sum!=0){
		return false;
	}
	if(sum==0){
		return true;
	}
	if(arr[n-1]<=sum){
		return isPartition(arr,n-1,sum-arr[n-1])||isPartition(arr,n-1,sum);
	}
	else
		return isPartition(arr,n-1,sum);
}
/*****************************************************************************
 * End Partition Problem Recursive
 ****************************************************************************/
/*****************************************************************************
 * Start Partition Problem DP
 ****************************************************************************/
void partition_DP(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	if(sum%2!=0){
		return ;
	}
	bool partition[(sum/2)+1][n+1];

	for(int i=0;i<=sum/2;i++){
		partition[i][0]=false;
	}
	for(int i=0;i<=n;i++){
			partition[0][i]=true;
		}
	for(int i=1;i<=sum/2;i++){
		for(int j=1;j<=n;j++){
			partition[i][j]=partition[i][j-1];
			if(arr[j-1]<=i){
				partition[i][j]=partition[i][j]||partition[i-arr[j-1]][j-1];
			}
		}
	}
	//Printing partition table
	for(int i=0;i<=sum/2;i++){
		for(int j=0;j<=n;j++){
			cout<<partition[i][j]<<"   ";
		}
		cout<<endl;
	}
  cout<<endl<<"is Partition possible "<<partition[sum/2][n];
}
int main(){
	int arr[]={5,11,8};
	int n=sizeof(arr)/sizeof(int);
	cout<<"Partition is possible or not "<<partitionProblem(arr,n);
	cout<<"Partition problem using DP===="<<endl;
	partition_DP(arr,n);
}
