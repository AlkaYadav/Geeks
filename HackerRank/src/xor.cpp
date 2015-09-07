/*

 * xor.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: user





#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long int calDigit(long int integer){
	long int count=1;
	while(integer){
		count++;
		integer=integer/10;
	}
	return count;
}


int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT
    int T;
    int xor2;
    long int integer,digit;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>integer;
        digit=calDigit(integer);
        xor2=pow(2,digit)-1;
        integer=integer^xor2;
        cout<<integer<<endl;
    }
    return 0;
}
*/
