/*

 * Monk.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: user


#include <iostream>
#include<algorithm>
using namespace std;

void calculateBits(long long int a[],long long int num,long long int j){

	long long int count=0;
	while(num){
		if(num&1){
			count++;
		}
		num=num>>1;
	}
	a[j]=count;
}

	int compare(const void* a,const void *b){
		return *(long long int*)a-*(long long int*)b;
	}
void displayKElements(long long int a[],long long int N,long long int K){
	qsort(a,N,sizeof(a[0]),compare);
	long long int count=0;
	for(long long int i=0;i<K;i++){
		count+=a[i];
	}
	cout<<count<<endl;
}
int main()
{
	long long int T;
	long long int N,K;
	long long int num;

    cin>>T;
    for(long long int i=0;i<T;i++){
    	cin>>N>>K;
    	long long int a[N];
    	    	for(long long int j=0;j<N;j++){
    	    		cin>>num;
    	    		calculateBits(a,num,j);
    	    	}
    	    	displayKElements(a,N,K);
    	    }
    	    return 0;
    	}


*/
