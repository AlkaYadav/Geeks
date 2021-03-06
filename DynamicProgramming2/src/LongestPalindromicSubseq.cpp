/*

 * LongestPalindromicSubseq.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user


#include<iostream>
#include<cstring>
using namespace std;
//i=1,j=length
int longestPalindromicSubseq(char X[],int i,int j)
{
	if(i==j){
		return 1;
	}
	if(j<=0 || i>j-1){
		return 0;
	}
	if(X[i-1]==X[j-1]){
		return 2+longestPalindromicSubseq(X,i+1,j-1);
	}
	else return max(longestPalindromicSubseq(X,i,j-1),longestPalindromicSubseq(X,i+1,j));
}

void longestPalindromicSubseq_DP(char X[],int len){
	int lps[len][len];
	int j;
	//Construct len-1 palindrome substring
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(i==j){
				lps[i][j]=1;
			}
		}
	}

	//Construct len-2 and greater palindrome substring
	for(int cl=2;cl<=len;cl++){
		//Calculate from first to last start index
		for(int i=0;i<=len-cl;i++){
			j=i+cl-1;
			if(cl==2&& X[i]==X[j]){
					lps[i][j]=2;

			}
			else if(X[i]==X[j]){
				lps[i][j]=2+lps[i+1][j-1];
			}
			else{
				lps[i][j]=max(lps[i+1][j],lps[i][j-1]);
			}
		}
	}

	cout<<"LPS is "<<lps[0][len-1]<<endl;
}
int main(){
	char X[] = "GEEKSFORGEEKS";
	int size = strlen(X);
	cout<<"longestPalindromicSubseq "<<longestPalindromicSubseq(X,1,size);
	longestPalindromicSubseq_DP(X,size);
	return 0;
}
*/
