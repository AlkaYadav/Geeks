/*


 * output.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: user


#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void func(int a[],char *b){
	//Both decompose to pointers
    cout<<"A"<<sizeof(a)<<endl;
    cout<<"B"<<sizeof(b)<<endl;
}
int main()
{
	int arri[] = {1, 2 ,3};
	int *ptri = arri;

	char arrc[] = {1, 2 ,3};
	char *ptrc = arrc;
    cout<<"In main "<<endl;
    cout<<"A"<<sizeof(arri)<<endl;
    cout<<"B"<<sizeof(arrc)<<endl;
	func(arri,arrc);

	return 0;
}


int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("Number of elements between two pointer are: %d.",
                                (ptr2 - ptr1));
    printf("Number of bytes between two pointers are: %d",
                              (char*)ptr2 - (char*) ptr1);
    return 0;
}



#include<stdio.h>

void fun(int arr[])
{
  int i;
  int arr_size = sizeof(arr)/sizeof(arr[1]);
  for (i = 0; i < arr_size; i++)
      printf("%d ", arr[i]);
}

int main()
{
  int i;
  int arr[4] = {10, 20 ,30, 40};
  int *p;
  int a=5;
  p=&a;
  fun(p);
  return 0;
}
*/
