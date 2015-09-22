/*

 * RabinKarp.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: user

#include<cstring>
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

 * q-prime number


void rabinKarp(char* str,char* pat,int q){
	int n=strlen(str);
	cout<<"Value of n "<<n<<endl;
	int m=strlen(pat);
	cout<<"Value of m "<<m<<endl;

	vector<int> indexes;
	int hash_pat=0;
	int hash_str=0;
	int p=1;
	for(int i=0;i<m;i++){
		hash_pat=(hash_pat+p*pat[i])%q;
		hash_str=(hash_str+p*str[i])%q;
		p*=10;
	}
	p=p/10;
cout<<"HAsh str is "<<hash_str<<endl;
cout<<"HAsh pat is "<<p<<endl;

	for(int i=0;i<=n-m;i++){
		if(hash_pat==hash_str){
			cout<<"YES"<<endl;
			indexes.push_back(i);
		}
		hash_str=((hash_str-str[i])*10+str[i+m]*p)%q;
		cout<<"Hash str is "<<hash_str<<endl;
	}

	vector<int>::iterator it;
	for(it=indexes.begin();it!=indexes.end();it++){
		cout<<*it<<endl;
	}
}


int main()
{
    char *txt = "GEEKS FOR GEEKS";
    char *pat = "GEEK";
    int q = 101;  // A prime number
    rabinKarp( txt,pat, q);
    getchar();
    return 0;
}
*/
