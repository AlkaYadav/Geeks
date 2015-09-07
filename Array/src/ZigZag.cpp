/*

 * ZigZag.cpp
 *
 *  Created on: Aug 27, 2015
 *      Author: user


#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void zigZag(int a[],int n){
	for(int i=0;i<n-1;i++){
		if(i%2==0){
			if(a[i]>a[i+1]){
				swap(&a[i],&a[i+1]);
			}
		}
		else{
			if(a[i]<a[i+1]){
							swap(&a[i],&a[i+1]);
						}
		}
	}
}


int main(){
	int  arr[] = {4, 3, 7, 8, 6, 2, 1};
	    int n = sizeof(arr)/sizeof(arr[0]);
	    zigZag(arr, n);
	    for (int i=0; i<n; i++)
	        cout << arr[i] << "  ";
}
*/
