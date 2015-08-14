/*
 * MaximumSquareSubmatrix.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: user
 */

#define R 6
#define C 5
#include<iostream>
#include<limits.h>
using namespace std;
void maximumSquareSubmatrix(bool arr[R][C]){
	int S[R][C];
	for(int i=0;i<R;i++){
		S[i][0]=arr[i][0];
	}
	for(int i=0;i<C;i++){
			S[0][i]=arr[0][i];
	}
	for(int i=1;i<R;i++){
		for(int j=1;j<C;j++){
			if(arr[i][j]==1)
			S[i][j]=min(S[i-1][j],min(S[i][j-1],S[i-1][j-1]))+1;
			else
				S[i][j]=0;
		}
	}

	cout<<"Original Matrix:"<<endl;
	for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
	}

	cout<<"Transformed Matrix:"<<endl;
		for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					cout<<S[i][j]<<" ";
				}
				cout<<endl;
		}
		int max_matrix=INT_MIN;
		int max_matrix_i,max_matrix_j;
		for(int i=0;i<R;i++){
						for(int j=0;j<C;j++){
							if(S[i][j]>max_matrix){
								max_matrix_i=i;
								max_matrix_j=j;
								max_matrix=S[i][j];
							}
						}
		}

		for(int i=max_matrix_i;i>max_matrix_i-max_matrix;i--){
			for(int j=max_matrix_j;j>max_matrix_j-max_matrix;j--){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
}

int main(){
	bool M[R][C] =  {{0, 1, 1, 0, 1},
	                   {1, 1, 0, 1, 0},
	                   {0, 1, 1, 1, 0},
	                   {1, 1, 1, 1, 0},
	                   {1, 1, 1, 1, 1},
	                   {0, 0, 0, 0, 0}};
	maximumSquareSubmatrix(M);
}

