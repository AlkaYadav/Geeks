/*
//============================================================================
// Name        : HackerEarth.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define MOD 1000000007
#define NUM 10
using namespace std;

int findCnt(char ele,char arr[][NUM],int row,int N){
	int cnt=0;
	for(int i=0;i<6;i++){
		if(arr[row][i]==ele){
			cnt++;
		}
	}
	return cnt;
}

void printArray(char arr[][NUM],int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<6;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main() {
	int N,K;
	string S;
	char a,b,c,d,e,f;
	cin>>N>>K;
	char arr[NUM][NUM];

	for(int i=0;i<N;i++){

		for(int l=0;l<6;l++){
			cin>>a;

			arr[i][l]=a;
		}


	}

	cin>>S;

	printArray(arr,N);
	long long int res=1;
	long long int combination=0;
	for(int i=0;i<S.length();i++){
		combination=0;
		for(int j=0;j<N;j++){
			long long int cnt=findCnt(S[i],arr,j,N);
			combination+=cnt;
		}
		res=(res*combination)%MOD;
	}

	cout<<res<<endl;


	return 0;
}
*/
