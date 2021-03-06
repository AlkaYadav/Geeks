/*

 * LCS.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user

#include<iostream>
#include<cstring>
using namespace std;

int LCS_Recursive(char X[],char Y[],int m,int n){
	if(m<=0|| n<=0){
		return 0;
	}
	if(X[m-1]==Y[n-1]){
		return 1+LCS_Recursive(X,Y,m-1,n-1);
	}
	else{
		return max(LCS_Recursive(X,Y,m-1,n),LCS_Recursive(X,Y,m,n-1));
	}
}

void LCS_DP(char X[],char Y[],int m,int n){
	int lcs[m+1][n+1];
	for(int i=0;i<=m;i++){
		lcs[i][0]=0;
	}
	for(int j=0;j<=n;j++){
			lcs[0][j]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(X[i-1]==Y[j-1]){
				lcs[i][j]=1+lcs[i-1][j-1];
			}
			else{
				lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
			}
		}
	}
	cout<<endl<<"LCS is "<<lcs[m][n]<<endl;
	//LCS table is
	cout<<"LCS table is "<<endl;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<lcs[i][j]<<" ";
		}
		cout<<endl;
	}
	//Printing LCS
	int i=m;
	int j=n;
	int index=lcs[m][n];
	int len=index+1;
	char lcs_print[index+1];

	while(i>=0 && j>=0){
		if(X[i-1]==Y[j-1]){
			lcs_print[index-1]=X[i-1];
			index--;
			i--;
			j--;
		}
		else{
			if(lcs[i][j-1]>lcs[i-1][j]){
				j--;
			}
			else {
				i--;
			}
		}
	}
lcs_print[len-1]='\0';
cout<<"Printing LCS..."<<lcs_print<<endl;;
}

char* reverse(char X[],int m){
	char *Y=new char[m+1];
	Y[m]='\0';
	char tmp;
	for(int i=0;i<m;i++){
		Y[i]=X[i];
	}
	for(int i=0;i<m/2;i++){
		tmp=Y[i];
		Y[i]=Y[m-i-1];
		Y[m-i-1]=tmp;
	}
	return Y;
}
int main(){
	char X[]="ABCDH";
	char Y[]="AEDFHR";
	int m=strlen(X);
	int n=strlen(Y);
	cout<<"LCS is "<<LCS_Recursive(X,Y,m,n);
	LCS_DP(X,Y,m,n);

	//Finding Longest Palindromic Subsequence using LCS
	cout<<"============================================================="<<endl;
	char Z[]="ABCDH";
	m=strlen(Z);

	char *W=reverse(Z,m);
	cout<<"Reverse of string is "<<W<<endl;
	cout<<"Longest Palindromic Subsequence using LCS"<<endl;
	LCS_DP(Z,W,m,m);
}
*/
