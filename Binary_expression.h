#define MAX_LINE 80

//Ʈ�� ����ü
typedef struct TreeNode{
	char ch;
	struct TreeNode *left, *right;
} TreeNode;

void binary_insert_pre_exp(TreeNode **root, char *exp);// �������� Ʈ�� ����
void insert_operand(TreeNode *root, char *exp);	    // ���� ���Խ� �ǿ����� ����
int  evaluate(TreeNode *root);			    // ���� Ʈ�� ��� ����
void inorder(TreeNode *root);			    // ���� ��ȸ
void preorder(TreeNode *root);			    // ���� ��ȸ
void postorder(TreeNode *root);			    // ���� ��ȸ
static int nGlobalIndex;	                                       // ���� ���Խ� ����ϴ� ��������
