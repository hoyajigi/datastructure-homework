#include<stdio.h>

//score[n]���� �ִ� ���� ��ġ�� ���ϴ� �Լ�
int find_max_index(int score[],int n)
{
	int i,max_index=0;
	for(i=1;i<n;i++){
		if(score[i]>score[max_index]){
			max_index=i;
		}
	}
	return max_index;
}

int main()
{
	int i,max_index;
	int score[10]={55,20,33,85,13,22,45,98,67,77};
	
	//�� ���� �� ���
	for(i=0;i<10;i++){
		printf("%d ��: %d ��\n",i,score[i]);
	}
	//���� ū ������ ��ġ ���ϱ�
	max_index=find_max_index(score,10);
	
	printf("\n1���� %d ��, ������ %d �Դϴ�. \n\n",max_index,score[max_index]);
	return 0;
}