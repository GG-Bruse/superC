/*
���ĸ���:
����һ�ַ����Ե����ݽṹ��������n(n>=0)�����޽�����һ�����в�ι�ϵ�ļ��ϡ�
������Ϊ��������Ϊ����������һ�õ��ҵ����������ϣ�Ҷ���¡�
*/

/*
�ص�:
1.��һ������Ľ�㣬��Ϊ����㣬�����û��ǰ����㡣
2.��������⣬�����㱻�ֳ�M(M>0)�������ཻ�ļ���T1��T2����Tm������ÿһ������Ti(1<=i<=m)����һ�ýṹ�������Ƶĵ�������
ÿ�������ĸ��������ֻ��һ��ǰ����������0���������
3.���ǵݹ鶨���
*/

/*
����:
���Ķ�:���ҽӵ�������(�м���ֱ�Ӻ�̾�Ϊ����)

���Ĳ��:�Ӹ����ý��Ĳ���(��������һ��)

Ҷ�ӡ�Ҷ�ڵ㡢�ն˽��:��Ϊ0�Ľ��(���޺�̵Ľ��)

���ն˽�㡢��֧���:�Ȳ�Ϊ0�Ľ��

˫�׽�㡢�����:��һ����㺬���ӽڵ㣬�������������ӽ��ĸ����(�ӽڵ��ֱ��ǰ��)

���ӽ�㡢�ӽ��:һ����㺬�е������ĸ�����Ϊ�ý����ӽ��(���ý���ֱ�Ӻ��)

�ֵܽ��:ͬһ˫���µ�ͬ����(��������ͬ�����Ľ�㻥��Ϊ�ֵܽ��)

���ֵܽ��:��˫��λ��ͬһ��Ľ��(��ͬһ˫��)

����:�Ӹ����ý��������֧�ϵ����н��(��Ҳ������)

����:�Ըý��Ϊ���������е���һ��㶼Ϊ�ý�������

���Ķ�:һ�����У����� ���Ķ� �е����ֵ

�������(�߶�):ָ���н���е�������

������:�����������������򣬲��ɻ���(��Ϊ��һ)

������:���������ɻ���λ��

ɭ��:��m(m>0)�û����ཻ������ɵļ��ϱ���Ϊɭ��
*/


/*
���ı�ʾ:
1.�������ֵܱ�ʾ��:
�������ߵĺ��ӳ�Ϊ���ӽ�㣬���ӵ��ұߵ��ֵ�Ϊ�Һ���(��һ�ö����ת��Ϊ������)
2.˫�ױ�ʾ��:
��������洢˫�׵��±�
*/



















/*
������:
n(n>=0)���������޼��ϣ���һ��������Լ����û����ཻ���ֱ��Ϊ���������������Ķ��������

����:
1.ÿ���������������������������������ڶȴ���2�Ľ��
2.������������������֮�֣��������Ĵ����ܵߵ�(������)
3.�ڶ������ĵ�i����������2^(i-1)�����(i>0)
4.���Ϊk�Ķ�����������2^k - 1�����(k>0)
5.�����κ�һ�ö�����������Ϊ2�Ľ������m������Ҷ����n��Ϊm+1(��n = m+1)
6.����n�������������������ΪlogN

���������:
1.��������:
һ�����Ϊk����2^k - 1�����Ķ�����(��ÿ��Ľ�������ﵽ���ֵ)
2.��ȫ������:
�����һ���⣬ÿ���ϵĽ�������ﵽ���ֵ�������һ����ֻȱ���ұߵ����ɽ��
(�������Ϊk������n�����Ķ����������ҽ�����ÿһ����������Ϊk�����������б�Ŵ�1��n�Ľ��һһ��Ӧʱ���ö���������Ϊ��ȫ������)
����������һ���������ȫ������
*/


/*
�������Ĵ洢��ʽ:
1.˳��洢:
��������洢��һ������ֻ�ʺϱ�ʾ��ȫ������(������ȫ���������пռ��ϵ��˷�)
������˳��洢����������һ�����飬���߼�����һ��������
2.��ʽ�洢:
����������ʽ�洢�ṹ��ָ����������ʾһ�ö���������������ָʾԪ��֮����߼���ϵ��
ͨ���ķ���:�����ÿ���������������ɣ������������ָ����
��ʽ�ṹ�ַ�Ϊ��������������(�����)
*/

/*
�������ı�����ʽ:
����(��)����:�� ������ ������ NLR
����(��)����:������ �� ������ LNR
����(��)����:������ ������ �� LRN
�������:
��������ĸ�������ڲ���Ϊ1������������Ǵ����ڶ������ĸ���������
���ȷ��ʵ�һ���������㣬Ȼ������ҷ��ʵڶ����ϵĽ�㣬�Դ����ƣ����ϵ��£������ң����������Ľ�㡣
*/




#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
};
void PrevOrder(struct BinaryTreeNode* root)//ǰ��
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(struct BinaryTreeNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
void PostOrder(struct BinaryTreeNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
int main()
{
	//׼�����
	struct BinaryTreeNode* A = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;
	struct BinaryTreeNode* B = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;
	struct BinaryTreeNode* C = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;
	struct BinaryTreeNode* D = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	struct BinaryTreeNode* E = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	//�������ṹ
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	//ǰ�к������
	PrevOrder(A);
	printf("\n");
	InOrder(A); 
	printf("\n");
	PostOrder(A);
	return 0;
}
/*
A B D NULL NULL E NULL NULL C NULL NULL
NULL D NULL B NULL E NULL A NULL C NULL
NULL NULL D NULL NULL E B NULL NULL C A
*/





































