/*
 * Djikstra_heap.cpp
 *
 *  Created on: Sep 24, 2015
 *      Author: user
 */




#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<limits.h>
#include <algorithm>
using namespace std;
struct Edge
{
    int dest;
    int wt;
};
struct heapnode{
    int vertex;
    int d;
};
int compare(struct heapnode* a,struct heapnode* b){
    return (a->d)>(b->d);
}

void printContent(vector<struct heapnode*> v_heap){
    cout<<"Contents of heap are "<<endl;
    vector<struct heapnode*>::iterator it;
    for(it=v_heap.begin();it!=v_heap.end();it++){
        struct heapnode* a=*it;
        cout<<a->vertex<<" "<<a->d<<endl;
    }
    cout<<"Ending Contents of heap  "<<endl;
}
int main() {
    int T,N,M,source,x,y,r;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N>>M;
        vector<struct Edge*> v[N+1];
        for(int j=0;j<M;j++){
            cin>>x>>y>>r;
            struct Edge* e=(struct Edge*)malloc(sizeof(struct Edge));
            e->dest=y;
            e->wt=r;
            v[x].push_back(e);

            struct Edge* e1=(struct Edge*)malloc(sizeof(struct Edge));
            e1->dest=x;
            e1->wt=r;
            v[y].push_back(e1);
        }
        bool *isIncluded=new bool[N+1];


        cin>>source;

        int count=0;

        vector<struct heapnode*> v_heap;
        make_heap(v_heap.begin(),v_heap.end(),compare);
        struct heapnode* hnode=(struct heapnode*)malloc(sizeof(struct heapnode));
        hnode->d=0;
        hnode->vertex=source;
        v_heap.push_back(hnode);
        push_heap(v_heap.begin(),v_heap.end(),compare);
        int *dist=new int[N+1];
        for(int k=0;k<=N;k++){
            isIncluded[k]=false;
            dist[k]=-1;
        }

        while(count!=N && v_heap.size()!=0){

                            struct heapnode* minindex=v_heap.front();

                            pop_heap(v_heap.begin(),v_heap.end(),compare);
                            v_heap.pop_back();

                            if(dist[minindex->vertex]<0){

                                dist[minindex->vertex]=minindex->d;
                                isIncluded[minindex->vertex]=true;
                                count++;

                                //Relaxing edges
                            vector<struct Edge*>::iterator it;
                                for(it=v[minindex->vertex].begin();it!=v[minindex->vertex].end();it++){
                                    struct Edge* e=*it;
                                   if(!isIncluded[e->dest]){

                                        struct heapnode* hn=(struct heapnode*)malloc(sizeof(struct heapnode));
                                        hn->d=dist[minindex->vertex]+e->wt;
                                        hn->vertex=e->dest;

                                        v_heap.push_back(hn);
                                        push_heap(v_heap.begin(),v_heap.end(),compare);
                                   }
                                }
                            }
        }

       // cout<<"Printin"<<endl;
        for(int i=1;i<=N;i++){
            int val;

            if(i!=source){
                if(dist[i]==INT_MAX){
                    val=-1;
                }
                else{
                    val=dist[i];
                }
            cout<<val<<" ";
        }
    }
        cout<<endl;
    }

    return 0;
}
