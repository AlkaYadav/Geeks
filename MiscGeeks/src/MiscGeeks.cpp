//============================================================================
// Name        : MiscGeeks.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Permutation.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: user
 */
//Print all permutations of a string (string cannot have duplicates)
#include<iostream>
#include<cstring>
using namespace std;
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
			permute(str,i,h);
			swap(str,l,i);
		}
	}
}

int main(){
	char str[]="ABDS";
	int len=strlen(str);
	permute(str,0,len-1);

}
