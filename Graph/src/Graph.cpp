/*
//============================================================================
// Name        : Graph.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
public:
	Graph(int vertex);
	void addEdge(int src,int dest);
	void showGraph();
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

void Graph::showGraph(){
	for(int i=0;i<vertices;i++){
		while(adj[i]){
			cout<<i<<" "<<adj[i]->data<<" "<<endl;
			adj[i]=adj[i]->next;
		}
	}
}
int main() {
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(3,2);
	g.addEdge(2,3);
	g.showGraph();
	return 0;
}
*/
