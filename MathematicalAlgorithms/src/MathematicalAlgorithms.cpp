//============================================================================
// Name        : MathematicalAlgorithms.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<limits.h>
#include<cstring>
#include<math.h>
#include<limits.h>
#include<algorithm>
#include "Fibonacci.h"
#include "AverageOfStreamOfNumbers.h"
using namespace std;

bool isMultipleOfThree(int num){
	int oddcount=0;
	int evencount=0;
	if(num<0){
		num=num*-1;
	}
	while(num){
	if(num&1){
		oddcount++;
	}
	num=num>>1;
	if(num&1){
		evencount++;
	}
	num=num>>1;
}
return ((oddcount-evencount)%3==0);
}
 int multiplyWithSeven(int num){
 	int orig=num;
 	num=num<<3;
 	return num-orig;
 }

 void SieveOfErtosthenes(int num){
 	int arr[num+1];
 	for(int i=2;i<=num;i++){
 		arr[i]=1;
	 }
	 for(int j=2;j<=num;j++){
	 	if(arr[j]==1){
	 		int k=2;
	 		while(j*k<=num){
	 			arr[j*k]=0;
	 			k++;
			 }
		 }
	 }

	 for(int i=2;i<=num;i++){
	 	if(arr[i]==1){
	 		cout<<i<<"->";
		 }
	 }
 }

 bool isLucky(int num){
 	int k=2;
 	int pos=num;
 	while(k<=pos){
 		if(pos%k==0){
 			return 0;
		 }
		 pos=pos-pos/k;

		 k++;

	 }
	 return 1;
 }

 int extract(char a){
	 int num;
	 if(a>='A' && a<='Z'){
		 num=a-'A';
		 num+=10;
	 }
	 else if(a>='0' && a<='9'){
		 num=a-'0';
	 }
	 return num;
 }

 char convert(int num){
	 char a;
	 if(num>=10){
		 a='A'+num-10;
	 }
	 else{
		 a=num+'0';
	 }
	 return a;
 }

 void addNumbersWithGivenBase(char* num1,char* num2,int base){
 int len1=strlen(num1);
 int len2=strlen(num2);
 int sum,tmp_sum;
 int index=max(len1,len2)+1;
 int LEN=index;
 char result[LEN];
 int carry=0;

 while(len1 && len2){
	 int number1=extract(num1[len1-1]);
	 int number2=extract(num2[len2-1]);
	 cout<<"Number extracted are"<<number1<<" =="<<number2<<endl;
	 sum=number1+number2+carry;
	 cout<<"calculating sum::"<<sum<<endl;
     if(sum>=base){
    	tmp_sum=sum-base;
    	carry=1;
     }
     else{
    	 tmp_sum=sum;
    	 carry=0;
     }
     result[index-1]=convert(tmp_sum);
     cout<<"Result is ::"<<result[index-1]<<endl;
     index--;
	 len1--;
	 len2--;
 }

if(len1){
	while(len1){
		int number1=extract(num1[len1-1]);
		sum=number1+carry;
		if(sum>=base){
		    	tmp_sum=sum-base;
		    	carry=1;
		     }
		     else{
		    	 tmp_sum=sum;
		    	 carry=0;
		    }
		result[index-1]=convert(tmp_sum);
			     cout<<"Result 2 is ::"<<result[index-1]<<endl;
			     index--;
				 len1--;
	}

}
else if(len2){
	while(len2){
		int number2=extract(num2[len2-1]);
		sum=number2+carry;
		if(sum>=base){
		    	tmp_sum=sum-base;
		    	carry=1;
		     }
		     else{
		    	 tmp_sum=sum;
		    	 carry=0;
		    }
		result[index-1]=convert(tmp_sum);
			     cout<<"Result 2 is ::"<<result[index-1]<<endl;
			     index--;
				 len2--;
	}

}
if(carry){
	result[index-1]='1';
	index--;
}

 for(int i=index;i<LEN;i++){
	 cout<<result[i]<<" ";
 }
 cout<<endl;
 }

 void addNumbersWithGivenBaseNew(char* num1,char* num2,int base){
 int len1=strlen(num1);
 int len2=strlen(num2);
 int sum,tmp_sum;
 int index=max(len1,len2)+1;
 int LEN=index;
 char result[LEN];
 int carry=0;
 int number1,number2;
 while(len1 || len2){

	 if(len1){
	 number1=extract(num1[len1-1]);
	 }
	 else{
		 number1=0;
	 }
	 if(len2){
	 number2=extract(num2[len2-1]);
	 }
	 else{
		 number2=0;
	 }
	 cout<<"Number extracted are"<<number1<<" =="<<number2<<endl;
	 sum=number1+number2+carry;
	 cout<<"calculating sum::"<<sum<<endl;
     if(sum>=base){
    	tmp_sum=sum-base;
    	carry=1;
     }
     else{
    	 tmp_sum=sum;
    	 carry=0;
     }
     result[index-1]=convert(tmp_sum);
     cout<<"Result is ::"<<result[index-1]<<endl;
     index--;
     if(len1){
	 len1--;
     }
     if(len2){
	 len2--;
     }
 }

if(carry){
	result[index-1]='1';
	index--;
}

 for(int i=index;i<LEN;i++){
	 cout<<result[i]<<" ";
 }
 cout<<endl;
 }

