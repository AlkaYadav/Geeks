/*
 * ThreeSum.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: user
 */
#include <iostream>
#include<math.h>
using namespace std;
int noOfWays(int arr[],int N){
	double cnt=0,sum=0,total=0;
	for(int i=0;i<N-2;i++){
		for(int j=i+1;j<N-1;j++){
			for(int k=j+1;k<N;k++){
				sum=arr[i]+arr[j]+arr[k];
				int cuberoot=cbrt(sum);
				if(cuberoot*cuberoot*cuberoot==sum){
					cnt++;
				}
				total++;
			}
		}
	}

	double ways=cnt/total;
	printf("%.9f",ways);
	return cnt;
}
int main(){
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		noOfWays(arr,N);

	}
}

