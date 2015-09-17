/*

 * CustomizedGraph.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: user

#include<queue>
#include <iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct Edge{
	int dest;
	int cost;
	int dist;
};
void dfsUtil(vector<struct Edge*> *v,bool *visited,int N,int src){
	visited[src]=true;
	cout<<src<<" ";
	vector<struct Edge*>::iterator it;
	for(it=v[src].begin();it!=v[src].end();it++){
		struct Edge* e=*it;
		if(visited[e->dest]==false){
			visited[e->dest]=true;
			dfsUtil(v,visited,N,e->dest);
		}
	}

	}
void dfs(vector<struct Edge*> *v,int N){
	bool * visited=new bool[N+1];
	for(int i=1;i<=N;i++){
			visited[i]=false;
		}
		cout<<"In dfs ";
		for(int i=1;i<=N;i++){
			if(visited[i]==false){
				//cout<<"In dfs "<<i<<endl;
				dfsUtil(v,visited,N,i);
			}
		}
}

int main(){
		int N,M,src,wt;
		int dest;
			int cost;
			int dist;
		int sum=0;
		cin>>N>>M;
		vector<struct Edge*> v[N+1];
		for(int i=0;i<M;i++){
			cin>>src;
			cin>>dest;
			cin>>cost;
			cin>>dist;
			struct Edge *e=(struct Edge *)malloc(sizeof(struct Edge));
			e->dest=dest;
			e->cost=cost;
			e->dist=dist;
			v[src].push_back(e);
		}
		dfs(v,N);
		vector<struct Edge*>::iterator it;
		int i=0;
		for(it=v[i].begin();it!=v[i].end();it++){
			struct Edge* p=*it;
			cout<<"dest is "<<p->dest<<endl;
		}

}
*/
