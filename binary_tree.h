#define	boolean	unsigned char
#define	TRUE	1
#define	FALSE	0

typedef int Element;
// Binary tree node
typedef struct tree_node *tree_pointer;
typedef struct tree_node {
		Element 		data;
		tree_pointer 	left;
		tree_pointer 	right;
} tree_node;

tree_pointer build_simple_tree();    // �տ� ���ǵ� 7���� ��带 ���� binary tree�� ����
int bt_count(tree_pointer ptr); // Ʈ���� ������ ���
int bt_add(tree_pointer ptr); // Ʈ���� ������ ���� ���
int bt_height(tree_pointer ptr); // Ʈ���� ���̸� ���
void bt_show_preorder(tree_pointer ptr); // Ʈ���� ������ preorder�� ���
void free_bt(tree_pointer ptr); // Ʈ���� ��� ��带 �ý��ۿ� ��ȯ(free)
