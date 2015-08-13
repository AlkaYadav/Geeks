/*
 * Caesar.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,K;
    cin>>N;
    char S[N];

    cin>>S;
    cin>>K;
    for(int i=0;i<N;i++){
        if((S[i]>='A'&& S[i]<='Z')||(S[i]>='a'&& S[i]<='z')){
            S[i]=(S[i]+K)%26;
        }
    }
    cout<<S;
    return 0;
}




