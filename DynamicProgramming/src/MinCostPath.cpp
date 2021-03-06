/*

 * MinCostPath.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: user

#define R 3
#define C 3
#include<limits.h>
#include<iostream>
using namespace std;
void minCostPath(int cost[R][C],int m,int n){
	int tc[R][C];
	tc[0][0]=cost[0][0];

	//Table initialization
	for(int i=1;i<m;i++){
		tc[i][0]=cost[i][0]+tc[i-1][0];
	}
	for(int j=1;j<n;j++){
			tc[0][j]=cost[0][j]+tc[0][j-1];
	}

	//Filling up table
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			tc[i][j]=min(tc[i-1][j],min(tc[i][j-1],tc[i-1][j-1]))+cost[i][j];

		}
	}
	cout<<"Min Cost Path is "<<tc[m-1][n-1]<<endl;
	//Printing table...
	for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<tc[i][j]<<" ";
			}
			cout<<endl;
	}

	//Printing Min Cost Path
	int i=m-1;
	int j=n-1;
	int mini,min1,min2,min3;
	cout<<"Printing values on min cost path"<<endl;
	while(i>=0&& j>=0){
		mini=INT_MAX;
		cout<<cost[i][j]<<" ";
		min1=tc[i-1][j-1];
		min2=tc[i-1][j];
		min3=tc[i][j-1];
		mini=min(min1,min2);
		mini=min(mini,min3);
		if(mini==min1){
			i--;
			j--;
		}
		else if(mini==min2){
			i--;
		}
		else{
			j--;
		}
	}

}

int main(){
	int cost[R][C] = { {1, 2, 3},
	                      {4, 8, 2},
	                      {1, 5, 3} };
	minCostPath(cost,R,C);
}

*/
