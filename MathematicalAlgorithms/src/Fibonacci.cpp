/*
 * Fibonacci.cpp
 *
 *  Created on: Jul 30, 2015
 *      Author: user
 */

#include"Fibonacci.h"

int Fibonacci::fibonacci_recursion(int num){
	if(num==0 || num==1){
		return num;
	}
	return fibonacci_recursion(num-1)+fibonacci_recursion(num-2);
}

int Fibonacci::fibonacci_dynamicProgramming(int num){
	int f[num];
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=num;i++){
		f[i]=f[i-1]+f[i-2];
	}
	return f[num];
}

int Fibonacci::fibonacci_optimized(int num){
	int a=0,b=1,c;
	for(int i=2;i<=num;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int Fibonacci::fibonacci_powerOfMatrix(int num){
   int F[2][2]={{1,1},{1,0}};
   int M[2][2]={{1,1},{1,0}};
   for(int i=2;i<num;i++){
	   multiply(F,M);
   }
   return F[0][0];
}

int Fibonacci::fibonacci_powerOfMatrixOptimized(int num){
   int F[2][2]={{1,1},{1,0}};
   int M[2][2]={{1,0},{0,1}};
  for(int i=num;i>=1;){
	  if(i%2==0){
		  multiply(F,F);
		  i=i/2;
	  }
	  else{
		  multiply(M,F);
		  i--;
	  }
  }
   return M[0][1];
}
void Fibonacci::multiply(int F[2][2],int M[2][2]){
	int a=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	int b=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	int c=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	int d=F[1][0]*M[0][1]+F[1][1]*M[1][1];

	F[0][0]=a;
	F[0][1]=b;
	F[1][0]=c;
	F[1][1]=d;
}
