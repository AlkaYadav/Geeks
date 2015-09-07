/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxSum(int n,int k,int values[]){
    int result[k+1];
    for(int i=0;i<=k;i++){
        result[i]=0;
    }
    result[0]=1;
    cout<<"REsult is "<<result[k]<<endl;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i>=values[j]){

                result[i]+=result[i-values[j]];
                if(i==k){
                cout<<"result is "<<result[i]<<endl;
                cout<<"result is "<<result[i-values[j]]<<endl;
                            	}
            }
        }
    }
    cout<<"REsult is "<<result[k]<<endl;
    int max_val=0;
    for(int i=0;i<=k;i++){
        if(result[i]>0&&i>=max_val){
            max_val=i;
        }
    }
    return max_val;
}

int main() {
    int T,n,k;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        cin>>k;
        int values[n];
        for(int j=0;j<n;j++){
            cin>>values[j];
        }
        cout<<maxSum(n,k,values)<<endl;
    }
    return 0;
}
*/
