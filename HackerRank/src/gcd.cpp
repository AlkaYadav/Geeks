/*

 * gcd.cpp
 *
 *  Created on: Sep 20, 2015
 *      Author: user





#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<limits.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    if(a==1||b==1){
        return 1;
    }
    if(a>b){
        return gcd(b,a%b);
    }
    return gcd(a,b%a);
}

int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT
    int T,l,b;

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>l>>b;
       int g=gcd(l,b);
      //  int g=1;
        int res=(l*b)/(g*g);
        cout<<res<<endl;

    }
    return 0;
}
*/
