#include<stdio.h>


//�����˻� �Լ� ã�� �� ���� ���� -1�� �����ϰ� ã����� �� index�� �����Ѵ�.
int bs(int list[],int searchnum,int left,int right)
{
	int middle;
	if(left>right){//��������
		return -1;
	}
	
	printf("Call to binary_search with index [%d, %d]\n",left,right);
	
	middle=(left+right)/2;
	if(list[middle]==searchnum){//Ž������
		return middle;
	}
	else if(list[middle]>searchnum){//���ʿ��� Ž��
		return bs(list,searchnum,left,middle-1);
	}
	else{//�����ʿ��� Ž��
		return bs(list,searchnum,middle+1,right);
	}
}

void print_list(int list[],int n) //�迭�� ������ ������ִ� �Լ�
{
	int i;
	printf("\n");
	printf("   i  : ");
	for(i=0;i<10;i++){
		printf("%2d  ",i);
	}
	printf("\n a[i] : ");
	for(i=0;i<10;i++){
		printf("%2d  ",list[i]);
	}
	printf("\n\n");
}

int main()
{
	int searchnum,index;
	int a[10]={1,3,5,7,9,11,13,15,17,19}; //a�� ������ �� ���� �������� ���ĵǾ� �ִٰ� �����Ѵ�.
	print_list(a,10);
	printf("Search number: ");
	scanf("%d",&searchnum);//ã���� �ϴ� ���ڸ� �Է� �޴´�.
	index=bs(a,searchnum,0,9);
	if(index==-1){
		printf("cannot find %d\n\n",searchnum);
	}
	else{
		printf("%d is in a[%d]\n\n",searchnum,index);
	}
}