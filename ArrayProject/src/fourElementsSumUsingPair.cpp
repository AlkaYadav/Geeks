/*

 * fourElementsSumUsingPair.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: user

#include<iostream>
#include<limits.h>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

struct SumPair{
	int sum;
	int first;
	int second;
};
int compare(const void* a,const void * b){
	return (*(struct SumPair*)a).sum-(*(struct SumPair*)b).sum;
}
bool noCommon(struct SumPair s1,struct SumPair s2){
	if(s1.first==s2.first||s1.second==s2.second||s1.second==s2.first||s1.first==s2.second){
		return false;
	}
	return true;
}
void findFourPairSum(int a[],int n,int sum){

	struct SumPair sumPair[n*(n-1)/2];
	int indx=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			sumPair[indx].sum=a[i]+a[j];
			sumPair[indx].first=i;
			sumPair[indx].second=j;
			indx++;
		}
	}
	qsort(sumPair,n*(n-1)/2,sizeof(sumPair[0]),compare);

	int k=0;
	int size=(n*(n-1)/2);
	int l=size-1;
	while(k<size && l>=0){
		if((sumPair[k].sum+sumPair[l].sum==sum)&&noCommon(sumPair[k],sumPair[l])){
			cout<<"Sum Pair exist "<<endl;
			cout<<a[sumPair[k].first]<<" "<<a[sumPair[k].second]<<" ";
			cout<<a[sumPair[l].first]<<" "<<a[sumPair[l].second]<<endl;
			return;
		}
		else if (sumPair[k].sum+sumPair[l].sum<sum){
			k++;
		}
		else l--;
	}
}

int main(){
	int ar1[] = {10, 20, 30, 40, 1, 2};

	int n1=sizeof(ar1)/sizeof(ar1[0]);

	findFourPairSum(ar1,n1,91);

}

*/
