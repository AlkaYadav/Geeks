/*


 * BitDiffer.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: user



#include <iostream>
using namespace std;
void printDistinctBits(long long int P,long long int M){
	long long int count=0;
	while(P&&M){
		cout<<"P "<<(P&1)<<endl;
		cout<<"M "<<(M&1)<<endl;
		if((P&1) != (M&1)){
			count++;
		}
		P=P>>1;
		M=M>>1;
	}
	cout<<count<<endl;
}

int main()
{
    long long int T,P,M;
    cin>>T;
    for(int i=0;i<T;i++){
    	cin>>P>>M;
    	printDistinctBits(P,M);
    }
    return 0;
}



#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int (*func[10])(float,char)={NULL};
int main()
{
	union A{
		long int y[5];
		union B{
			double g;
			union C{
				int k;
				union D{
					char ch;
					int x[5];
				}s;
			}a;
		}b;
	}*p;

	p=(union A*)malloc(sizeof(union A));
	p->b.a.k=15;
	printf("%d %d\n",p->b.a.s.x[0],p->b.a.s.ch);
    return 0;

}

void fun(){
    char c;
    if((c=getchar())!='\n')
    fun();
    printf("%c",c);

}
*/
