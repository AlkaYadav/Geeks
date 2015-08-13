/*

 * PalindromePartitioning.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user


#include<limits.h>
#include<iostream>
#include<cstring>
using namespace std;

int palindromePartitioning(char X[],int n){
	bool P[n][n];

	//Initialize boolean table
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			P[i][j]=false;
		}
	}

	//Construct len-1 palindromes
	for(int i=0;i<n;i++){
		P[i][i]=true;
	}

	//Construct len-2 or greater palindromes
	for(int cl=2;cl<=n;cl++){
		for(int i=0;i<=n-cl;i++){
			int j=i+cl-1;
			if(cl==2){
				if(X[i]==X[j]){
					P[i][j]=true;
				}
			}
			else{
				if(X[i]==X[j]&& P[i+1][j-1]){
					P[i][j]=true;
				}
			}
		}
	}

	//Calculate minimum number of cuts
	int C[n];
	C[0]=0;
	for(int i=0;i<n;i++){
		if(P[0][i]){
			C[i]=0;
		}
		else{
			C[i]=INT_MAX;
			for(int j=0;j<i;j++){
				if(P[j+1][i]&& C[j]+1<C[i]){
					C[i]=C[j]+1;
				}
			}
		}
	}
	//Minimum cuts till index n-1 are C[n-1]
	return C[n-1];
}

int main(){
	char X[]="ababbbabbababa";
	int n=strlen(X);
	cout<<"Minimum number of cuts are:"<<palindromePartitioning(X,n)<<endl;
}

*/
