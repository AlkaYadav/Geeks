/*
//============================================================================
// Name        : HackerRank.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printStair(int h){
	for(int i=1;i<=h;i++){

		for(int j=h-i;j>0;j--){
			cout<<" ";
		}

		for(int k=i;k>0;k--){
			cout<<"#";
		}


		cout<<endl;
	}

}
void bigFactorial(int number){
	int fact[100];
	int index=0,digits;
	int num=number;
	while(num){
		fact[digits++]=num%10;
		num=num/10;
	}
	int carry=0;
	int j=0;
	for(int i=2;i<num;i++)
	{	while(j!=)
		res=num*i;
		product=fact[j]*i;
		fact[j]=product%10;
		carry=product/10;
		while(carry){
			j++;
			fact[j]+=carry;

		}

	}
}
void SherlockandMovingTales(){
	long double L,S1,S2;
	    long int Q;
	    long double qi;
	    long double a,t;
	    cin>>L>>S1>>S2;
	    cin>>Q;
	    for(int i=0;i<Q;i++){
	        cin>>qi;
	        a=sqrt(qi);
	        t=(L-a)*sqrt(2)/(S2-S1);
	        cout<<t<<endl;
	    }
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT
    int T,N,a;
    cin>>T;
    for(int i=0;i<T;i++){
        int res=1;
        cin>>N;
        for(int j=0;j<N-1;j++){
            cin>>a;
            res*=a;
        }
        cout<<res<<endl;

    }
    return 0;
}

*/
