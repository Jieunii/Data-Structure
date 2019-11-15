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

	printf("이름	국어	영어	수학	합계	평균	등수\n");
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
		printf("검색하고자하는 사람의 이름: "); // 1
		scanf("%s", search);
		int search_idx = -1; // 검색하고자하는 사람의 id(인덱스) 
		for (int i = 0; i < total_num; i++) // 검색
		{

			if (strcmp(search, data[i].name) == 0)
			{
				search_idx = i;
				break;
			}
		}
		// search idx가 -1이 아니면 밑에, -1이면 다시 위로 

		if (search_idx != -1)
		{
			printf("이름: %s\n", data[search_idx].name);
			printf("국어: %d점\n영어: %d점\n수학: %d점\n", data[search_idx].arr[0], data[search_idx].arr[1], data[search_idx].arr[2]);
			printf("합계: %d점\n", data[search_idx].arr[3]);
			printf("평균: %d점\n", data[search_idx].arr[4]);
			printf("등수: %d등\n", data[search_idx].arr[5]);
			break;
		}
		printf("검색하고자 하는 사람이 없습니다.\n\n"); // 2 -> 1
	}
}

void INPUT(Student data[MAX], int total_num)
{
	printf("이름 입력:");
	scanf("%s", data[total_num].name);
	printf("국어, 영어, 수학 성적 입력:");
	for (int j = 0; j < 3; j++)
	{
		scanf("%d", &data[total_num].arr[j]);
	}
	data[total_num].arr[3] = SUM(data[total_num].arr);
	data[total_num].arr[4] = AVG(data[total_num].arr[3]);
}

int main(void)
{
	int total_num = 0; // 총 학생 수
	Student data[MAX];
	char a;
	do {
		INPUT(data, total_num);
		total_num++;
		printf("입력을 종료하시겠습니까\n");
		scanf(" %c", &a);
	} while (a == 'n');

	for (int i = 0; i < total_num; i++)
	{
		data[i].arr[5] = RANK(total_num, data, data[i].arr[3]);
	}

	PRINT(data, total_num);
	SEARCH(data, total_num);
}