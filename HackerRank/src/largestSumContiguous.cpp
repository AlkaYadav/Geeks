/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<limits.h>
using namespace std;
int longestSumContiguous(long int a[],long int N){
    long int curr_sum=a[0],max_sum=a[0];
    for(long int i=1;i<N;i++){
        curr_sum=max(a[i],a[i]+curr_sum);
        max_sum=max(curr_sum,max_sum);
    }
    return max_sum;
}

int longestSumNonContiguous(long int a[],long int N){
    long int max_sum=0;
    for(long int i=0;i<N;i++){
        if(a[i]>0){
            max_sum+=a[i];
        }

        }
    return max_sum;
}
int main() {
    int T;
    long int N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        long int a[N];
        for(long int i=0;i<N;i++){
            cin>>a[i];
        }
        cout<<longestSumContiguous(a,N)<<" "<<longestSumNonContiguous(a,N)>0?longestSumNonContiguous(a,N):longestSumContiguous(a,N);
        cout<<endl;
    }
    return 0;
}
*/
