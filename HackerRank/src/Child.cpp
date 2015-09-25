/*

 * Child.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: user



#include <cmath>
#include <cstdio>
#include <vector>
#include<cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   char a[5001],b[5001];
    cin>>a;
    cin>>b;
    int m=strlen(a);
    int LCS[m+1][m+1];
    for(int i=0;i<=m;i++){
        LCS[i][0]=0;
        LCS[0][i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
            LCS[i][j]=1+LCS[i-1][j-1];
            }
            else
            LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    cout<<LCS[m][m]<<endl;
    return 0;
}


*/
