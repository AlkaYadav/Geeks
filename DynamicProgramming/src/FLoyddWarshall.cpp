/*

 * FLoyddWarshall.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: user


#include<iostream>
#define INF 9999
#define V 4
using namespace std;
void floyddWarshall(int graph[V][V]){
	int distance[V][V];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			distance[i][j]=graph[i][j];
		}
	}

	//Floydd Warshall
	for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				for(int k=0;k<V;k++){
					if(distance[i][j]>distance[i][k]+distance[k][j]){
						distance[i][j]=distance[i][k]+distance[k][j];
					}
				}
			}
}
//Printing Shortest path matrix
	for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				cout<<distance[i][j]<<" ";
			}
			cout<<endl;
		}
}

int main(){
	int graph[V][V] = { {0,   5,  INF, 10},
	                        {INF, 0,   3, INF},
	                        {INF, INF, 0,   1},
	                        {INF, INF, INF, 0}
	                      };
	floyddWarshall(graph);
}
*/
