/*

 * MorganString.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: user


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
    string A,B;
        stack<char> s1,s2;
        cin>>A;
        cin>>B;


        for(int i=A.length()-1;i>=0;i--){
        	char a=A[i];
            s1.push(a);
        }
        for(int i=B.length()-1;i>=0;i--){
        	char b=B[i];
            s2.push(b);
        }
        while(!s1.empty() && !s2.empty()){
            char top1=s1.top();
            char top2=s2.top();
            if(top1<=top2){
                cout<<top1;
                s1.pop();
            }
            else{
                cout<<top2;
                s2.pop();
            }
        }

        while(!s1.empty()){
            char top1=s1.top();
            cout<<top1;
            s1.pop();
        }
        while(!s2.empty()){
            char top2=s2.top();
            cout<<top2;
                s2.pop();
        }
        cout<<endl;
    }

    return 0;
}



*/
