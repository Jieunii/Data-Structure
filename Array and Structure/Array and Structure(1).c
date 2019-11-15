#include <stdio.h>
#include <string.h>
#define MAX 100

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

int RANK(int total_num, int arr[][6], int fix)
{
	int rank = 1;
	for (int i = 0; i < total_num; i++)
	{
		if (arr[i][3] > fix)
			rank++;
	}
	return rank;
}

void PRINT(char student[][10], int arr[][6], int total_num)
{

	printf("�̸�	����	����	����	�հ�	���	���\n");
	printf("====================================================\n");
	for (int i = 0; i < total_num; i++)
	{
		printf("%s\t", student[i]);
		for (int j = 0; j < 6; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}


}

void SEARCH(char student[][10], int arr[][6], int total_num)
{
	char search[10];
	while (1)
	{
		printf("�˻��ϰ����ϴ� ����� �̸�: "); // 1
		scanf("%s", search);
		int search_idx = -1; // �˻��ϰ����ϴ� ����� id(�ε���) 
		for (int i = 0; i < total_num; i++) // �˻�
		{

			if (strcmp(search, student[i]) == 0)
			{
				search_idx = i;
				break;
			}
		}
		// search idx�� -1�� �ƴϸ� �ؿ�, -1�̸� �ٽ� ���� 

		if (search_idx != -1)
		{
			printf("�̸�: %s\n", student[search_idx]);
			printf("����: %d��\n����: %d��\n����: %d��\n", arr[search_idx][0], arr[search_idx][1], arr[search_idx][2]);
			printf("�հ�: %d��\n", arr[search_idx][3]);
			printf("���: %d��\n", arr[search_idx][4]);
			printf("���: %d��\n", arr[search_idx][5]);
			break;
		}
		printf("�˻��ϰ��� �ϴ� ����� �����ϴ�.\n\n"); // 2 -> 1
	}
}

void INPUT(char student[][10], int arr[][6], int total_num)
{
	printf("�̸� �Է�:");
	scanf("%s", student[total_num]);
	printf("����, ����, ���� ���� �Է�:");
	for (int j = 0; j < 3; j++)
	{
		scanf("%d", &arr[total_num][j]);
	}
	arr[total_num][3] = SUM(arr[total_num]); // �հ� ����
	arr[total_num][4] = AVG(arr[total_num][3]);
}

int main(void)
{
	int total_num = 0; // �� �л� ��
	char student[MAX][10]; // �̸�
	int arr[MAX][6]; // data(����, ����, ...)
	char a;

	do {
		INPUT(student, arr, total_num);
		total_num++;
		printf("�Է��� �����Ͻðڽ��ϱ�\n");
		scanf(" %c", &a);
	} while (a == 'n');

	for (int i = 0; i < total_num; i++)
	{
		arr[i][5] = RANK(total_num, arr, arr[i][3]);
	}

	PRINT(student, arr, total_num);
	SEARCH(student, arr, total_num);



}