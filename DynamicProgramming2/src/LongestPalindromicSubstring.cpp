/*

 * LongestPalindromicSubstring.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user

#include<iostream>
#include<cstring>
using namespace std;
void longestPalindromicSubstring(char X[],int n){
	bool table[n][n];
	int maxlen=0,startIndex=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			table[i][j]=false;
		}
	}
	//Calculate length 1 substrings
	for(int i=0;i<n;i++){
			table[i][i]=true;
			}
	maxlen=1;

	//Calculate length 2 or greater substrings
	for(int cl=2;cl<=n;cl++){
		for(int i=0;i<=n-cl;i++){
			int j=i+cl-1;
			if(cl==2){
				if(X[i]==X[j]){
					table[i][j]=true;
				}
			}
			else{
				if(X[i]==X[j] && table[i+1][j-1]){
					table[i][j]=true;
				}
			}
			if(cl>maxlen && table[i][j]){
				maxlen=cl;
				startIndex=i;
			}
		}
	}

	//Printing the longest common substring
	cout<<"Max len is:"<<maxlen<<"start is"<<startIndex<<endl;
	cout<<"Longest Common Substring is:"<<endl;
	for(int i=startIndex;i<maxlen+startIndex;i++){
		cout<<X[i]<<" ";
	}
}

int main(){
	char X[]="forgeeksskeegfor";
	int n=strlen(X);
	longestPalindromicSubstring(X,n);
	return 0;
}
*/
