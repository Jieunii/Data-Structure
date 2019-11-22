#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct poly {
	int coef;
	int expon;
	struct poly* link;
}Poly;

Poly* CreateNode()
{
	Poly* first = (Poly*)malloc(sizeof(Poly));
	first->link = NULL;
	return first;
}

void InsertNode(Poly* first, int coef, int expon)
{
	Poly* curNode = first;
	Poly* newNode = CreateNode();
	if (first->link == NULL) // ��尡 ������� �� ù ���
	{
		first->link = newNode;
		newNode->link = first;
		newNode->coef = coef;
		newNode->expon = expon;
		return;
	}
	while (curNode->link != first)
	{
		if (curNode->link->expon < expon) // ������ ����� ������ ���� ��庸�� Ŭ ��
		{
			newNode->link = curNode->link;
			curNode->link = newNode;
			newNode->coef = coef;
			newNode->expon = expon;
			return;
		}
		else if (curNode->link->expon == expon)
		{
			curNode->link->coef += coef;
			return;
		}
		else
			curNode = curNode->link;
	}
	newNode->link = first;
	curNode->link = newNode;
	newNode->coef = coef;
	newNode->expon = expon;
}

void PrintList(Poly* first)
{
	Poly* curnode = first;
	while (curnode->link != first)
	{
		curnode = curnode->link;
		if (curnode->link == first)
		{
			printf("%d^%d\n", curnode->coef, curnode->expon);
		}
		else
			printf("%d^%d + ", curnode->coef, curnode->expon);
	}
}

int main() {
	Poly* first = CreateNode();
	char total[1024] = "\0";
	char input[256];
	char *delim = "^ +\n";
	printf("���׽�1 �Է�: ");
	fgets(input, sizeof(input), stdin);
	strcat(total, input);
	printf("���׽�2 �Է�: ");
	fgets(input, sizeof(input), stdin);
	strcat(total, input);
	char *token = strtok(total, delim);

	while (token != NULL)
	{
		int a = atoi(token);
		token = strtok(NULL, delim);
		int b = atoi(token);
		token = strtok(NULL, delim);
		InsertNode(first, a, b);
	}
	printf("��= ");
	PrintList(first);

	return 0;
}