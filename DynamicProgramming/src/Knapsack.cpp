/*

 * 01Knapsack.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user

#include<iostream>
using namespace std;

int Knapsack_Recursive(int wt[],int val[],int n,int W){
	if(n<0){
		return 0;
	}
	if(wt[n-1]>W){
		return Knapsack_Recursive(wt,val,n-1,W);
	}
	else{
		return max(Knapsack_Recursive(wt,val,n-1,W-wt[n-1])+val[n-1],Knapsack_Recursive(wt,val,n-1,W));
	}
}

void Knapsack_DP(int wt[],int val[],int n,int W){
	int knapsack[n+1][W+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0||j==0){
				knapsack[i][j]=0;
			}
			else{
				if(wt[i-1]>j){
					knapsack[i][j]=knapsack[i-1][j];
				}
				else
					knapsack[i][j]=max(val[i-1]+knapsack[i-1][j-wt[i-1]],knapsack[i-1][j]);
			}
		}


	}
	cout<<"MAximum value using knapsack is "<<knapsack[n][W]<<endl;
}
int main(){
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int  W = 50;
	int n = sizeof(val)/sizeof(val[0]);
	printf("%d", Knapsack_Recursive(wt, val, n,W));
	cout<<"Knapsack_DP is "<<endl;
	Knapsack_DP(wt,val,n,W);
	return 0;
}

*/
