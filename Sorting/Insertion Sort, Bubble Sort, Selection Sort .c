#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 8

void InsertionSort(int list[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
	for (int i = 0;i < n; i++)
	{
		printf("%d ", list[i]);
	}
}

void BubbleSort(int list[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (list[j + 1] < list[j])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
}

void SelectionSort(int list[], int n)
{
	int least, temp;
	for (int i = 0; i < n - 1; i++)
	{
		least = i;
		for (int j=i + 1; j < n; j++)
		{
			if (list[j] < list[least])
				least = j;
		}
		if (i != least)
		{
			temp = list[i];
			list[i] = list[least];
			list[least] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
}



int main()
{
	int num=0, n=MAX_SIZE;
	int list[] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	printf("정렬할 데이터: 69 10 30 2 16 8 31 22\n");
	while (num!=4)
	{
		printf("Insertion sort algorithm (1), Bubble sort algorithm(2), Selection sort algorithm (3), 종료(4) : ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("Insertion sort을 수행한 결과: ");
			InsertionSort(list, n);
			printf("\n");
			break;
		case 2:
			printf("Bubble Sort를 수행한 결과: ");
			BubbleSort(list, n);
			printf("\n");
			break;
		case 3:
			printf("Selection sort를 수행한 결과: ");
			SelectionSort(list, n);
			printf("\n");
			break;
		case 4:
			printf("종료\n");
			break;
		}
	}

	return 0;
}