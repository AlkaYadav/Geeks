/*

 * array.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: user

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void findLeftRight(long long int *A,long long int *left,long long int *right,long long int N){
    for(long long int i=0;i<N;i++){
        long long int sum=0;
        if(i==0){
            left[i]=0;
        }
        else{
            for(int j=0;j<i;j++){
                sum+=A[j];
            }
            left[i]=sum;
        }
        sum=0;
        if(i==N-1){
            right[i]=0;
        }
        else{
            for(int j=i+1;j<N;j++){
                sum+=A[j];
            }
            right[i]=sum;
        }
    }
}

int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT
    int T;
    long long int N;
    long long int *A;
    long long int *left;
    long long int *right;
    cin>>T;
    for(int k=0;k<T;k++){
    cin>>N;
    A=new long long int [N];
    left=new long long int [N];
    right=new long long int [N];
    for(long long int i=0;i<N;i++){
        left[i]=-1;
        right[i]=-1;
        cin>>A[i];
    }
    findLeftRight(A,left,right,N);
    int flag=0;
    for(int i=0;i<N;i++){
        if(left[i]==right[i]){
            flag=1;
            cout<<"YES"<<endl;
            break;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }
    delete A;
    delete left;
    delete right;
    }
    return 0;
}




*/
