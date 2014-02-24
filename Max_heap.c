#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "max_heap.h"

boolean error_flag;

// 히프에 item(key, data) 삽입
void insert_max_heap(Element item)
{
	int i;
	i= ++heap_size;
	while ((i != 1) && (item.key > heap[i/2].key)) {
		heap[i] =heap[i/2];
		i =i/2;
	}
	heap[i]=item;

}
// 히프에서 max item (루트) 삭제 및 반환
Element delete_max_heap()
{
	Element max = heap[1];
	Element temp;
	int p = 1;
	int c = 2;
	if(is_heap_empty()){
		error_flag=1;
		printf("\n Heap is empty !!!\n");
		return;
	}
	temp = heap[heap_size--];

	while(c <= heap_size){
		// c = 현재 parent의 큰 자식
		if ((c < heap_size) && (heap[c].key < heap[c+1].key)) c++;
		if (temp.key >= heap[c].key) break;
		heap[p] =heap[c];
		p =  c;
		c =c*2;
	}
	heap[p]=temp;
   	return max;
}
// 히프의 자료들을 차례로 출력 
void max_heap_show(){
	int i;
	for(i=1;i<=heap_size;i++){
		printf(" %d %c\n",heap[i].key,heap[i].data);
	}
}
boolean is_heap_empty()
{
	return (heap_size==0);
}

void main () {

	char	c, data;
	int		key;
	Element item;

	printf("************* Command ************ \n");
	printf("I: Insert data, D: Delete max data \n");
	printf("P: Print heap, Q: Quit             \n");
	printf("********************************** \n");

	while (1) {
		error_flag=0;
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
			case 'I' : 
				printf("\n key and data: ");
				scanf("%d %c", &key, &data);
				item.key = key;
				item.data = data;
				insert_max_heap(item);
				break;
			case 'D' : 
				item = delete_max_heap();
				if(!error_flag)
				printf ("\n Max: key %d, data %c \n", item.key, item.data);
				break;
			case 'P' : 
				printf ("\n");
				max_heap_show(); 
				break;
			case 'Q' : 
				printf("\n");
				exit(1);
			default  : break;
		}
	}
}

/*
i3 B
i1 A
i7 D
i9 E
i5 C
pdddddd
*/