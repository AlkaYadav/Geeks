/*

 * mergeOverlappingIntervals.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: user

#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct Interval{
	int start;
	int end;
};
int compare(struct Interval a,struct Interval b){
	return a.start<b.start;
}


void mergeOverlapping(vector<struct Interval> v){
	sort(v.begin(),v.end(),compare);
	stack<struct Interval> s;
	s.push(v[0]);
	for(int i=1;i<v.size();i++){
		struct Interval top=s.top();
		if(top.end<v[i].start){
					s.push(v[i]);
				}
		else if( top.end<v[i].end){
			top.end=v[i].end;
			s.pop();
			s.push(top);
		}

	}

	cout<<"Overlapped merged are "<<endl;
	while(!s.empty()){
		cout<<s.top().start<<" "<<s.top().end<<endl;
		s.pop();
	}
}

int main(){

	Interval intvls[] = { {1,3},{7,9},{4,6},{10,13} };
	    vector<Interval> intervals(intvls, intvls+4);

    // Merge overlapping inervals and print result
    mergeOverlapping(intervals);
}
*/
