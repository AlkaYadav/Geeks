/*

 * candies.cpp
 *
 *  Created on: Sep 19, 2015
 *      Author: user

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int N,count=0,rating;
    vector<long long int> v;
    cin>>N;
    for(long long int i=0;i<N;i++){
        cin>>rating;
        v.push_back(rating);
    }

    vector<long long int> v_count;

    v_count[0]=1;
    count=v_count[0];
     for(long long int i=1;i<N;i++){
         if(v[i]>v[i-1]){
             v_count[i]=v_count[i-1]+1;
         }
         else{
             v_count[i]=1;
         }
         count+=v_count[i];
     }
    cout<<count<<endl;

    return 0;
}




*/
