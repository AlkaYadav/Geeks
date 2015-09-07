/*
 * BFSVector.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: user
 */

#include<vector>
#include<queue>
#include<iostream>
using namespace std;

void bfsUsingVector(vector<int>* v,int src,int n){
	queue<int> q;
	q.push(src);
	int *visited=new int[n];
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	while(!q.empty()){
		int top=q.front();
		q.pop();
		cout<<top<<" ";
		visited[top]=1;
		if(!v[top].empty()){
			for(int i=0;i<v[top].size();i++){
				if(visited[v[top][i]]==0)
				q.push(v[top][i]);
			}
		}
	}
}
int main(){
	vector<int> *v;
	int n,edges,x,y;
	cin>>n;
	v=new vector<int>[n];
	cout<<"Enter the number of edges "<<endl;
	cin>>edges;
	for(int i=0;i<edges;i++){
		cin>>x;
		cin>>y;
		v[x].push_back(y);
	}
	int src;
	cout<<"Enter source "<<endl;
	cin>>src;
	bfsUsingVector(v,src,n);
}



