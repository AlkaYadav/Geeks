/*

 * lis.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: user

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<limits.h>
using namespace std;

int lis_seq(long int a[],long int N){
    long int lis[N];
    for(long int i=0;i<N;i++){
        lis[i]=1;
    }
    for(long int i=1;i<N;i++){
        for(long int j=i-1;j>=0;j--){
            if(a[j]<a[i]&& lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }
    long int max_lis=INT_MIN;
    for(long int i=0;i<N;i++){
        if(lis[i]>max_lis){
            max_lis=lis[i];
        }
    }
    return max_lis;
}
int main() {
    long int N;
    cin>>N;
    long int a[N];
    for(long int i=0;i<N;i++){
        cin>>a[i];
    }
    cout<<"Calling LIS"<<endl;
    cout<<lis_seq(a,N);
    return 0;
}




*/
