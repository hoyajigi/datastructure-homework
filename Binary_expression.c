#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Binary_expression.h"

int nGlobalIndex;

// 전위수식 트리 삽입
void binary_insert_pre_exp(TreeNode **root, char *exp) {
	TreeNode *n1,*n2,*n3;
	assert(root != NULL);
	assert(exp != NULL);
	nGlobalIndex = 0;
	n1=(TreeNode *)malloc(sizeof(TreeNode));
	n2=(TreeNode *)malloc(sizeof(TreeNode));
	n3=(TreeNode *)malloc(sizeof(TreeNode));
	*root=
		n1;
	n1->ch=exp[0];
	n1->left=n2;
	n1->right=n3;
	nGlobalIndex=1;
	insert_operand(n2,exp);
	nGlobalIndex=4;
	insert_operand(n3,exp);
}



// 수식 삽입시 피연산자 삽입 -> left, right 고려
void insert_operand(TreeNode *root, char *exp) {
	TreeNode *n1,*n2;
	assert(root != NULL);
	assert(exp != NULL);
	n1=(TreeNode *)malloc(sizeof(TreeNode));
	n2=(TreeNode *)malloc(sizeof(TreeNode));
	n1->left=NULL;
	n1->right=NULL;
	n1->ch=exp[nGlobalIndex+1];
	n2->left=NULL;
	n2->right=NULL;
	n2->ch=exp[nGlobalIndex+2];
	root->left=n1;
	root->right=n2;
	root->ch=exp[nGlobalIndex];
//	………………
	
}

// 수식 트리 계산 연산
int evaluate(TreeNode *root) {
	assert(root != NULL);

	if(root == NULL) { return 0; }
	// 후위 순회를 하며 단말노드의 값을 얻어온다.
	if(root->left == NULL && root->right == NULL) { 
		return root->ch - '0'; 
	} else {
		// 연산순위에 따라 트리 아래쪽부터 계산을 수행한다.
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		switch(root->ch) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}

// 중위 순회
void inorder(TreeNode *root) {
	if(root->left)
		inorder(root->left);
	printf("%c ",root->ch);
	if(root->right)
		inorder(root->right);
}
// 전위 순회
void preorder(TreeNode *root) {
	printf("%c ",root->ch);
	if(root->left)
		preorder(root->left);
	if(root->right)
		preorder(root->right);
}

// 후위 순회
void postorder(TreeNode *root) {
	if(root->left)
		postorder(root->left);
	if(root->right)
		postorder(root->right);
	printf("%c ",root->ch);
}


//+*32*56


int main(int argc, char *argv[]) {
	TreeNode *expRoot = NULL;	       // 수식 트리
	char pre_exp[MAX_LINE] = {0, };// 전위표기수식 입력을 위한 버퍼
	int nCalcResult = 0;	                       // 계산 결과

	printf("전위 수식 입력 : ");
	fgets(pre_exp, MAX_LINE - 1, stdin);
	binary_insert_pre_exp(&expRoot, pre_exp); 

	printf("수식 트리의 전위 순회 : ");
	preorder(expRoot);
	printf("\n");
	printf("수식 트리의 중위 순회 : ");
	inorder(expRoot);
	printf("\n");

	printf("수식 트리의 후위 순회 : ");
	postorder(expRoot);
	printf("\n");

	printf("수식 트리의 계산 (후위 순회 이용)\n");
	nCalcResult = evaluate(expRoot);
	printf("계산 결과 : %d\n", nCalcResult);

	return EXIT_SUCCESS;
} 
