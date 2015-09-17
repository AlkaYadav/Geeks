/*
//Find the minimum distance between two numbers
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<functional>
using namespace std;
int minDist(int a[],int n,int x,int y){
	int prev=-1,mindist=INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i]==x|| a[i]==y){
			prev=i;
			break;
		}
	}
	if(prev==-1){
		return -1;
	}
	for(int i=prev;i<n;i++){
		if(a[i]==x|| a[i]==y){
			if(a[i]!=a[prev] && mindist>i-prev){
				mindist=i-prev;
			}
			prev=i;
		}
	}

	cout<<"Minimum dist is "<<mindist<<endl;
	return mindist;
}
int main()
{
    int arr[] ={3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 6;

    printf("Minimum distance between %d and %d is %d\n", x, y,
              minDist(arr, n, x, y));
    return 0;
}
*/
