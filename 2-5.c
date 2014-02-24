#include<stdio.h>


//이진검색 함수 찾을 수 없을 때는 -1을 리턴하고 찾을경우 그 index를 리턴한다.
int bs(int list[],int searchnum,int left,int right)
{
	int middle;
	if(left>right){//종료조건
		return -1;
	}
	
	printf("Call to binary_search with index [%d, %d]\n",left,right);
	
	middle=(left+right)/2;
	if(list[middle]==searchnum){//탐색성공
		return middle;
	}
	else if(list[middle]>searchnum){//왼쪽에서 탐색
		return bs(list,searchnum,left,middle-1);
	}
	else{//오른쪽에서 탐색
		return bs(list,searchnum,middle+1,right);
	}
}

void print_list(int list[],int n) //배열의 값들을 출력해주는 함수
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
	int a[10]={1,3,5,7,9,11,13,15,17,19}; //a는 완전히 비 내림 차순으로 정렬되어 있다고 가정한다.
	print_list(a,10);
	printf("Search number: ");
	scanf("%d",&searchnum);//찾고자 하는 숫자를 입력 받는다.
	index=bs(a,searchnum,0,9);
	if(index==-1){
		printf("cannot find %d\n\n",searchnum);
	}
	else{
		printf("%d is in a[%d]\n\n",searchnum,index);
	}
}