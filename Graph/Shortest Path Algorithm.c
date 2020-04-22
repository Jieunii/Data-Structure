#include <stdio.h>
#define INF 10000
#define TOTAL_VERTEX 7
#define TRUE 1
#define FALSE 0
char cities[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
int weight[TOTAL_VERTEX][TOTAL_VERTEX] = {
	{0, 3, INF, INF, INF, 2, INF},//A
	{3, 0, 17, 16, INF, INF, INF},//B
	{INF, 17, 0, 8, INF, INF, 18},//C
	{INF, 16, 8, 0, 11, INF, 4},//D
	{INF, INF, INF, 11, 0, 2, 10},//E
	{2, INF, INF, INF, 2, 0, INF},//F
	{INF, INF, 18, 4, 10, INF, 0}//G
};
int path[TOTAL_VERTEX][TOTAL_VERTEX];
int check[TOTAL_VERTEX];

void Dijkstra(int s, int f) 
{
	int distance[TOTAL_VERTEX];
	int selected[TOTAL_VERTEX];
	int now;

	for (int i = 0; i < TOTAL_VERTEX; i++)
	{
		for (int j = 0; j < TOTAL_VERTEX; j++)
		{
			path[i][j] = INF;
		}
	}
	for (int i = 0; i < TOTAL_VERTEX; i++)
	{
		distance[i] = weight[s][i];
		selected[i] = FALSE;
		path[i][0] = s;
		check[i] = 1;
	}
	distance[s] = 0;
	selected[s] = TRUE;

	for (int i = 0; i < TOTAL_VERTEX-2; i++)
	{
		int min = INF;
		for (int j = 0; j < TOTAL_VERTEX; j++)
		{
			if (selected[j] == FALSE && distance[j] < min)
			{
				min = distance[j];
				now = j;
			}
		}
		
		selected[now] = TRUE;
		
		for (int j = 0; j < TOTAL_VERTEX; j++)
		{
			if (selected[j] == FALSE) {
				if (distance[now] + weight[now][j] < distance[j])
				{
					if(i == 0) 
					{
						path[j][check[j]] = now;
						check[j]++;
					}
					else
					{
						for (int k = 0; k < check[now] + 1; k++)
						{
							path[j][k] = path[now][k];
							path[j][k + 1] = now;
							check[j]++;
						}
					}
					distance[j] = distance[now] + weight[now][j];
				}
			}
		}
	}
	printf("%c지역에서 %c지역으로 가는 최단 거리 경로는 ", cities[s], cities[f]);
	for (int i = 0; i < TOTAL_VERTEX; i++)
	{
		if (path[f][i] != INF)
		{
			printf("%c ", cities[path[f][i]]);
		}
	}
	printf("%c이며, 이때 최단 거리는 %dkm입니다.\n",cities[f], distance[f]);
}
int main()
{
	char start, finish;
	int s= 0, f = 0;
	printf("출발지역을 입력하세요. ");
	scanf("%c", &start);
	printf("도착지역을 입력하세요. ");
	scanf(" %c", &finish);
	for (int i = 0; i < 7; i++)
	{
		if (cities[i] == start)
			s = i;
		if (cities[i] == finish)
			f = i;
	}
	Dijkstra(s,f);
	return 0;
}