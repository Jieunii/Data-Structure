#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

int num[5] = { 4, 2, 3, 5, 10 };

typedef struct tree* treepointer;
typedef struct tree {
	char data;
	struct tree *left;
	struct tree *right;
}Tree;

treepointer Createtree(char data)
{
	treepointer Newtree = (treepointer)malloc(sizeof(struct tree));
	Newtree->data = data;
	Newtree->left = NULL;
	Newtree->right = NULL;
	return Newtree;
}

void inorder(treepointer ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		printf("%c", ptr->data);
		inorder(ptr->right);
	}
	return;
}

void preorder(treepointer ptr)
{
	if (ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
	return;
}

int postorder(treepointer ptr)
{
	if (ptr->left&&ptr->left)
	{
		int a = postorder(ptr->left);
		int b = postorder(ptr->right);
		printf("%c", ptr->data);
		if (ptr->data == '/')	return a / b;
		else if (ptr->data == '+')	return a + b;
		else if (ptr->data == '*')	return a * b;
		else if (ptr->data == '-')	return a - b;
	}
	printf("%c", ptr->data);
	return num[ptr->data - 'A'];
}


void level(treepointer ptr, int i)
{
	if (ptr == NULL)
		return;
	if (i == 1)
		printf("%c", ptr->data);
	else if (i > 1)
	{
		level(ptr->left, i - 1);
		level(ptr->right, i - 1);
	}
}

void levelorder(treepointer ptr)
{
	for (int i = 1; i <= 5; i++)
	{
		level(ptr, i);
	}
}

void print(treepointer root)
{
	printf("inorder traversal: \t");
	inorder(root);
	printf("\n");
	printf("preorder traversal: \t");
	preorder(root);
	printf("\n");
	printf("postorder traversal: \t");
	int res = postorder(root);
	printf("\n");
	printf("levelorder traversal: \t");
	levelorder(root);
	printf("\n");
	printf("A=4, B=2, C=3, D=5, E=10 일 때 수식계산결과: %d\n", res);
}

int main()
{
	treepointer root = Createtree('+');
	root->left = Createtree('*');
	root->right = Createtree('E');
	root->left->left = Createtree('*');
	root->left->right = Createtree('D');
	root->left->left->left = Createtree('/');
	root->left->left->right = Createtree('C');
	root->left->left->left->left = Createtree('A');
	root->left->left->left->right = Createtree('B');

	print(root);

	return 0;
}