/*

 * GeneratePossibleSorted.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: user


//Generate all possible sorted arrays from alternate elements of two given sorted arrays

#include<iostream>
using namespace std;

void printArray(int a[],int len){
	for(int i=0;i<len;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void generate(int A[],int B[],int C[],int i,int j,int m,int n,int len,bool flag){
	if(flag){
		if(len){
			printArray(C,len+1);
		}

			for(int k=i;k<m;k++){
				if(!len){
					C[len]=A[k];
					generate(A,B,C,k,j,m,n,len,!flag);
				}
				else{
					if(A[k]>C[len]){
						C[len+1]=A[k];
						generate(A,B,C,k,j,m,n,len+1,!flag);
					}
				}
			}

	}

	else{
		for(int k=j;k<n;k++){
			if(B[k]>C[len]){
				C[len+1]=B[k];
				generate(A,B,C,i,k+1,m,n,len+1,!flag);
			}
		}
	}
}

int main(){
	int A[] = {10, 15, 25};
	int B[] = {5, 20, 30};
	int n = sizeof(A)/sizeof(A[0]);
	int m = sizeof(B)/sizeof(B[0]);
	int C[m+n];
	cout<<"Generate all possible sorted arrays from alternate elements of two given sorted arrays"<<endl;
	generate(A,B,C,0,0,m,n,0,true);

}
*/
