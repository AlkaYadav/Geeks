/*
 * DFS_StronglyCConnected.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: user
 */

#include<queue>
#include<stack>
#include<algorithm>
#include <iostream>
using namespace std;
class Node{
	int data;
	Node* next;
	friend class Graph;

};
class Graph{
	int vertices;
	Node **adj;
	Node* newNode(int data);
	void DFSUtil(int src,char *color,stack<int>& s);
public:
	Graph(int vertex);
	void addEdge(int src,int dest);
	void DFS(int src);
	Graph transposeGraph();
};

Graph::Graph(int v){
	this->vertices=v;
	adj=new Node*[vertices];
	for(int i=0;i<vertices;i++){
		adj[i]=NULL;
	}
}

Node* Graph::newNode(int data){
	Node* tmp=new Node();
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}

void Graph::addEdge(int src,int dest){
	if(adj[src]==NULL){
		adj[src]=newNode(dest);
	}
	else{
		Node *tmp=newNode(dest);
		tmp->next=adj[src];
		adj[src]=tmp;
	}
}

void Graph::DFS(int src){
	char *color=new char[vertices];
	stack<int> s;
	for(int i=0;i<vertices;i++){
		color[i]='W';
	}
	for(int i=0;i<vertices;i++){
		if(color[i]=='W'){
			DFSUtil(i,color,s);
		}
	}

	//Transpose graph
	Graph g=transposeGraph();
	for(int i=0;i<vertices;i++){
			color[i]='W';
		}
	stack<int> s2;
	cout<<endl<<"Strongly Connected Components"<<endl;
	while(!s.empty()){
		if(color[s.top()]=='W'){
		g.DFSUtil(s.top(),color,s2);
		cout<<endl;
		}
		s.pop();

	}
}

Graph Graph::transposeGraph(){
	Graph g(vertices);
	for(int i=0;i<vertices;i++){
		Node* tmp=adj[i];
		while(tmp){
			g.addEdge(tmp->data,i);
			tmp=tmp->next;
		}

	}
return g;
}
void Graph::DFSUtil(int src,char *color,stack<int>& s){
	color[src]='G';
	Node *tmp=adj[src];
	cout<<src<<" ";
	while(tmp){
		if(color[tmp->data]=='W'){
		DFSUtil(tmp->data,color,s);
		}
		tmp=tmp->next;
	}
	color[src]='B';
	s.push(src);
}
int compare(const void* a,const void * b){
	return *(int*)b-*(int *)a;
}

int main(){
	Graph g(5);
	 g.addEdge(1, 0);
	    g.addEdge(0, 2);
	    g.addEdge(2, 1);
	    g.addEdge(0, 3);
	    g.addEdge(3, 4);


	cout<<endl<<"DFS "<<endl;
	g.DFS(0);
}
