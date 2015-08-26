/*
//============================================================================
// Name        : Array.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define C 3
#define R 3
using namespace std;

//Find sum of all elements in a matrix except the elements in row and/or column of given cell?
struct cell{
	int r;
	int c;
};
void sum(int a[][C],struct cell acell[],int n){
	int sum;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=0;j<R;j++){
			for(int k=0;k<C;k++){
				if(j!=acell[i].r && k!=acell[i].c){
					sum+=a[j][k];
				}
			}
		}
		cout<<"Sum "<<sum;
	}
}

void sum_efficient(int a[][C],struct cell acell[],int n){
	int total_sum=0;
	int row_sum[R];
	int col_sum[C];

	for(int i=0;i<R;i++){
		row_sum[i]=0;
	}
	for(int j=0;j<C;j++){
		col_sum[j]=0;
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			total_sum+=a[i][j];
			row_sum[i]+=a[i][j];
			col_sum[j]+=a[i][j];
		}
	}

	for(int k=0;k<n;k++){
		int sum=0;
		int i=acell[k].r;
		int j=acell[k].c;
		sum=total_sum-row_sum[i]-col_sum[j]+a[i][j];
		cout<<sum<<" ";
	}
}
int main() {
	int a[][C]={
			{1, 1, 2}, {3, 4, 6}, {5, 3, 2}
	};
	struct cell arr[] = {{0, 0}, {1, 1}, {0, 1}};
	int n=sizeof(arr)/sizeof(arr[0]);
	//sum(a,arr,n);
	sum_efficient(a,arr,n);
	return 0;
}
*/
