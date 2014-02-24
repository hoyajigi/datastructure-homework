#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "bst.h"


// 트리에 (key, data) 자료 삽입
void bst_insert(int key, char data)
{
	tree_pointer new_node,parent_node;
	if(root==NULL){
		root=(tree_node *)malloc(sizeof(tree_node));
		root->data=data;
		root->key=key;
		root->left=NULL;
		root->right=NULL;
		return;
	}
	parent_node=root;
	new_node=(tree_node *)malloc(sizeof(tree_node));
	while(1){
		if(parent_node->key>=key){
			if(parent_node->left!=NULL){
				parent_node=parent_node->left;
			}
			else{
				parent_node->left=new_node;
				break;
			}
		}
		else{
			if(parent_node->right!=NULL){
				parent_node=parent_node->right;
			}
			else{
				parent_node->right=new_node;
				break;
			}
		}
	}
	new_node->data=data;
	new_node->key=key;
	new_node->left=NULL;
	new_node->right=NULL;
}
// 트리에서 키값이 key인 자료를 검색, data를 반환
char bst_search(int key)
{
	tree_pointer tree;
	tree=root;
	while(tree){
		if (key == tree->key) return tree->data;
		if (key < tree->key)
			tree =tree->left;
		else
			tree =tree->right;

	}
	return NULL;
}
// 트리의 자료들을 inorder로 출력 
void bst_show_inorder(tree_pointer ptr)
{
	if(!ptr)
		return;
	bst_show_inorder(ptr->left);
	printf(" %d %c\n",ptr->key,ptr->data);
	bst_show_inorder(ptr->right);
}


void main () 
{
	char	c, grade;
	int	id;

	printf("************* Command ************\n");
	printf("I: Insert data, S: Search data    \n");
	printf("P: Print inorder, Q: Quit         \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);

		switch (c) {
			case 'I' : 
				printf("\n id and grade: ");
				scanf("%d %c", &id, &grade);
				bst_insert(id, grade);
				break;
			case 'S' : 
				printf("\n id: ");
				scanf("%d", &id);
				grade = bst_search(id);
				if (grade) printf (" Grade of %d: %c \n", id, grade);
				else printf(" No such id ! \n");
				break;
			case 'P' : 
				printf ("\n");
				bst_show_inorder(root); 
				break;
			case 'Q' : 
				printf("\n");
				exit(1);
			default  : break;
		}
	}
}
/*
i107 D
i103 B
i109 F
i105 C
i101 A
ps105

*/