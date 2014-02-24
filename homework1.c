/*
 * 이름: 조현석
 * 학번: 2009003039
 * while, 함수 이용한 구구단
 *
 * a*b=c 라는 식이 있을 때 a를 전항, b를 후항이라고 부르자.
 * 2,4,6,8 단을 윗테이블 3,5,7,9 단을 아랫테이블
 */


#include<stdio.h>//출력을 위한 헤더

void gugudan()//구구단 함수 선언
{//start of gugudan()
	int flag=1,i=2,j,k;//변수의 선언과 초기화
	printf("==============================\n");
	while(flag>=0){//테이블을 반복한다.
		j=1;//후항의 초기화
		while(j<10){//후항을 반복한다.
			k=1;//전항의 초기화
			while(k<5){//전항을 반복한다.
				printf("%d*%d=%2d\t",i*k+flag,j,(i*k+flag)*j);//출력
				k++;//전항증가
			}//end of while()
			j++;//후항증가
			printf("\n");//개행
		}//end of while()
		flag--;//아랫 테이블로 변경
		printf("==============================\n");
	}//end of while()
}//end of gugudan()

int main(int argc, const char* argv[])//메인 함수 선언
{//start of main()
	gugudan();//구구단 함수 선언
	return 0;//메인함수를 성공적으로 종료함
}//end of main()
