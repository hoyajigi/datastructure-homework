#include<stdio.h>

int sum_of_square(int n)
{
	if(!n)//n�� 0�� �Ǹ� �����Ѵ�.
		return 0;
	return n*n+sum_of_square(n-1);
}

int main()
{
	int n,result;

	//read n
	printf("Input Number : ");
	scanf("%d",&n);

	if(n>1860){//1861���� int�� overflow�� ����.
		return 1;
	}
	result=sum_of_square(n);
	printf("sum of squares from 1 to %d = %d\n\n",n,result);
	return 0;
}