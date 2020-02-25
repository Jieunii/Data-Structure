#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node* treePointer;

typedef struct data{
	char name[20];
	int age;
	char region[20];
	char sex[10];
}Data;

typedef struct node {
	Data data;
	treePointer parent;
	treePointer left;
	treePointer right;
}Node;

void Insert(treePointer *n, Data d)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;
	// ù ���
	if (*n == NULL) {
		newNode->parent = NULL;
		*n = newNode;
	}
	else {
		Node *currentNode = *n;
		while(currentNode->left != NULL || currentNode->right != NULL)
		{
			int cmp = strcmp(currentNode->data.name, d.name);
			if (cmp > 0)
			{
				if (currentNode->left == NULL)
				{
					newNode->parent = currentNode;
					currentNode->left = newNode;
					return;
				}
				currentNode = currentNode->left;
			}
			else if(cmp < 0) 
			{
				if (currentNode->right == NULL)
				{
					newNode->parent = currentNode;
					currentNode->right = newNode;
					return;
				}
				currentNode = currentNode->right;
			}
			else
			{
				return;
			}
		}
		int cmp = strcmp(currentNode->data.name, d.name);
		newNode->parent = currentNode;
		if (cmp > 0) 
		{
			currentNode->left = newNode;
		}
		else if (cmp < 0)
		{
			currentNode->right = newNode;
		}
	}
}
Node* BinarySearch(Node *n, char* name) {
	Node *current = n;
	while (current)
	{
		int cmp = strcmp(current->data.name, name);
		if (cmp == 0) return current;
		if (cmp < 0)
		{
			current = current->right;
		}
		else
		{
			current = current->left;
		}
	}
	return NULL;
}
Node* FindMin(Node *n) {
	while (n->left)
	{
		n = n->left;
	}
	return n;
}
void Delete(Node **n, char *name) {
	Node *deleteNode = BinarySearch(*n, name);
	// ������ ����� �ڽ��� ���� ��
	if (deleteNode == NULL) return;
	Node *parent = deleteNode->parent;
	if (deleteNode->left == NULL && deleteNode->right == NULL) {
		if (parent) // �θ� �ִ� ���
		{
			if (deleteNode == parent->left) { 
				parent->left = NULL;
			}
			else 
			{
				parent->right = NULL;
			}
		} 
		else // root�� ���
		{
			deleteNode = NULL;
		}
		free(deleteNode);
	}
	else if (deleteNode->right && deleteNode->left) // �ڽ��� ��
	{
		Node* min = FindMin(deleteNode->right);
		deleteNode->data = min->data;
		Delete(&(deleteNode->right), min->data.name);
	}
	else // �ڽ��� �ϳ�
	{
		Node *child = (deleteNode->left == NULL) ? deleteNode->right : deleteNode->left;
		if (parent == NULL) // root ����� ��
		{
			child->parent = NULL;
			*n = child; // �ڽ��� root�� �ȴ�.
		}
		else
		{
			child->parent = parent;
			if (deleteNode == parent->left)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
			free(deleteNode);
		}
	}
}
int main()
{
	int total = 0;
	char input[3];
	Node *n = NULL;
	Data d;
	while (input[0] != 'e')
	{
		printf("�Է�(i), Ž��(s), ����(d): ");
		scanf(" %c", &input);

		switch (input[0])
		{
		case 'i':
			if (total >= 100) continue; 
			printf("������ �̸�: ");
			scanf("%s", d.name);
			printf("������ ����: ");
			scanf("%d", &d.age);
			printf("������ ����: ");
			scanf("%s", d.region);
			printf("������ ����: ");
			scanf("%s", d.sex);
			Insert(&n, d);
			total++;
			printf(".\n.\n.\n");
			break;
		case 's':
			printf("������ �̸�: ");
			scanf("%s", d.name);
			printf("\n");
			Node* node = BinarySearch(n, d.name);
			if (node)
			{
				printf("������ %s�� ������ ������ �����ϴ�.\n\n", d.name);
				printf("������ �̸�: %s\n", node->data.name);
				printf("������ ����: %d\n", node->data.age);
				printf("������ ����: %s\n", node->data.region);
				printf("������ ����: %s\n", node->data.sex);
				printf(".\n.\n.\n");
			}
			break;
		case 'd':
			printf("������ �̸�: ");
			scanf("%s", d.name);
			Delete(&n, d.name);
			if (total > 0) total--;
			printf("\n������ %s�� ������ �����Ǿ����ϴ�.\n", d.name);
			printf(".\n.\n.\n");
			break;
		}
	}
	return 0;
}