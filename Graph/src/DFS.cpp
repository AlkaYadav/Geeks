/*

 * DFS.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: user


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
	int time;
	Node* newNode(int data);
	void DFSUtil(int src,char *color,int *finish,stack<int>& s);
public:
	Graph(int vertex);
	void addEdge(int src,int dest);
	void addUndirectedEdge(int src,int dest);
	void DFS(int src);
	void showGraph();
	void topologicalSort(int *finish);
};

Graph::Graph(int v){
	this->vertices=v;
	this->time=0;
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

void Graph::addUndirectedEdge(int src,int dest){
	addEdge(src,dest);
	addEdge(dest,src);
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


void Graph::DFS(int src){
	char *color=new char[vertices];
	int *finish=new int[vertices];
	stack<int> s;
	for(int i=0;i<vertices;i++){
		color[i]='W';
		finish[i]=0;
	}
	DFSUtil(src,color,finish,s);
	for(int i=0;i<vertices;i++){
		if(color[i]=='W'){
			DFSUtil(i,color,finish,s);
		}
	}

	//topologicalSort(finish);
	cout<<"Topological sort"<<endl;
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}

int compare(const void* a,const void * b){
	return *(int*)b-*(int *)a;
}
void Graph::topologicalSort(int *finish){
	cout<<"Topological sort"<<endl;
	qsort(finish,vertices,sizeof(finish[0]),compare);
	for(int i=0;i<vertices;i++){
		cout<<finish[i]<<" ";
	}

}
void Graph::DFSUtil(int src,char *color,int *finish,stack<int>& s){
	time=time+1;
	color[src]='G';
	Node *tmp=adj[src];
	cout<<src<<" ";
	while(tmp){
		if(color[tmp->data]=='W'){
		DFSUtil(tmp->data,color,finish,s);
		}
		tmp=tmp->next;
	}
	color[src]='B';
	time=time+1;
	finish[src]=time;
	s.push(src);
}

int main(){
	Graph g(6);
	    g.addEdge(5, 2);
	    g.addEdge(5, 0);
	    g.addEdge(4, 0);
	    g.addEdge(4, 1);
	    g.addEdge(2, 3);
	    g.addEdge(3, 1);


	cout<<endl<<"DFS "<<endl;
	g.DFS(0);
}
*/
