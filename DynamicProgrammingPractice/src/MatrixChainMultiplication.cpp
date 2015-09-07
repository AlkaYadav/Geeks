/*
 * MatrixChainMultiplication.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: user
 */
#include<iostream>
#include<limits.h>
using namespace std;


void matrixChainMultiplication(int p[],int n){
	// p of size n leads to n-1 matrices
	int cost[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>=j){
				cost[i][j]=0;
			}
		}
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(j>i){
			cost[i][j]=INT_MAX;
			for(int k=i;k<j;k++){

				int c=cost[i][k]+cost[k+1][j]+p[i-1]*p[k]*p[j];
				if(c<cost[i][j]){
					cost[i][j]=c;
				}
			}
		}
		}
	}
	cout<<"Minimum "<<cost[1][n-1]<<endl;
}

int main(){
	int p[] = {10, 20, 30} ;
	int n=sizeof(p)/sizeof(p[0]);
	matrixChainMultiplication(p,n);
}
