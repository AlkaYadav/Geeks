/*

 * DiagonalSum.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT
    int N,i,j;
    cin>>N;
    int A[100][100];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    //Setting first diagonal
    int first_diagonal_sum=0;
    for( i=0;i<N;i++){
        for( j=0;j<N;j++){
            if(i==j){
                first_diagonal_sum+=A[i][j];

            }
        }
    }

      //Setting second diagonal
    if(N%2==0){
    	i=N/2-1;
    	j=N/2;
    }
    else{
        i=N/2;
        j=N/2;
    }
        int second_diagonal_sum=0;
        while(i!=-1&& j!=N){
            second_diagonal_sum+=A[i][j];
            i--;
            j++;

        }
        if(N%2==0){
        	i=N/2;
        	j=N/2-1;
        }
        else{
        i=N/2+1;
        j=N/2-1;
        }
        while(i!=N && j!=-1){
            second_diagonal_sum+=A[i][j];
            i++;
            j--;
        }

        int diff=abs(first_diagonal_sum-second_diagonal_sum);
        cout<<diff;
    return 0;
}


*/
