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

	printf("이름	국어	영어	수학	합계	평균	등수\n");
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
		printf("검색하고자하는 사람의 이름: "); // 1
		scanf("%s", search);
		int search_idx = -1; // 검색하고자하는 사람의 id(인덱스) 
		for (int i = 0; i < total_num; i++) // 검색
		{

			if (strcmp(search, student[i]) == 0)
			{
				search_idx = i;
				break;
			}
		}
		// search idx가 -1이 아니면 밑에, -1이면 다시 위로 

		if (search_idx != -1)
		{
			printf("이름: %s\n", student[search_idx]);
			printf("국어: %d점\n영어: %d점\n수학: %d점\n", arr[search_idx][0], arr[search_idx][1], arr[search_idx][2]);
			printf("합계: %d점\n", arr[search_idx][3]);
			printf("평균: %d점\n", arr[search_idx][4]);
			printf("등수: %d등\n", arr[search_idx][5]);
			break;
		}
		printf("검색하고자 하는 사람이 없습니다.\n\n"); // 2 -> 1
	}
}

void INPUT(char student[][10], int arr[][6], int total_num)
{
	printf("이름 입력:");
	scanf("%s", student[total_num]);
	printf("국어, 영어, 수학 성적 입력:");
	for (int j = 0; j < 3; j++)
	{
		scanf("%d", &arr[total_num][j]);
	}
	arr[total_num][3] = SUM(arr[total_num]); // 합계 저장
	arr[total_num][4] = AVG(arr[total_num][3]);
}

int main(void)
{
	int total_num = 0; // 총 학생 수
	char student[MAX][10]; // 이름
	int arr[MAX][6]; // data(수학, 영어, ...)
	char a;

	do{
		INPUT(student, arr, total_num);
		total_num++;
		printf("입력을 종료하시겠습니까\n");
		scanf(" %c", &a);
	} while (a == 'n');

	for (int i = 0; i < total_num; i++)
	{
		arr[i][5] = RANK(total_num, arr, arr[i][3]);
	}

	PRINT(student, arr, total_num);
	SEARCH(student, arr, total_num);



}