/********************************************************
 * Start Magic Square
 ********************************************************/
 /*
  * In any magic square, the first number i.e. 1 is stored at position (n/2, n-1). Let this position be (i,j). The next number is stored at position (i-1, j+1) where we can consider each row & column as circular array i.e. they wrap around.

Three conditions hold:

1. The position of next number is calculated by decrementing row number of previous number by 1, and incrementing the column number of previous number by 1. At any time, if the calculated row position becomes -1, it will wrap around to n-1. Similarly, if the calculated column position becomes n, it will wrap around to 0.

2. If the magic square already contains a number at the calculated position, calculated column position will be decremented by 2, and calculated row position will be incremented by 1.

3. If the calculated row position is -1 & calculated column position is n, the new position would be: (0, n-2).
  */

 void magicSquare(int n){
	 int magic[n][n];
	 int i,j;
	 for(int x=0;x<n;x++){
		 for(int y=0;y<n;y++){
			 magic[x][y]=0;
		 }
	 }
	 i=n/2;
	 j=n-1;
	 for(int num=1;num<=n*n;){
		 if(i==-1&&j==n){
			 i=0;
			 j=n-2;
		 }
		 else{
			 if(i==-1){
				 i=n-1;
			 }
			 else if(j==n){
				 j=0;
			 }
		 }
		 /*Rule 2*/
		 if(magic[i][j]){
			 j=j-2;
			 i++;
			 continue;
		 }
		 magic[i][j]=num++;
		 i--;
		 j++;
	 }

	 /*Print magic square*/
	 for(int x=0;x<n;x++){
	 		 for(int y=0;y<n;y++){
	 			 cout<<magic[x][y]<<" ";
	 		 }
	 		 cout<<endl;
	 	 }
 }
 /********************************************************
  * End Magic Square
  ********************************************************/

 /********************************************************
  * Start Print All combinations that compose a given number
  ********************************************************/
#define MAX_POINT 3
#define MAX_SIZE 10
 void printArray(int a[],int len);
 void printAllCombinationsComposingNumber(int n,int i){
	 static int a[MAX_SIZE];
	 if(n==0){
		 printArray(a,i);
	 }
	 else if(n>0){
		 for(int k=1;k<=MAX_POINT;k++){
			 a[i]=k;
			 printAllCombinationsComposingNumber(n-k,i+1);
		 }
	 }
 }

 void printArray(int a[],int len){
	 cout<<"Combinations"<<endl;
	 for(int i=0;i<len;i++){
		 cout<<a[i]<<" ";
	 }
	 cout<<endl;
 }

 void multiplyTwoPolynomials(int a[],int b[],int m,int n){
	 int c[m*n];
	 for(int k=0;k<m+n;k++){
		 c[k]=0;
	 }
	 for(int i=0;i<m;i++){
		 for(int j=0;j<n;j++){
			 c[i+j]+=a[i]*b[j];
		 }
	 }
	 cout<<"Multiplication is:"<<endl;
	 for(int k=0;k<m+n;k++){
		 if(c[k])
	 		 cout<<c[k]<<" ";
	 	 }
 }
/****************************************************
 * Ugly Numbers
 ******************************************************/
 bool isUglyNumber(int n){
//Allowed divisors are 2,3,5
	 while(n%2==0){
		 n=n/2;
	 }
	 while(n%3==0){
		 n=n/3;
	 }
	 while(n%5==0){
		 n=n/5;
	 }
	 return n==1;
 }

 void UglyNumber(int num){
	 int count=1;
	 int i=1;
	 while(count<num){
		 if(isUglyNumber(i)){
			 count++;
			 cout<<i<<" ";
		 }
		 i++;
	 }
 }
/************************************************************
 * End Ugly Numbers
 ************************************************************/

 /***********************************************************
 *Start Count Numbers that dont contain 3
  ***********************************************************/
int countNumberOfDigits(int num){
	int count=0;
	while(num){
		count++;
		num=num/10;
	}
	return count;
 }
