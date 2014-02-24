#define MAX_LINE 80

//트리 구조체
typedef struct TreeNode{
	char ch;
	struct TreeNode *left, *right;
} TreeNode;

void binary_insert_pre_exp(TreeNode **root, char *exp);// 전위수식 트리 삽입
void insert_operand(TreeNode *root, char *exp);	    // 수식 삽입시 피연산자 삽입
int  evaluate(TreeNode *root);			    // 수식 트리 계산 연산
void inorder(TreeNode *root);			    // 중위 순회
void preorder(TreeNode *root);			    // 전위 순회
void postorder(TreeNode *root);			    // 후위 순회
static int nGlobalIndex;	                                       // 수식 삽입시 사용하는 전역변수
