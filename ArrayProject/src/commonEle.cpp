/*

 * commonEle.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user


//Find common elements in three sorted arrays

#include<iostream>
using namespace std;

void common_Ele(int a1[],int a2[],int a3[],int s1,int s2,int s3){
	int i=0,j=0,k=0;
	int c_size=min(s1,min(s2,s3));
	int common[c_size];
	int c=0;
	while(i<s1&& j<s2&& k<s3){
		int min=0;
		if((a1[i]==a2[j])&& (a1[i]==a3[k])){
			common[c++]=a1[i];
			i++;
			j++;
			k++;
			continue;
		}
		if((a1[i]<a2[j])&& (a1[i]<a3[k])){
			min=1;
		}
		else if((a1[i]>a2[j])&& (a2[j]<a3[k])){
			min=2;
		}
		else min=3;
		if(min==1){
			i++;
		}
		if(min==2){
			j++;
		}
		if(min==3){
			k++;
		}
	}
	cout<<"Cmmon elements are "<<endl;
	for(int j=0;j<c;j++){
		cout<<common[j]<<" ";
	}
}

int main(){
	int ar1[] = {1, 5, 5};
	int ar2[] = {3, 4, 5, 5, 10};
	int ar3[] = {5, 5, 10, 20};
	int n1=sizeof(ar1)/sizeof(ar1[0]);
	int n2=sizeof(ar2)/sizeof(ar2[0]);
	int n3=sizeof(ar3)/sizeof(ar3[0]);

	common_Ele(ar1,ar2,ar3,n1,n2,n3);
}


*/
