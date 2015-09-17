/*

 * FloyddWarshall.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: user


//The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. (directed graph)

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
	//N is no. of vertices,M is no. of edges

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

	int dist[N+1][N+1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			dist[i][j]=INT_MAX;
		}
	}

	//Fill up dist initially

	for(int i=1;i<=N;i++){
		vector<struct Edge*>::iterator it;
		for(it=v[i].begin();it!=v[i].end();it++){
			struct Edge*e=*it;
			dist[i][e->dest]=e->wt;
		}
	}

	for(int i=1;i<=N;i++){
		dist[i][i]=0;

	}
	//Update dist
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	//Printing dist
	for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				cout<<dist[i][j]<<"  ";
			}
			cout<<endl;
	}
}

*/
