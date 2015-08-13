#include"AverageOfStreamOfNumbers.h"

void AverageOfStream::averageOfStream(){
	float a[20];
	int len;
	cout<<"Enter the number of elements to find average";
	cin>>len;
	float prev_avg=0.0,avg;
	for(int i=0;i<len;i++){
		cout<<"Enter the numbers";
		cin>>a[i];
		avg=averageOfStreamHelper(prev_avg,i,a[i]);
		cout<<"New average after adding "<<a[i]<<" is "<<avg;
		prev_avg=avg;
	}
}

float AverageOfStream::averageOfStreamHelper(float prev_avg,int i,float new_ele){
	float new_avg;
	new_avg=(prev_avg*i+new_ele)/(i+1);
	return new_avg;
}
