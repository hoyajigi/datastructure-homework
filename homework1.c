/*
 * �̸�: ������
 * �й�: 2009003039
 * while, �Լ� �̿��� ������
 *
 * a*b=c ��� ���� ���� �� a�� ����, b�� �����̶�� �θ���.
 * 2,4,6,8 ���� �����̺� 3,5,7,9 ���� �Ʒ����̺�
 */


#include<stdio.h>//����� ���� ���

void gugudan()//������ �Լ� ����
{//start of gugudan()
	int flag=1,i=2,j,k;//������ ����� �ʱ�ȭ
	printf("==============================\n");
	while(flag>=0){//���̺��� �ݺ��Ѵ�.
		j=1;//������ �ʱ�ȭ
		while(j<10){//������ �ݺ��Ѵ�.
			k=1;//������ �ʱ�ȭ
			while(k<5){//������ �ݺ��Ѵ�.
				printf("%d*%d=%2d\t",i*k+flag,j,(i*k+flag)*j);//���
				k++;//��������
			}//end of while()
			j++;//��������
			printf("\n");//����
		}//end of while()
		flag--;//�Ʒ� ���̺�� ����
		printf("==============================\n");
	}//end of while()
}//end of gugudan()

int main(int argc, const char* argv[])//���� �Լ� ����
{//start of main()
	gugudan();//������ �Լ� ����
	return 0;//�����Լ��� ���������� ������
}//end of main()
