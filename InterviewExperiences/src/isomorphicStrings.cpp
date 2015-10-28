/*
 * isomorphicStrings.cpp
 *
 *  Created on: Sep 26, 2015
 *      Author: user
 */

#include <iostream>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

int compare(const pair<char,int>& p1,const pair<char,int>& p2){
	return p1.second<p2.second;
}
void printMap(map<char,int> ma){
	map<char,int>::iterator it1;
	for(it1=ma.begin();it1!=ma.end();it1++){
		cout<<it1->first<<" "<<it1->second<<endl;
	}
}
bool isIsomorphic(string a,string b){
	map<char,int> ma,mb;
	for(int i=0;i<a.length();i++){
		ma[a[i]]++;
	}

	for(int i=0;i<b.length();i++){
		mb[b[i]]++;
	}

	sort(ma.begin(),ma.end(),compare);
	sort(mb.begin(),mb.end(),compare);
	printMap(ma);
	cout<<"Now B"<<endl;
	printMap(mb);
	if(ma.size()!=mb.size()){
		return 0;
	}
	map<char,int>::iterator it1,it2;
	for(it1=ma.begin(),it2=mb.begin();it1!=ma.end() && it2!=mb.end();it1++,it2++){
		if(it1->second!=it2->second){
			return 0;
		}
	}
	return 1;
}

int main(){
	string a="aab";
	string b="xxy";
	cout<<"Hi"<<endl;
	//cout<<isIsomorphic(a,b)<<endl;
}


