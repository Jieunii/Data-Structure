#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}node;

void CreateNode(node* first)
{
	first->data = 0;
	first->link = NULL;
}

void InsertNode(node* first, int input)//��������
{
	node * curnode = first;
	node* newnode = (node*)malloc(sizeof(node));

	if (curnode->link == NULL)
	{
		newnode->link = NULL;
		curnode->link = newnode;
		newnode->data = input;
		return;
	}
	while (curnode->link != NULL)
	{
		if (curnode->link->data > input)
		{
			newnode->link = curnode->link;
			newnode->data = input;
			curnode->link = newnode;
			return;
		}
		else
		{
			curnode = curnode->link;
		}
	}
	newnode->link = NULL;
	curnode->link = newnode;
	newnode->data = input;
}

void InReverseOrderlist(node* first)
{
	node* a;
	node* b;
	a = NULL;
	b = NULL;
	node* curnode = first->link;
	if (curnode == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	while (curnode != NULL)
	{
		b = a;
		a = curnode;
		curnode = curnode->link;
		a->link = b;
	}
	first->link = a;
}

void InOrderPrintList(node *first)
{
	node* curnode = first;
	if (curnode->link == NULL)
	{
		printf("list is empty.\n");
	}
	else
	{
		while (curnode->link != NULL)
		{
			curnode = curnode->link;
			if (curnode->link != NULL)
			{
				printf("%d-", curnode->data);
			}
			else
				printf("%d", curnode->data);
		}
		printf("\n");
	}
}

int main(void)
{
	int input;
	char a[2];
	node* first = (node*)malloc(sizeof(node));
	CreateNode(first);

	while (a[0] != 'N')
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &input);
		InsertNode(first, input);
		printf("�� �Է��Ͻðڽ��ϱ�? ");
		scanf("%s", a);
	}
	printf("�������� ����Ʈ: ");
	InOrderPrintList(first);
	printf("���� ����Ʈ:");
	InReverseOrderlist(first);
	InOrderPrintList(first);
	InReverseOrderlist(first);
}