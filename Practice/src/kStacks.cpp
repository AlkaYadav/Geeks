/*

 * kStacks.cpp
 *
 *  Created on: Aug 22, 2015
 *      Author: user


//Implement k stacks in an array
#include<iostream>
#include<queue>
using namespace std;
class kStacks{
	int *arr;
	int *top;
	int *next;
	int free;
public:
	kStacks(int k,int n);
	void push(int sn,int item);
	int pop(int sn);
};

kStacks::kStacks(int k,int n){
	top=new int[k];
	next=new int[n];
	arr=new int[n];
	free=0;
	for(int i=0;i<k;i++){
		top[i]=-1;
	}
	for(int i=0;i<n-1;i++){
		next[i]=i+1;
	}
	next[n-1]=-1;
}

void kStacks::push(int sn,int item){
	int i=free;
	free=next[free];
	if(top[sn]==-1){
		top[sn]=i;
		next[i]=-1;
		arr[i]=item;
	}
	else{
		next[i]=top[sn];
		top[sn]=i;
		arr[i]=item;
	}
}

int kStacks::pop(int sn){
	if(top[sn]==-1){
		return -1;
	}
	else{
		int i=top[sn];
		top[sn]=next[top[sn]];
		next[i]=free;
		free=i;
		return arr[i];
	}
}

void prac(){

}
int main(){
	kStacks kstack(3,10);
	kstack.push(1,2);
	kstack.push(1,3);
	kstack.push(1,4);
	kstack.push(1,5);
	kstack.push(1,6);
	kstack.push(0,7);
	kstack.push(0,8);
	kstack.push(0,9);
	kstack.push(2,10);

	cout<<kstack.pop(0)<<endl;
	cout<<kstack.pop(1)<<endl;
	cout<<kstack.pop(2)<<endl;

}
*/
