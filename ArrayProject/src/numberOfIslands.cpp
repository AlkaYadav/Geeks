/*

 * numberOfIslands.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: user

#define ROW 5
#define COL 5
#include<iostream>
using namespace std;

bool isValid(int row,int col,int mat[ROW][COL],int visited[ROW][COL]){
	if(row>=0&& row<ROW && col>=0&& col<COL && mat[row][col] &&!visited[row][col]){
		return true;
	}
	return false;
}
void DFS(int mat[ROW][COL],int row,int col, int visited[ROW][COL]){
	visited[row][col]=1;
	int row_num[]={-1,-1,-1,0,0,1,1,1};
	int col_num[]={-1,0,1,1,-1,1,0,-1};
	for(int i=0;i<8;i++){
		if(isValid(row+row_num[i],col+col_num[i],mat,visited)){
			DFS(mat,row+row_num[i],col+col_num[i],visited);
		}
	}
}
int numberOfIslands(int mat[ROW][COL]){
	int count=0;
	int visited[ROW][COL];
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			visited[i][j]=0;
		}
	}

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			if(mat[i][j]&&!visited[i][j]){
				++count;
				DFS(mat,i,j,visited);

			}
		}
	}
	return count;
}

int main()
{
    int M[][COL]= { {1, 1, 0, 0, 0},
					{0, 1, 0, 0, 1},
					{1, 0, 1, 1, 1},
					{0, 0, 0, 0, 0},
					{1, 0, 1, 0, 1}
    };

cout<<"Islands "<<numberOfIslands(M);
}

*/
