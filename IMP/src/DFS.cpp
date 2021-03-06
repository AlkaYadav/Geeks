/*

 * DFS.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: user

#include<queue>
#include <iostream>
using namespace std;

//Implementing DFS using Adjacency Matrix
void dfsUtil(vector<int> *v,bool *visited,int N,int src){
	visited[src]=true;
	cout<<src<<" ";
	vector<int>::iterator it;
	for(it=v[src].begin();it!=v[src].end();it++){
		if(visited[*it]==false){
			visited[*it]=true;
			dfsUtil(v,visited,N,*it);
		}
	}
}
void dfs(vector<int> *v,int N){
	bool visited[N+1];
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
	int N,M,src,dest;
	cin>>N>>M;
	vector<int> v[N+1];

	for(int i=0;i<M;i++){

		cin>>src>>dest;
		v[src].push_back(dest);
	}
	dfs(v,N);
}


*/
