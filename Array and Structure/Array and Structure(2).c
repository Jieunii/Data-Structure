#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
	char name[10];
	int arr[6];
}Student;

int SUM(int data[3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += data[i];
	}
	return sum;
}

int AVG(int sum)
{
	return sum / 3;
}

int RANK(int total_num, Student data[MAX], int fix)
{
	int rank = 1;
	for (int i = 0; i < total_num; i++)
	{
		if (data[i].arr[3] > fix)
			rank++;
	}
	return rank;
}

void PRINT(Student data[MAX], int total_num)
{

	printf("�̸�	����	����	����	�հ�	���	���\n");
	printf("====================================================\n");
	for (int i = 0; i < total_num; i++)
	{
		printf("%s\t", data[i].name);
		for (int j = 0; j < 6; j++)
		{
			printf("%d\t", data[i].arr[j]);
		}
		printf("\n");
	}
}

void SEARCH(Student data[MAX], int total_num)
{
	char search[10];
	while (1)
	{
		printf("�˻��ϰ����ϴ� ����� �̸�: "); // 1
		scanf("%s", search);
		int search_idx = -1; // �˻��ϰ����ϴ� ����� id(�ε���) 
		for (int i = 0; i < total_num; i++) // �˻�
		{

			if (strcmp(search, data[i].name) == 0)
			{
				search_idx = i;
				break;
			}
		}
		// search idx�� -1�� �ƴϸ� �ؿ�, -1�̸� �ٽ� ���� 

		if (search_idx != -1)
		{
			printf("�̸�: %s\n", data[search_idx].name);
			printf("����: %d��\n����: %d��\n����: %d��\n", data[search_idx].arr[0], data[search_idx].arr[1], data[search_idx].arr[2]);
			printf("�հ�: %d��\n", data[search_idx].arr[3]);
			printf("���: %d��\n", data[search_idx].arr[4]);
			printf("���: %d��\n", data[search_idx].arr[5]);
			break;
		}
		printf("�˻��ϰ��� �ϴ� ����� �����ϴ�.\n\n"); // 2 -> 1
	}
}

void INPUT(Student data[MAX], int total_num)
{
	printf("�̸� �Է�:");
	scanf("%s", data[total_num].name);
	printf("����, ����, ���� ���� �Է�:");
	for (int j = 0; j < 3; j++)
	{
		scanf("%d", &data[total_num].arr[j]);
	}
	data[total_num].arr[3] = SUM(data[total_num].arr);
	data[total_num].arr[4] = AVG(data[total_num].arr[3]);
}

int main(void)
{
	int total_num = 0; // �� �л� ��
	Student data[MAX];
	char a;
	do {
		INPUT(data, total_num);
		total_num++;
		printf("�Է��� �����Ͻðڽ��ϱ�\n");
		scanf(" %c", &a);
	} while (a == 'n');

	for (int i = 0; i < total_num; i++)
	{
		data[i].arr[5] = RANK(total_num, data, data[i].arr[3]);
	}

	PRINT(data, total_num);
	SEARCH(data, total_num);
}