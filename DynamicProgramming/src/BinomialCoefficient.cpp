/*

 * BinomialCoefficient.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user


#include<iostream>
using namespace std;

int binomialCoefficient_Recursion(int n,int k){
	if(k==0||k==n){
		return 1;
	}
	return binomialCoefficient_Recursion(n-1,k-1)+binomialCoefficient_Recursion(n-1,k);
}
void binomialCoefficient(int n,int k){
	int binomial[n+1][k+1];
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=min(i,k);j++){
			if(j==0||j==i){
				binomial[i][j]=1;
			}
			else{
			binomial[i][j]=binomial[i-1][j-1]+binomial[i-1][j];
			}
		}
}
cout<<"Binomial is "<<binomial[n][k]<<endl;
}

void binomialCoefficient_SpaceOptimized(int n,int k){
	int table[n+1];
	for(int i=0;i<=n;i++){
		table[i]=0;
	}
	table[0]=1;
	for(int i=0;i<=n;i++){
		for(int j=min(i,k);j>0;j--){
		table[j]+=table[j-1];
		}
	}
	cout<<"Binomial space optimized is "<<table[k]<<endl;
}
int main(){
	cout<<"Binomial Coefficient is "<<binomialCoefficient_Recursion(5,2)<<endl;
			binomialCoefficient(5,2);
			binomialCoefficient_SpaceOptimized(5,2);
}
*/
