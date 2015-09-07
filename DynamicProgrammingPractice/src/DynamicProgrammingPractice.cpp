/*
//============================================================================
// Name        : DynamicProgrammingPractice.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;

void editDistance(char *X,char *Y,int m,int n){
	int E[m+1][n+1];
	int DEL_COST=1;
	int REPL_COST=1;
	int INS_COST=1;
	for(int i=0;i<=m;i++){
		//Convert string of length i to string of length 0 needs i deletions
		E[i][0]=i*DEL_COST;
	}
	for(int i=0;i<=n;i++){
		//Convert string of length 0 to string of length i needs i insertions
		E[0][i]=i*INS_COST;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int diff=REPL_COST;
			if(X[i-1]==Y[j-1]){
				diff=0;
			}
			//By replacing last character or if both chars same then cost is 0
			int replace_cost=E[i-1][j-1]+diff;

			//By inserting character
			int ins_cost=INS_COST+E[i][j-1];
			int del_cost=DEL_COST+E[i-1][j];
			E[i][j]=min(replace_cost,min(ins_cost,del_cost));
		}
	}

	cout<<"Minimum no. of edits are "<<E[m][n]<<endl;
}
int main() {
	char *X="SUNDAY";
	char *Y="SATURDAY";
	int m=strlen(X);
	int n=strlen(Y);
	editDistance(X,Y,m,n);
	return 0;
}
*/
