#include<stdio.h>

int sum_of_square(int n)
{
	if(!n)//n이 0이 되면 종료한다.
		return 0;
	return n*n+sum_of_square(n-1);
}

int main()
{
	int n,result;

	//read n
	printf("Input Number : ");
	scanf("%d",&n);

	if(n>1860){//1861부터 int의 overflow가 난다.
		return 1;
	}
	result=sum_of_square(n);
	printf("sum of squares from 1 to %d = %d\n\n",n,result);
	return 0;
}