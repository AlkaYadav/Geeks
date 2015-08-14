/*

 * BoxStacking.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: user


#include<algorithm>
#include<iostream>
using namespace std;
struct dimensions{
	int l;
	int b;
	int h;
};

void printStruct(struct dimensions dim[],int n){
	for(int i=0;i<n;i++){
		cout<<dim[i].l<<"X"<<dim[i].b<<"X"<<dim[i].h<<endl;
	}
}
int compare(const void * a,const void * b1){
	return -(((dimensions *)a)->l) * (((dimensions *)a)->b)-
			(((dimensions *)b1)->l) * (((dimensions *)b1)->b);
}
void boxStacking(struct dimensions a[],int n){
	struct dimensions box[3*n];
	int index=0;
	int i=0;
	//Create all possible combinations
	for(int index=0;index<3*n;index++){

		box[index]=a[i];
		i++;
		index++;
		//Interchange b with l

		box[index].l=box[index-1].b;
		box[index].b=box[index-1].l;
		box[index].h=box[index-1].h;

		index++;
		//Interchange h with l
		box[index].l=box[index-2].h;
		box[index].h=box[index-2].l;
		box[index].b=box[index-2].b;
	}

	qsort(box,3*n,sizeof(box[0]),compare);

	printStruct(box,3*n);

	int boxstackinglis[3*n];
	for(int i=0;i<3*n;i++){
		boxstackinglis[i]=1;
	}
	//Find LIS
	for(int i=1;i<3*n;i++){
		for(int j=0;j<i;j++){
			if(box[i].l<box[j].l && box[i].b<box[j].b && boxstackinglis[i]>boxstackinglis[j]+box[i].h){
				boxstackinglis[i]=boxstackinglis[j]+box[i].h;
			}
		}
	}

	//Find max height obtained
	int max_lis=INT_MIN;
	for(int i=0;i<3*n;i++){
		if(boxstackinglis[i]>max_lis){
			max_lis=boxstackinglis[i];
		}
	}

	cout<<"Maximum height is "<<max_lis<<endl;
}

int main(){
	dimensions arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	int n = sizeof(arr)/sizeof(arr[0]);
	boxStacking(arr,n);
}
*/
