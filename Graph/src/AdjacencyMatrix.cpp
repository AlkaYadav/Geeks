/*

 * AdjacencyMatrix.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: user

#include<iostream>
#include<stdio.h>
using namespace std;
class Graph{
	int vertices;
	int **adj;
public:
	Graph(int vertex);
	void addEdge(int src,int dest);
	void displayGraph();
};

Graph::Graph(int v){
	this->vertices=v;
	adj=new int*[vertices];
	for(int i=0;i<vertices;i++){
		adj[i]=new int[vertices];
	}
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++)
			adj[i][j]=0;
		}
}

void Graph::addEdge(int src,int dest){
	adj[src][dest]=1;
}

void Graph::displayGraph(){
	for(int i=0;i<vertices;i++){
			for(int j=0;j<vertices;j++)
				cout<<adj[i][j]<<" ";
			cout<<endl;
			}
}

int main() {
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(3,2);
	g.addEdge(2,3);
	g.displayGraph();
	return 0;
}
*/
