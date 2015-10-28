//============================================================================
// Name        : GoogleCodeJam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cmath>
#include<map>
#include<math.h>
using namespace std;

bool isprimeNumber(long long int num){
	if(num%2==0 && num!=2){
		return false;
	}
	for(long long int i=3;i<=sqrt(num);i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}

int chosePrimeFactor(long long int n){
	map<long long int,long long int> m;
	while(n%2==0){
		n=n/2;
		m[2]+=1;
	}
	for(long long int i=3;i<=sqrt(n);i++){
		while(n%i==0){
			m[i]+=1;
			n=n/i;
		}
	}
	map<long long int,long long int>::iterator it;
	long long int count=0,count2=0;
	for(it=m.begin();it!=m.end();it++){
		if(it->second>1){
			count2++;
		}
		count++;
	}
	if(count>1 && count2>0){
		return count-count2;
	}
	return count;
}
bool isGNumber(long long int n){
	long long int tmp=n,sum=0;
	while(tmp){
		sum+=tmp%10;
		tmp=tmp/10;
	}

	if(sum==1){
		return true;
	}

	bool isPrime=isprimeNumber(sum);
	return isPrime;
}
int main() {
	long long int T,N,noOfprimefactor;
	cin>>T;
	for(long long int i=1;i<=T;i++){
		cin>>N;

		if(isGNumber(N)){
			cout<<"Case #"<<i<<": "<<"Seymour"<<endl;
		}
		else{
			noOfprimefactor=chosePrimeFactor(N);

			if(noOfprimefactor%2==0){
				cout<<"Case #"<<i<<": "<<"Seymour"<<endl;
			}
			else{
				cout<<"Case #"<<i<<": "<<"Laurence"<<endl;
			}
		}
	}
	return 0;
}
