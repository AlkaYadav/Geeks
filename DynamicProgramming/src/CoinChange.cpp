/*
 * CoinChange.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user
 *      Description:Minimum no. of coins to make change
 *      C(P)=1+min(C(p-vi))for all i
*/
#include<limits.h>
#include<iostream>
using namespace std;
void coinChange(int coins[],int noOfCoins,int sum){
	int table[sum+1];
	table[0]=0;
	int c;
	for(int i=1;i<=sum;i++){
		c=INT_MAX;
		for(int j=0;j<noOfCoins;j++){
			if(i>=coins[j]){
				c=min(c,table[i-coins[j]]);

			}
		}
		if(c<INT_MAX){
			table[i]=c+1;
		}
		else{
			table[i]=INT_MAX;
		}
	}
	cout<<"Minimum no. of coins are "<<table[sum]<<endl;

	//Count no. of ways to change coins
	int noOfWays[sum+1];
	for(int k=0;k<=sum;k++){
		noOfWays[k]=0;
	}
	noOfWays[0]=1;

	for(int i=0;i<noOfCoins;i++){
		for(int j=coins[i];j<=sum;j++){
			noOfWays[j]+=noOfWays[j-coins[i]];
		}
	}
	cout<<"No. of ways to count coins are "<<noOfWays[sum]<<endl;
}

int main(){
	int coins[]={2,3,7};
	int noOfCoins=sizeof(coins)/sizeof(int);
	coinChange(coins,noOfCoins,11);
	return 0;
}


