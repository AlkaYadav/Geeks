/*

 * CheckForIdenticalBST.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: user


#include<iostream>
#include<limits.h>
using namespace std;
//Check for Identical BSTs without building the trees
bool checkForIdenticalBSTWithoutConstruction(int a[],int b[],int mini,int maxi,int i1,int i2,int n){
	int j1,j2;
	for(j1=i1;j1<n;j1++){
		if(a[j1]>mini && a[j1]<maxi){
			break;
		}
	}

	for(j2=i2;j2<n;j2++){
			if(b[j2]>mini && b[j2]<maxi){
				break;
			}
		}
	if(j1==n && j2==n){
		return true;
	}
	if(((j1==n) ^ (j2==n)) || a[j1]!=b[j2]){
		return false;
	}
	return checkForIdenticalBSTWithoutConstruction(a,b,mini,a[j1],j1+1,j2+1,n)&&
			checkForIdenticalBSTWithoutConstruction(a,b,a[j1],maxi,j1+1,j2+1,n);
}

bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2, int min, int max)
{
   int j, k;

    Search for a value satisfying the constraints of min and max in a[] and
      b[]. If the parent element is a leaf node then there must be some
      elements in a[] and b[] satisfying constraint.
   for (j=i1; j<n; j++)
       if (a[j]>min && a[j]<max)
           break;
   for (k=i2; k<n; k++)
       if (b[k]>min && b[k]<max)
           break;

    If the parent element is leaf in both arrays
   if (j==n && k==n)
       return true;

    Return false if any of the following is true
      a) If the parent element is leaf in one array, but non-leaf in other.
      b) The elements satisfying constraints are not same. We either search
         for left child or right child of the parent element (decinded by min
         and max values). The child found must be same in both arrays
   if (((j==n)^(k==n)) || a[j]!=b[k])
       return false;

    Make the current child as parent and recursively check for left and right
      subtrees of it. Note that we can also pass a[k] in place of a[j] as they
      are both are same
   return   // Right Subtree
          isSameBSTUtil(a, b, n, j+1, k+1, min, a[j]) && isSameBSTUtil(a, b, n, j+1, k+1, a[j], max);    // Left Subtree
}

int main(){
	int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
	   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n=sizeof(a)/sizeof(a[0]);
   cout<<"Check for Identical BSTs without building the trees "<<endl;
   cout<<"REsult is "<<checkForIdenticalBSTWithoutConstruction(a,b,INT_MIN,INT_MAX,n,0,0);
   cout<<isSameBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX);
}


*/
