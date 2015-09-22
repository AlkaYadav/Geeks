/*
 * MSexcelColName.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: user
 */

#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

char* colNameFromNumber(int num){
	int p=1;
	int rem=0;
	char * res=new char[100];
	int i=0;
	while(num){
		rem=num%27;
		res[i++]=('A'+(rem-1));
		num=num/26;
	}
	res[i]='\0';
	cout<<"In func"<<res<<endl;
	return res;
}

int main(){
	int num;
	cin>>num;
	string res;
	res=colNameFromNumber(num);
	cout<<res;
	reverse(res.begin(),res.end());
	cout<<"After reverse "<<res<<endl;



}

