/*

 * sortArrayOrderBySecond.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user


//Sort an array according to the order defined by another array

#include<iostream>
#include<limits.h>
#include<map>
#include<algorithm>
using namespace std;

int compare(const void* a,const void * b){
	return *(int*)a-*(int*)b;
}
void sortAccording(int a1[],int a2[],int s1,int s2){
	map<int,int> m;
	//Create hash map for first array
	int k=0;
	for(int i=0;i<s1;i++){
		m[a1[i]]+=1;
	}
	for(int j=0;j<s2;j++){
		if(m[a2[j]]){
			while(m[a2[j]]){
			a1[k++]=a2[j];
			m[a2[j]]--;
			}
			m.erase(a2[j]);
		}
	}
	int end_sort=k;
	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		while(it->second){
			a1[k++]=it->first;
			it->second--;
		}
	}

	if(k<s1){
	qsort(a1+k,s1-k,sizeof(a1[0]),compare);
	}
	for(int l=0;l<s1;l++){
		cout<<a1[l]<<" ";
	}
}

int main(){
	int ar1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8, 7, 5, 6, 9, 7, 5};
	int ar2[] =  {2, 1, 8, 3, 4};
	int n1=sizeof(ar1)/sizeof(ar1[0]);
	int n2=sizeof(ar2)/sizeof(ar2[0]);
	sortAccording(ar1,ar2,n1,n2);
}

*/
