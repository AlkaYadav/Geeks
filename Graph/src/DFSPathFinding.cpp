/*

 * DFSPathFinding.cpp
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
	Node* newNode(int data);
	bool DFS_pathFindUtil(int src,int dest,int *visited,int *parent);
public:
	Graph(int vertices);
	void DFS_pathFind(int src,int dest);
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

void Graph::DFS_pathFind(int src,int dest){
	int *parent=new int[vertices];   //To find path
	int *visited=new int[vertices];
	for(int i=0;i<vertices;i++){
		parent[i]=-1;
		visited[i]=0;
	}

	if(DFS_pathFindUtil(src,dest,visited,parent)){
		int i=dest;
		while(parent[i]!=-1){
			cout<<parent[i]<<" ";
			i=parent[i];
		}
	}
	else{
		cout<<"Path not found"<<endl;
	}

}

bool Graph::DFS_pathFindUtil(int src,int dest,int *visited,int *parent){
	visited[src]=1;
	Node* tmp=adj[src];
	while(tmp){
		if(visited[tmp->data]==0){
			parent[tmp->data]=src;
			if(tmp->data==dest){
				cout<<"Path found"<<endl;
				return true;
			}
			DFS_pathFindUtil(tmp->data,dest,visited,parent);
			tmp=tmp->next;
		}
	}
	return false;
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
	g.DFS_pathFind(5,1);
}



*/
