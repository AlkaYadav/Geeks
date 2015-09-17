/*

 * sortKSortedArray.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: user


//Sort a nearly sorted (or K sorted) array
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<functional>
using namespace std;

void printVector(vector<int> heap){
	cout<<endl<<"Vector is "<<endl;
	for(int i=0;i<heap.size();i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}
void sortedK(int arr[],int n,int k){
	int result[n];
	vector<int> v(arr,arr+k+1);
	int indx=0;
	make_heap(v.begin(),v.end(),greater<int>());
	cout<<"After making heap "<<endl;
	printVector(v);

	int i=k+1;
	while(!v.empty()){
		if(i<n){
	cout<<"The fron ele is "<<v.front()<<endl;
	result[indx++]=v.front();
	pop_heap(v.begin(),v.end(),greater<int>());
	v.pop_back();
	v.push_back(arr[i]);
	push_heap(v.begin(),v.end(),greater<int>());
	i++;
	}
		else{
			cout<<"The fron ele is "<<v.front()<<endl;
				result[indx++]=v.front();
				pop_heap(v.begin(),v.end(),greater<int>());
				v.pop_back();
		}

}

	for(int i=0;i<n;i++){
		arr[i]=result[i];
	}

}

void heapPrac(){
	vector<int> v;
	make_heap(v.begin(),v.end());
	for(int i=5;i>=0;i--){
		v.push_back(i);
		push_heap(v.begin(),v.end());
		cout<<"Front is "<<v.front()<<endl;
		printVector(v);
	}
	cout<<"Now sorting ..."<<endl;
	sort_heap(v.begin(),v.end());
	printVector(v);
	while(!v.empty()){

		pop_heap(v.begin(),v.end(),greater<int>());
		cout<<"Front is "<<v.front()<<endl;
		v.pop_back();
	}
}
int main()
{
    int k = 3;
    int arr[] = { 6,2, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapPrac();
    //sortKSortedArray(arr, n, k);

    sortedK(arr,n,k);
   for(int i=0;i<n;i++){
	   cout<<arr[i]<<" ";
   }

    return 0;
}
*/
