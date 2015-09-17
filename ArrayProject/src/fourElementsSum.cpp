/*

 * fourElementsSum.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

#include<iostream>
#include<limits.h>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
//Find four elements that sum to a given value | Set 1 (n^3 solution)

int compare(const void* a,const void * b){
	return *(int*)a-*(int*)b;
}
void fourElementsSum(int a[],int n,int sum){
for(int i=0;i<=n-4;i++){
	for(int j=i+1;j<=n-3;j++){
		int k=j+1;
		int l=n-1;
		while(k<l){
			if(a[i]+a[j]+a[k]+a[l]==sum){
				cout<<"Sum found with "<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<endl;
				return;
			}
			else if(a[i]+a[j]+a[k]+a[l]<sum){
				k++;
			}
			else l--;
		}
	}
}

cout<<"Not found "<<endl;
}

int main(){
	int ar1[] = {1, 4, 45, 6, 10, 12};;

	int n1=sizeof(ar1)/sizeof(ar1[0]);
	qsort(ar1,n1,sizeof(ar1[0]),compare);
	fourElementsSum(ar1,n1,21);

}
*/
