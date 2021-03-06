/*

 * MatrixChainMultiplication.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user

#include<limits.h>
#include<iostream>
using namespace std;
int matrixChainMultiply_Recursion(int p[],int i,int j){
	if(i==j){
		return 0;
	}
	int min=INT_MAX,count;
	for(int k=i;k<j;k++){
		count=matrixChainMultiply_Recursion(p,i,k)+
				matrixChainMultiply_Recursion(p,k+1,j)+
				p[i-1]*p[j]*p[k];
		cout<<p[4]<<"In function "<<endl;
		cout<<"Function being called for i "<<i<<" and j="<<j<<"cost added is "<<p[i-1]*p[j]*p[k]<<"with p[k] as "<<p[j]<<"for j="<<j<<endl;
		if(count<min){
			min=count;
		}
	}
	return min;
}
void matrixChainMultiply(int p[],int n){
	int m[n][n],cost;
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j||i>j){
					m[i][j]=0;
				}
			}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
				if(j>i){
				m[i][j]=INT_MAX;
				cout<<"Value being set to max is "<<i<<"and "<<j<<endl;
				for(int k=i;k<=j-1;k++){
					cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
					cout<<"Calculating cost for i"<<i<<" j "<<j<<" k "<<k<<endl;
					cout<<"Values m["<<i<<"]["<<k<<"] + m["<<k+1<<"]["<<j<<"]"<<"cost added "<<p[i-1]*p[k]*p[j]<<endl;
					cout<<"Values "<<m[i][k]<<"+" <<m[k+1][j]<<"cost added "<<p[i-1]*p[k]*p[j]<<endl;
					if(cost<m[i][j]){
						m[i][j]=cost;
					}
				}
				}

		}
	}
//Printing Matrix...
for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
}
	cout<<"Minimum cost is "<<m[1][n-1]<<endl;
}

int main(){
	int p[]={40, 20, 30, 10, 30};
	int n=sizeof(p)/sizeof(int);
	matrixChainMultiply(p,n);
	cout<<matrixChainMultiply_Recursion(p,1,n-1);
}

*/
