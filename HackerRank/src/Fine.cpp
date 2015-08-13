/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT
    int D,M,YYYY; //actual
    int d,m,yyyy;  //expected
    int fine;
    cin>>D>>M>>YYYY;
    cin>>d>>m>>yyyy;
    if(YYYY<=yyyy){
        if(M<=m){
            if(M==m){
            if(D<=d){
                fine=0;
            }
            else{
                fine=15*(D-d);
            }
            }
            else fine=0;
        }
        else{
            fine=500*(M-m);
        }
    }
    else{
        fine=10000;
    }
    cout<<fine<<endl;
    return 0;
}
*/
