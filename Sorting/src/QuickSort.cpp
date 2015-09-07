/*
//============================================================================
// Name        : Sorting.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int l,int h,int x){
	int i=l-1;
	int j;
	for(j=l;j<h;j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[j]);
	return (i+1);
}

void quicksort(int a[],int l,int h){
	if(l<h){
	int x=a[h];

	int p=partition(a,l,h,x);
	quicksort(a,l,p-1);
	quicksort(a,p+1,h);
	}
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
	int arr[] = {10, 7, 8, 9, 1, 5};
	    int n = sizeof(arr)/sizeof(arr[0]);
	    quicksort(arr, 0, n-1);
	    printf("Sorted array: \n");
	    printArray(arr, n);
	return 0;
}
*/
