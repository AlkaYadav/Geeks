/*

 * LCS.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: user

#include<iostream>
#include<cstring>
using namespace std;

void LCS(char *X,char *Y,int m,int n){
	int LCS[m+1][n+1];
	char *lcs;
	int i,j,k;
	//Initializing table
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			LCS[i][0]=0;
			LCS[0][j]=0;
		}
	}

	//Fill the table
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(X[i-1]==Y[j-1]){
				LCS[i][j]=1+LCS[i-1][j-1];
			}
			else{
				LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
			}
		}
	}

	//Length of LCS
	cout<<"Length of LCS "<<LCS[m][n]<<endl;
	//Printing LCS table
	for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				cout<<LCS[i][j]<<" ";
			}
			cout<<endl;
	}
	//Printing LCS
	i=m;
	j=n;
	int index=LCS[m][n];
	lcs=new char[index+1];
	k=0;
	lcs[index]='\0';
	while(i>0 && j>0){
		if(X[i-1]==Y[j-1]){
			lcs[index-1]=X[i-1];
			i--;
			j--;
			index--;
		}
		else if(LCS[i][j-1]>LCS[i-1][j]){
				j--;
		}
		else{
				i--;
		}


		}
	cout<<"LCS is "<<lcs<<endl;
}



int main(){
	char X[] = "ABCDGH";
	char Y[] = "AEDFHR";
	LCS(X,Y,strlen(X),strlen(Y));
	return 0;
}
*/
