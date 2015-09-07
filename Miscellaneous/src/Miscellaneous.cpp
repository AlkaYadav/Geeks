/*
//============================================================================
// Name        : Miscellaneous.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<limits.h>
using namespace std;

//Find all possible combinations to construct a given value from an array
void printArray(int arr[],int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int countNoOfAllWays(int coins[],int value,int index,int noOfCoins){
	static int arr[50];
	int count=0;

	if(value==0){
		printArray(arr,index);
		return 1;
	}
	if(value<0){
		return 0;
	}
	for(int i=0;i<noOfCoins;i++){
		arr[index]=coins[i];
		cout<<"Value of index is "<<index<<endl;
		count+=countNoOfAllWays(coins,value-coins[i],index+1,noOfCoins);
	}
	return count;
}

//Find all possible distinct combinations to construct a given value from an array
int countNoOfDistinctWays(int coins[],int value,int index,int noOfCoins){
	static int arr[50];

		if(value==0){
			printArray(arr,index);
			return 1;
		}
		if(value<0 || noOfCoins==0){
			return 0;
		}
		if(value>=coins[noOfCoins-1]){
		arr[index]=coins[noOfCoins-1];
		}

		return countNoOfDistinctWays(coins,value-coins[noOfCoins-1],index+1,noOfCoins)+
				countNoOfDistinctWays(coins,value,index,noOfCoins-1);
}

//Find MINIMUM no. of coins to construct a given value from an array
int countMinimumNoOfCoins(int coins[],int value,int index,int noOfCoins,int &minimum){
	static int arr[50];

		if(value==0){
			if(index<=minimum){
				minimum=index;
				cout<<"Index being passed is "<<index<<"and minimum is "<<minimum<<endl;
			printArray(arr,index);
			}
			return 1;
		}
		if(value<0 || noOfCoins==0){
			return 0;
		}
		if(value>=coins[noOfCoins-1]){
		arr[index]=coins[noOfCoins-1];
		}

		return countMinimumNoOfCoins(coins,value-coins[noOfCoins-1],index+1,noOfCoins,minimum)+
				countMinimumNoOfCoins(coins,value,index,noOfCoins-1,minimum);
}
int main() {
	int coins[]={1,2};
	int value=4;
	int noOfCoins=sizeof(coins)/sizeof(int);
	int index=0;
	int minimum=INT_MAX;
	cout <<countNoOfAllWays(coins,value,index,noOfCoins);
	//cout<<countNoOfDistinctWays(coins,value,index,noOfCoins);
	//cout<<"Minimum no. of coins "<<countMinimumNoOfCoins(coins,value,index,noOfCoins,minimum)<<endl;
	return 0;
}
*/
