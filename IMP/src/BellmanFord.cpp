/*
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
	int dist[N+1];
	for(int i=1;i<=N;i++){
		dist[i]=INT_MAX;
	}
	dist[source]=0;
	for(int j=1;j<=N-1;j++){
		for(int i=1;i<=N;i++){
		vector<struct Edge*>::iterator it;
		for(it=v[i].begin();it!=v[i].end();it++){
			struct Edge*e =*it;

			if(dist[i]!=INT_MAX&& (dist[i]+e->wt)<dist[e->dest]){

					dist[e->dest]=dist[i]+e->wt;
			}
		}
	}

	}


	//Negative weight Cycle detection
	for(int i=1;i<=N;i++){
			vector<struct Edge*>::iterator it;
			for(it=v[i].begin();it!=v[i].end();it++){
				struct Edge*e =*it;

				if(dist[i]!=INT_MAX&& (dist[i]+e->wt)<dist[e->dest]){

						cout<<"Cycle Detected"<<endl;
				}
			}
		}
	for(int i=1;i<=N;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}

}
*/
