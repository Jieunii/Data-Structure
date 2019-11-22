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

void InsertNode(node* first, int input)//오름차순
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
		printf("정수를 입력하시오: ");
		scanf("%d", &input);
		InsertNode(first, input);
		printf("더 입력하시겠습니까? ");
		scanf("%s", a);
	}
	printf("오름차순 리스트: ");
	InOrderPrintList(first);
	printf("역순 리스트:");
	InReverseOrderlist(first);
	InOrderPrintList(first);
	InReverseOrderlist(first);
}