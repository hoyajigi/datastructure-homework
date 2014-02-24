#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include"binary_tree.h"

#define MAX(a,b) ((a)>(b))?((a)):((b))

tree_pointer build_simple_tree(){    // 앞에 정의된 7개의 노드를 갖는 binary tree를 생성
	tree_pointer n1,n2,n3,n4,n5,n6,n7;
	n1=(tree_pointer)malloc(sizeof(tree_node));
	n2=(tree_pointer)malloc(sizeof(tree_node));
	n3=(tree_pointer)malloc(sizeof(tree_node));
	n4=(tree_pointer)malloc(sizeof(tree_node));
	n5=(tree_pointer)malloc(sizeof(tree_node));
	n6=(tree_pointer)malloc(sizeof(tree_node));
	n7=(tree_pointer)malloc(sizeof(tree_node));
	n1->data=10;
	n2->data=20;
	n3->data=30;
	n4->data=40;
	n5->data=50;
	n6->data=60;
	n7->data=70;
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	n3->left=n6;
	n3->right=n7;

	n4->left=NULL;
	n4->right=NULL;
	n5->left=NULL;
	n5->right=NULL;
	n6->left=NULL;
	n6->right=NULL;
	n7->left=NULL;
	n7->right=NULL;

	return n1;
}
int bt_count(tree_pointer ptr){ // 트리의 노드수를 계산
	if(ptr==NULL)
		return 0;
	return bt_count(ptr->left)+bt_count(ptr->right)+1;
}
int bt_add(tree_pointer ptr){ // 트리의 데이터 합을 계산
	if(ptr==NULL)
		return 0;
	return bt_add(ptr->left)+bt_add(ptr->right)+ptr->data;
}
int bt_height(tree_pointer ptr){ // 트리의 높이를 계산
	if(ptr==NULL)
		return 0;
	return MAX(bt_height(ptr->left),bt_height(ptr->right))+1;
}
void bt_show_preorder(tree_pointer ptr){ // 트리의 내용을 preorder로 출력
	if(ptr==NULL)
		return;
	printf(" [%d] ",ptr->data);
	bt_show_preorder(ptr->left);
	bt_show_preorder(ptr->right);
}
void free_bt(tree_pointer ptr){ // 트리의 모든 노드를 시스템에 반환(free)
	if(ptr==NULL)
		return;
	free_bt(ptr->left);
	free_bt(ptr->right);
	printf("\nfree node with item %d ...\n",ptr->data);
	free(ptr);
}


void main () 
{
	char		c;
	int		n;
	tree_pointer	t;

	t = build_simple_tree();

	printf("************* Command ************\n");
	printf("C: Count tree, A: Add tree data    \n");
	printf("H: Height of tree, S: Show preorder \n");
	printf("F: Free tree, Q: Quit              \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c) {
			case 'C' : 
				n = bt_count(t);
				printf ("\n Total number of node = %d \n", n);
				break;
			case 'A' : 
				n = bt_add(t);
				printf ("\n Sum of tree data = %d \n", n);
				break;
			case 'H' : 
				n = bt_height(t);
				printf ("\n Height of tree = %d \n", n);
				break;
			case 'S' : 
				printf ("\n");
				bt_show_preorder(t); 
				printf ("\n");
				break;
			case 'F' : 
				printf ("\n");
				free_bt(t); 
				printf ("\n");
				break;
			case 'Q' : 
				printf("\n");
				exit(1);
			default  : break;
		}
	}
}

