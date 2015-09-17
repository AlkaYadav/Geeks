#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<limits.h>
#include <algorithm>
using namespace std;
struct Edge{
    int dest;
    int wt;
};
int findMinDistNode(int *dist,int N,bool *isIncluded){
    int mindist=INT_MAX;
    int minnode=-1;
    for(int i=1;i<=N;i++){
        if(!isIncluded[i]&& dist[i]<=mindist){
            mindist=dist[i];
            minnode=i;
        }
    }
    return minnode;
}

void relaxEdges(vector<struct Edge*>* v,int *dist,int N,bool *isIncluded,int minindx){
    vector<struct Edge*>::iterator it;
    for(it=v[minindx].begin();it!=v[minindx].end();it++){
        struct Edge* e=*it;
        if(!isIncluded[e->dest]&& dist[minindx]!=INT_MAX && dist[e->dest]>dist[minindx]+e->wt){
            dist[e->dest]=dist[minindx]+e->wt;
        }
    }
}
int main() {
   int T,N,M,src,dest,wt;
    int source;

    cin>>T;
    for(int x=0;x<T;x++){
        cin>>N>>M;
        vector<struct Edge*> v[N+1];
        for(int i=0;i<M;i++){
            cin>>src>>dest>>wt;
            struct Edge* e=(struct Edge*)malloc(sizeof(struct Edge));
            e->dest=dest;
            e->wt=wt;
            v[src].push_back(e);

            struct Edge* e1=(struct Edge*)malloc(sizeof(struct Edge));
            e1->dest=src;
            e1->wt=wt;
            v[dest].push_back(e1);
        }
        cin>>source;
        int dist[N+1];
        bool* isIncluded=new bool[N+1];
        for(int i=1;i<=N;i++){
            dist[i]=INT_MAX;
            isIncluded[i]=false;
        }
        dist[source]=0;
        int count=-1;
        while(count!=N-1){
        int minindx=findMinDistNode(dist,N,isIncluded);
          isIncluded[minindx]=true;
            relaxEdges(v,dist,N,isIncluded,minindx);
            count++;
        }
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
    }
    return 0;
}
