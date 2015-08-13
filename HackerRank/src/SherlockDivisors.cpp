/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numberOfDivisors(int N){
    int count=0;
    if(N&1){
        return 0;
    }
else count++;
    for(long int i=2;i<=N/2;i++){
        if(N%i==0){
            if(i&1){

            }
                else count++;
            }
        }


    return count;
}
int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT
    int T;
    long long int N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        int t=numberOfDivisors(N);
        cout<<t<<endl;
    }
    return 0;
}
*/
