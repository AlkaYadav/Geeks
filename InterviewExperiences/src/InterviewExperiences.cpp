/*
//============================================================================
// Name        : InterviewExperiences.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void checkIfPresent(string permt,string str,vector<int> &indexes){
	for(int i=0;i<str.length();i++){
		int j;
		for( j=0;j<permt.length();j++){
			if(str[i+j]!=permt[j]){
				break;
			}
		}
		if(j==permt.length()){
			indexes.push_back(i);
		}
	}
}
void permute(string permt,int start,int end,vector<int> &indexes,string str){
	if(start==end){
			//cout<<permt<<endl;
			checkIfPresent(permt,str,indexes);
				return;
	}
	for(int i=start;i<=end;i++){
		swap(permt[i],permt[start]);
		permute(permt,start+1,end,indexes,str);
		swap(permt[i],permt[start]);
	}
}
void printStr(string str,int start,int end){
	cout<<"Printing "<<endl;
	for(int i=start;i<start+end;i++){
		cout<<str[i];
	}
	cout<<endl;
}
int main() {
	string str;
	string permt;
	vector<int> indexes;
	cout<<"Enter the first string "<<endl;
	cin>>str;
	cout<<"Enter the string whose permutations need to be searched "<<endl;
	cin>>permt;
	permute(permt,0,permt.length()-1,indexes,str);
	vector<int>::iterator it;
	int count=0;
	for(it=indexes.begin();it!=indexes.end();it++){
		cout<<"Index "<<*it<<endl;
		printStr(str,*it,permt.length());
		count++;
	}
	cout<<"No. of occurence are "<<count<<endl;
	return 0;
}
*/
