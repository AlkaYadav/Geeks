/*

 * DFSDetectcycle.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: user


#include<iostream>
using namespace std;

class Node{
	int data;
	Node* next;
	friend class Graph;
};

class Graph{
	int vertices;
	Node** adj;
	void DFS_detectCycleUtil(int src,char * color);
	Node* newNode(int data);
public:
	Graph(int vertices);
	void DFS_detectCycle();
	void addEdge(int src,int dest);
};

Graph::Graph(int vertices){
	this->vertices=vertices;
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

void Graph::DFS_detectCycle(){
	char *color=new char[vertices];   //To detect cycle
	for(int i=0;i<vertices;i++){
		color[i]='W';
	}

	for(int i=0;i<vertices;i++){
		if(color[i]=='W'){
			DFS_detectCycleUtil(i,color);
		}
	}
}

void Graph::DFS_detectCycleUtil(int src,char* color){
	color[src]='G';
	Node * tmp=adj[src];
	cout<<src<<" ";
	while(tmp){
		if(color[tmp->data]=='W'){

			DFS_detectCycleUtil(tmp->data,color);
		}
		else if(color[tmp->data]=='G'){
			cout<<"Cycle Detected"<<endl;
			return;
		}
		tmp=tmp->next;
	}
	color[src]='B';
}

int main(){
	Graph g(7);
	    g.addEdge(5, 2);
	    g.addEdge(5, 0);
	    g.addEdge(4, 0);
	    g.addEdge(4, 1);
	    g.addEdge(2, 3);
	    g.addEdge(3, 1);
	    g.addEdge(1,5);
	cout<<endl<<"DFS "<<endl;
	g.DFS_detectCycle();
}
*/