int countThatDontContain3Helper(int num);
int countThatDontContain3(int num){
	if(num){
		return countThatDontContain3Helper(num)-1;
	}
	return 0;
}
int countThatDontContain3Helper(int num){
	if(num>=0 && num<=9){
		if (num<3)
			return num;
		else
				return num-1;
	}
	int count=0;
	int d=countNumberOfDigits(num);
	int intervals=num/pow(10,d-1);
	int m=pow(9,d-1);
	int z=(int)pow(10,d-1);
	int remaining=num%z;

	if(intervals>3){
		count+= (intervals-1)*m+countThatDontContain3(remaining);
	}
	else if(intervals<3){
		count+= intervals*m+countThatDontContain3(remaining);
	}
	else if(intervals==3){
		count+= intervals*m;
	}
	return count;
}

void printUglySequence(int num){
	int ugly[num];
	int i2=0,i3=0,i5=0;
	int index=0,next_ugly_2,next_ugly_3,next_ugly_5,next_ugly;
	ugly[0]=1;
	while(index<num){
		next_ugly_2=ugly[i2]*2;
		next_ugly_3=ugly[i3]*3;
		next_ugly_5=ugly[i5]*5;
		next_ugly=min(min(next_ugly_2,next_ugly_3),next_ugly_5);
		ugly[++index]=next_ugly;
		cout<<next_ugly<<" ";
		if(next_ugly==next_ugly_2){
			i2++;
		}
		if(next_ugly==next_ugly_3){
					i3++;
		}
		if(next_ugly==next_ugly_5){
					i5++;
		}
	}
}

/**************************************************************************
 * Start Find next greater number with same set of digits
 ************************************************************************/
int findNextGreater(char number[],unsigned int index){
	int mindiff=INT_MAX;
	int minIndx;
	for(int i=index+1;i<strlen(number);i++){
		int diff=abs((int)number[i]-(int)number[index]);
		if(diff<mindiff){
			mindiff=diff;
			minIndx=i;
		}
	}
	return minIndx;
}
void swap(char number[],int greaterIndx,int index){
	char tmp;
	tmp=number[greaterIndx];
	number[greaterIndx]=number[index];
	number[index]=tmp;
}
char* findNextGreaterNumberWithSameDigits(char number[]){
	int len=strlen(number);

	int index=-1;

	for(int i=len-1;i>0;i--){

		if((number[i-1]-'0')<(number[i]-'0')){
			cout<<"Checking "<<number[i-1] <<"and "<<number[i]<<endl;
			index=i-1;
			cout<<"Index is "<<index<<endl;
			break;
		}
	}
	cout<<"Index found is"<<number[index];

	if(index!=-1){
	int greaterIndx=findNextGreater(number,index);
	cout<<"Next greater index"<<greaterIndx<<endl;

	swap(number,greaterIndx,index);
	cout<<"Number is"<<number<<endl;
	sort(number+index+1,number+len);

	}

	return number;
}

void printStair(int h){
	for(int i=1;i<=h;i++){

		for(int j=h-i;j>0;j--){
			cout<<" ";
		}

		for(int k=i;k>0;k--){
			cout<<"#";
		}


		cout<<endl;
	}

}
int main(){
	/*int num;
	cout<<"Enter number";
	cin>>num;
	cout<<INT_MAX;
	cout<<"ismutiple of 3"<<isMultipleOfThree(num);
	cout<<"multiply with seven"<<multiplyWithSeven(-4294967296);
	SieveOfErtosthenes(98);
	cout<<"isLucky"<<isLucky(21);
	addNumbersWithGivenBase("123","A2CBD",14);
	addNumbersWithGivenBaseNew("123","143",10);

	Fibonacci fib;

	AverageOfStream avgstream;
	cout<<"Using fib recursion:"<<fib.fibonacci_recursion(9)<<endl;
	cout<<"Using fib dynamic programming:"<<fib.fibonacci_dynamicProgramming(9)<<endl;
	cout<<"Using fib optimized space:"<<fib.fibonacci_optimized(9)<<endl;
	cout<<"Using fib power of matrix:"<<fib.fibonacci_powerOfMatrix(9)<<endl;
	cout<<"Using fib power of matrix in optimized way:"<<fib.fibonacci_powerOfMatrixOptimized(9)<<endl;
	cout<<"Calculating average of stream of numbers "<<endl;

	avgstream.averageOfStream();
	magicSquare(7);
	printAllCombinationsComposingNumber(4,0);
	int a[]={5, 0, 10, 6};
	int b[]={1, 2, 4};
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(b)/sizeof(b[0]);
	multiplyTwoPolynomials(a,b,m,n);

	cout<<"isUglyNumber:"<<isUglyNumber(300)<<endl;
	cout<<"Ugly numbers"<<endl;
	UglyNumber(15);

	cout<<"Count Numbers that dont contain 3::"<<countThatDontContain3(999)<<endl;
	cout<<"Print ugly number sequence"<<endl;
	printUglySequence(11);

	char a[]="534976";
	cout<<"Find next greater number"<<findNextGreaterNumberWithSameDigits(a)<<endl;
	*/
	printStair(5);
	return 0;
}
