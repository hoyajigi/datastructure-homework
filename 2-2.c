#include<stdio.h>

int main()
{
	int i,max_index;
	int score[10]={55,20,33,85,13,22,45,98,67,77};
	
	//�� ���� �� ���
	for(i=0;i<10;i++){
		printf("%d ��: %d ��\n",i,score[i]);
	}
	//���� ū ������ ��ġ ���ϱ�
	max_index=0;
	for(i=1;i<10;i++){
		if(score[i]>score[max_index]){
			max_index=i;
		}
	}
	printf("\n1���� %d ��, ������ %d �Դϴ�. \n\n",max_index,score[max_index]);
	return 0;
}