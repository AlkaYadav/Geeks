/*

 * EggDroppingPuzzle.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user
 *      Description:Minimum no. of trials needed to find the critical floor in worst case

#include<limits.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int eggDropping(int n,int k){
	if (k == 1 || k == 0)
			return k;
	if (n == 1)
			return k;

	int min=INT_MAX;
	int count,i;
	for(i=1;i<=k;i++){
		count=max(eggDropping(n-1,i-1),eggDropping(n,k-i));
		if(count<min){
			min=count;
		}
	}
	return min+1;
}
int eggDrop(int n, int k)
{
	// If there are no floors, then no trials needed. OR if there is
	// one floor, one trial needed.
	if (k == 1 || k == 0)
		return k;

	// We need k trials for one egg and k floors
	if (n == 1)
		return k;

	int min = INT_MAX, x, res;

	// Consider all droppings from 1st floor to kth floor and
	// return the minimum of these values plus 1.
	for (x = 1; x <= k; x++)
	{
		res = max(eggDrop(n-1, x-1), eggDrop(n, k-x));
		if (res < min)
			min = res;
	}

	return min + 1;
}

void eggDropping_DP(int n,int k){
	int egg[n+1][k+1];
	for(int i=1;i<=n;i++){
		egg[i][0]=0;
		egg[i][1]=1;
	}
	for(int i=1;i<=k;i++){
		egg[1][i]=i;
	}
	int count,min=INT_MAX;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			egg[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				count=1+max(egg[i-1][x-1],egg[i][j-x]);

			if(count<egg[i][j]){
				cout<<"Floor being considered is "<<j<<endl;
				egg[i][j]=count;
			}
		}
		}
	}
	cout<<"Minimum no. of trials needed to find the critical floor in worst case"<<egg[n][k]<<endl;
}
int main(){
	cout<<"Minimum no. of trials needed to find the critical floor in worst case "<<eggDropping(2,10)<<endl;
	cout<<"Dynamic Programming "<<endl;
	eggDropping_DP(2,10);
}


*/
