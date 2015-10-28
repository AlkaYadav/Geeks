//============================================================================
// Name        : KMP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

void computeLPSArray(char *pat,int* lps,int M){
	lps[0]=0;
	int i=1;
	int len=0;
	while(i<M){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void KMPSearch(char* pat,char* str){
	int M=strlen(pat);
	int N=strlen(str);
	int i=0;
	int j=0;
	int* lps=new int[M];

	computeLPSArray(pat,lps,M);

	while(i<N){
		if(pat[j]==str[i]){
			i++;
			j++;
		}
		if(j==M){
			cout<<"Pattern found at "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<N && pat[j]!=str[i]){
			if(j!=0)
			    j=lps[j-1];
			else i=i+1;
		}
	}
}
int main(){
	char *pat="ABABCABAB";
	char *str = "ABABDABACDABABCABAB";
	KMPSearch(pat,str);


	cout<<endl;
}
