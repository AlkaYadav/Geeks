/*

 * SingleSourceShortestPath.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: user

//Shortest Path in Directed Acyclic Graph
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

void topologicalSort(vector<struct Edge* > *v,bool * visited,int src,stack<int> &s){
	visited[src]=true;
	cout<<"Source is "<<src<<" "<<endl;
	vector<struct Edge*>::iterator it;
	for(it=v[src].begin();it!=v[src].end();it++){
		struct Edge *e=*it;
		if(visited[e->dest]==false){
			topologicalSort(v,visited,e->dest,s);
		}
	}
	s.push(src);
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
	}
	cout<<"Enter source for single source shortest path"<<endl;
	cin>>source;
	bool* visited=new bool[N+1];
	stack<int> s;
	for(int k=1;k<=N;k++){
		visited[k]=false;
	}
	for(int j=1;j<=N;j++){
		if(visited[j]==false){
			topologicalSort(v,visited,j,s);
		}
	}

	int dist[N+1];
	for(int i=1;i<=N;i++){
		dist[i]=INT_MAX;
	}
	dist[source]=0;
	while(!s.empty()){
		int top=s.top();
		s.pop();
		if(dist[top]!=INT_MAX){
			vector<struct Edge*>::iterator it;
			for(it=v[top].begin();it!=v[top].end();it++){
				struct Edge * e=*it;

				if(dist[e->dest]>dist[top]+e->wt){
					dist[e->dest]=dist[top]+e->wt;
				}
			}
		}
	}

	for(int i=1;i<=N;i++){
		if(dist[i]!=INT_MAX){
			cout<<"Dist is from"<<source<<"to "<<i<<" "<<dist[i]<<endl;
		}
	}
}



*/
