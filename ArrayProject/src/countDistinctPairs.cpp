/*

 * countDistinctPairs.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

//Count all distinct pairs with difference equal to k
#include<iostream>
#include<limits.h>
#include<map>
#include<algorithm>
using namespace std;
void countDistictPairsWithSumK(int a[],int n,int k){
	map<int,int> m;
	for(int i=0;i<n;i++){
		m[a[i]]=1;
	}
	map<int,int>::iterator it;
	int count=0;
	for(int i=0;i<n;i++){
		if(m[a[i]+k]>0){
			count++;
		}
		if(m[a[i]-k]>0){
			count++;
		}
		m[a[i]]=0;
	}
	for(it=m.begin();it!=m.end();it++){
		int n=it->first+k;
		if(m[n]){
			count++;
			//break;
		}

	}
	cout<<"Count is "<<count<<endl;
}


int main(){
	int ar1[] = {1, 5, 3, 4, 2};
	int x=3;
	int n1=sizeof(ar1)/sizeof(ar1[0]);

	countDistictPairsWithSumK(ar1,n1,x);
}

*/
