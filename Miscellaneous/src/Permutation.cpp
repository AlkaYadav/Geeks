/*
 * Permutation.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: user
 */
//Print all permutations of a string (string cannot have duplicates)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/*************************************************************************
 * Start Print all permutations of a given string
 *************************************************************************/
void swap(char str[],int indx1,int indx2){
	char tmp;
	tmp=str[indx1];
	str[indx1]=str[indx2];
	str[indx2]=tmp;
}
void permute(char* str,int l,int h){
	if(l==h){
		cout<<str<<" "<<endl;
	}
	else{
		for(int i=l;i<=h;i++){
			swap(str,l,i);
			permute(str,l+1,h);
			swap(str,l,i);
		}
	}
}
/*************************************************************************
 * End Print all permutations of a given string
 *************************************************************************/

/*************************************************************************
 * Start Print all distinct permutations of a given string
 *************************************************************************/
int compare(const void * a,const void * b){
	return *(char *)a-*(char *)b;
}

int findCeil(char str[],char first,int l,int h){
	int ceilIndex=l;
	for(int i=l+1;i<=h;i++){
		if(first<str[i] && str[i]<str[ceilIndex]){
			ceilIndex=i;
		}
	}
	return ceilIndex;
}
void distinctPermutations(char str[]){
	int len=strlen(str);
	qsort(str,len,sizeof(str[0]),compare);
	bool isFinished=false;
	int i;
	while(!isFinished){
		cout<<str<<" "<<endl;
		for(i=len-2;i>=0;i--){
			if(str[i]<str[i+1]){
				break;
			}
		}
		if(i==-1){
			isFinished=true;
			break;
		}
		int ceilIndex=findCeil(str,str[i],i+1,len-1);
		swap(str,i,ceilIndex);
		qsort(str+i+1,len-i-1,sizeof(str[0]),compare);
	}
}

//Lexicographic Rank of a string

int findRightCount(char str[],int l,int h){
	int count=0;
	for(int i=l+1;i<=h;i++){
		if(str[i]<str[l]){
			++count;
		}
	}
	return count;
}

int fact(int num){
	if(num==1||num==0){
		return 1;
	}
	else return num*fact(num-1);
}
int findRank(char str[]){
	int len=strlen(str);
	int rank=1;
	int mul=fact(len);
	for(int i=0;i<len;i++){
		mul/=len-i;
		int countRight=findRightCount(str,i,len-1);
		rank+=mul*countRight;
	}
	return rank;
}
int main(){
	char str[]="string";
	int len=strlen(str);
	//permute(str,0,len-1);
	//distinctPermutations(str);
	cout<<"Rank of string "<<str<<" is "<<findRank(str)<<endl;
}
