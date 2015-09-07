/*

 * longestConsecutivePath.cpp
 *
 *  Created on: Aug 27, 2015
 *      Author: user


#include<iostream>
#define ROW 3
#define COL 3
using namespace std;

int xMove[8] = {  -1, -1,-1, 0, 0, 1, 1, 1};
int yMove[8] = { -1, 0,  1,  -1, 1, -1, 0, 1 };

bool areConsecutive(char a[ROW][COL],int x,int y,int next_x,int next_y){
	if(next_x>=0 && next_x<ROW && next_y>=0 && next_y<COL){
		if(a[next_x][next_y]==a[x][y]+1){
			return true;
		}
	}
	return false;
}
int checklongestConsecutivePath(char a[ROW][COL],int x,int y){
	int count=1;
	for(int i=0;i<8;i++){
		int next_x=x+xMove[i];
		int next_y=y+yMove[i];

		if(areConsecutive(a,x,y,next_x,next_y)){

			count=max(count,1+checklongestConsecutivePath(a,next_x,next_y));

		}

	}
	return count;
}

int main(){
	char mat[ROW][COL] = { {'a', 's', 'd'},
	                       {'c', 'b', 'e'},
	                       {'d', 'h', 'f'}};
	int maxsum=0;
	cout<<"Max" <<checklongestConsecutivePath(mat,1,1);

}
*/
