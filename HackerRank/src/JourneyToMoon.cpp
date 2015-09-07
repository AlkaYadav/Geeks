/*

 * JourneyToMoon.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: user

#include<iostream>
#include<list>
using namespace std;
long long int C(long int n,int p){
	long int c=n*(n-1)/2;
	return c;
}
void DFSUtil(list<long int> *adjList,long int source,long int *visited,long int N,long int *count,long int connnectedComp){
	visited[source]=1;
	list<long int> ::iterator it;

	for(it=adjList[source].begin();it!=adjList[source].end();it++){
		if(visited[*it]==0){
			count[connnectedComp]++;
			DFSUtil(adjList,*it,visited,N,count,connnectedComp);
		}
	}
}
void DFS(list<long int> *adjList,long int N){
	long int *visited=new long int[N];
	long int connnectedComp=-1;
	long int *count=new long int[N];
	long int sum=0;
	long long int noOfWays=0;
	for(long int i=0;i<N;i++){
		visited[i]=0;
		count[i]=1;
	}

	for(long int i=0;i<N;i++){
		if(visited[i]==0){
			connnectedComp++;
			DFSUtil(adjList,i,visited,N,count,connnectedComp);

		}
	}
	cout<<"In DFS"<<endl;
	for(long int i=0;i<=connnectedComp;i++){
		cout<<count[i]<<endl;
		sum+=count[i];
	}
	cout<<"Component "<<endl;
	for(long int i=0;i<=connnectedComp;i++){
		sum=sum-count[i];
		noOfWays+=sum*count[i];
	}
	//noOfWays=C(N,2)-noOfWays;
    cout<<noOfWays<<endl;
}
int main(){
	long int N,l,x,y;
	list<long int> *adjList;


	cin>>N>>l;
	adjList=new list<long int>[N];
	for(long int i=0;i<l;i++){
		cin>>x>>y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	DFS(adjList,N);
}


*/
