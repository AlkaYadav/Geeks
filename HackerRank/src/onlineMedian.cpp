/*

 * onlineMedian.cpp
 *
 *  Created on: Sep 24, 2015
 *      Author: user


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int compare(int a,int b){
    return a>b;
}

int main() {


    int N,ele;
    vector<int> v_max,v_min;
    int v_max_size,v_min_size;
    v_max.push_back(1);
    make_heap(v_max.begin(),v_max.end());
    make_heap(v_min.begin(),v_min.end(),compare);
    v_max_size=v_max.size();
    v_min_size=v_min.size();

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>ele;
        v_max_size=v_max.size();
        v_min_size=v_min.size();
        if(v_max_size==v_min_size){
            //insert in max_heap
            v_max.push_back(ele);
            push_heap(v_max.begin(),v_max.end());
        }
        else if(v_max_size>v_min_size){
            //pop from max_heap and push in min heap and push the new element in max_heap
            pop_heap(v_max.begin(),v_max.end());
            int top_max=v_max[v_max.size()-1];
            v_max.pop_back();

            v_min.push_back(top_max);
            push_heap(v_min.begin(),v_min.end(),compare);

            v_max.push_back(ele);
            push_heap(v_max.begin(),v_max.end());
        }

           v_max_size=v_max.size();
        v_min_size=v_min.size();
                double median=0;
                if(v_max_size>v_min_size){
                   median=v_max[0];
                }
                else if(v_max_size==v_min_size){
                    int median=((double)v_max[0]+(double)v_min[0])/2;
                }
                printf("%.1f\n",median);
    }
    return 0;
}



*/
