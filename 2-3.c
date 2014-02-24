#include<stdio.h>

//score[n]에서 최대 원소 위치를 구하는 함수
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
	
	//각 원소 값 출력
	for(i=0;i<10;i++){
		printf("%d 번: %d 점\n",i,score[i]);
	}
	//가장 큰 원소의 위치 구하기
	max_index=find_max_index(score,10);
	
	printf("\n1등은 %d 번, 성적은 %d 입니다. \n\n",max_index,score[max_index]);
	return 0;
}