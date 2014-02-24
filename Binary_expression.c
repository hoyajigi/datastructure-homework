#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Binary_expression.h"

int nGlobalIndex;

// �������� Ʈ�� ����
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



// ���� ���Խ� �ǿ����� ���� -> left, right ���
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
//	������������
	
}

// ���� Ʈ�� ��� ����
int evaluate(TreeNode *root) {
	assert(root != NULL);

	if(root == NULL) { return 0; }
	// ���� ��ȸ�� �ϸ� �ܸ������ ���� ���´�.
	if(root->left == NULL && root->right == NULL) { 
		return root->ch - '0'; 
	} else {
		// ��������� ���� Ʈ�� �Ʒ��ʺ��� ����� �����Ѵ�.
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

// ���� ��ȸ
void inorder(TreeNode *root) {
	if(root->left)
		inorder(root->left);
	printf("%c ",root->ch);
	if(root->right)
		inorder(root->right);
}
// ���� ��ȸ
void preorder(TreeNode *root) {
	printf("%c ",root->ch);
	if(root->left)
		preorder(root->left);
	if(root->right)
		preorder(root->right);
}

// ���� ��ȸ
void postorder(TreeNode *root) {
	if(root->left)
		postorder(root->left);
	if(root->right)
		postorder(root->right);
	printf("%c ",root->ch);
}


//+*32*56


int main(int argc, char *argv[]) {
	TreeNode *expRoot = NULL;	       // ���� Ʈ��
	char pre_exp[MAX_LINE] = {0, };// ����ǥ����� �Է��� ���� ����
	int nCalcResult = 0;	                       // ��� ���

	printf("���� ���� �Է� : ");
	fgets(pre_exp, MAX_LINE - 1, stdin);
	binary_insert_pre_exp(&expRoot, pre_exp); 

	printf("���� Ʈ���� ���� ��ȸ : ");
	preorder(expRoot);
	printf("\n");
	printf("���� Ʈ���� ���� ��ȸ : ");
	inorder(expRoot);
	printf("\n");

	printf("���� Ʈ���� ���� ��ȸ : ");
	postorder(expRoot);
	printf("\n");

	printf("���� Ʈ���� ��� (���� ��ȸ �̿�)\n");
	nCalcResult = evaluate(expRoot);
	printf("��� ��� : %d\n", nCalcResult);

	return EXIT_SUCCESS;
} 
