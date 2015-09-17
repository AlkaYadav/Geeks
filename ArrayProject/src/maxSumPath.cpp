/*

 * maxSumPath.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

//Maximum Sum Path in Two Arrays

#include<iostream>
#include<limits.h>
#include<map>
using namespace std;
void maxSumPath(int a1[],int a2[],int s1,int s2){
	int i=0,j=0;
	int sum1=0,sum2=0,sum=0;
	while(i<s1&& j<s2){
		if(a1[i]==a2[j]){
			sum+=max(sum1,sum2)+a1[i];
			i++;
			j++;
			sum1=0;
			sum2=0;
		}
		else if(a1[i]<a2[j]){
			sum1+=a1[i];
			i++;

		}
		else{
			sum2+=a2[j];
			j++;
		}


	}

	if(i<s1){
		while(i<s1){
			sum1+=a1[i];
			i++;
		}
	}
	if(j<s2){
			while(j<s2){
				sum2+=a2[j];
				j++;
			}
		}
	sum+=max(sum1,sum2);

	cout<<"Sum is "<<sum<<endl;
}

int main(){
	int ar1[] = {2, 3, 7, 10, 12, 15, 30, 34};
	int ar2[] = {1, 5, 7, 8, 10, 15, 16, 19};
	int n1=sizeof(ar1)/sizeof(ar1[0]);
	int n2=sizeof(ar2)/sizeof(ar2[0]);
	maxSumPath(ar1,ar2,n1,n2);
}


*/
