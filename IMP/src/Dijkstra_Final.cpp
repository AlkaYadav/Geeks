/*


 * Dijkstra.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: user



#include <iostream>
#include<stack>
#include<vector>
#include<stdlib.h>
#include<limits.h>
using namespace std;

struct Edge{
	int dest;
	int wt;
};
int findMinDistNode(int* dist,int N,bool* isIncluded){
	int mindist=INT_MAX;
	int minnode=-1;
	for(int i=1;i<=N;i++){
		if(!isIncluded[i] && dist[i]<=mindist){
			minnode=i;
			mindist=dist[i];
		}
	}
	return minnode;
}

void relaxEdges(vector<struct Edge*> *v,int minindx,int* dist,int N,bool* isIncluded){
	vector<struct Edge*>::iterator it;
	for(it=v[minindx].begin();it!=v[minindx].end();it++){
		struct Edge* e=*it;

		if(!isIncluded[e->dest]&&dist[minindx]!=INT_MAX && dist[e->dest]>dist[minindx]+e->wt){
			dist[e->dest]=dist[minindx]+e->wt;
		}
	}
}

int main(){
	//N is no. of vertices,M i sno. of edges

	int N,M,src,dest,wt,source;
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
	cout<<"Enter source for single source shortest path"<<endl;
	cin>>source;

	bool *isIncluded=new bool[N+1];
		int count=0;
		int *dist=new int[N+1];
		for(int i=1;i<=N;i++){
			dist[i]=INT_MAX;
			isIncluded[i]=false;
		}
		dist[source]=0;

		while(count!=N-1){
			int minindx=findMinDistNode(dist,N,isIncluded);
			isIncluded[minindx]=true;
			relaxEdges(v,minindx,dist,N,isIncluded);
			count++;
		}


		//Printing min distances

			for(int i=1;i<=N;i++){
				if(dist[i]!=INT_MAX)
				cout<<source<<" "<<dist[i]<<endl;
			}
}


*/
