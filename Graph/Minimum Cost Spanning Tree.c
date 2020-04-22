#include <stdio.h>
#define INF 10000000
#define TOTAL_VERTEX 7
#define TRUE 1
#define FALSE 0
typedef struct graph {
	int vertex1;
	int vertex2;
	int cost;
}Graph;
Graph edges[9] = {
		{ 0, 5, 10 },
		{ 2, 3, 12 },
		{ 1, 6, 14 },
		{ 1, 2, 16 },
		{ 3, 6, 18 },
		{ 3, 4, 22 },
		{ 4, 6, 24 },
		{ 4, 5, 25 },
		{ 0, 1, 28 }
};
int parent[9];
int graph[TOTAL_VERTEX][TOTAL_VERTEX] = {
		{0,28,0,0,0,10,0},
		{28,0,16,0,0,0,14},
		{0,16,0,12,0,0,0},
		{0,0,12,0,22,0,18},
		{0,0,0,22,0,25,24},
		{10,0,0,0,25,0,0},
		{0,14,0,18,24,0,0}
};

int Find(idx) {
	if (idx == parent[idx]) return idx;
	return Find(parent[idx]);
}

void Union(int v1, int v2) {
	int p1 = Find(v1);
	int p2 = Find(v2);
	if (p1 < p2)
	{
		parent[v2] = p1;
		parent[p2] = p1;
	} else 
	{
		parent[v1] = p2;
		parent[p1] = p2;
	}
}

void kruskal() {
	printf("Kruskal’s Algorithm을 이용한 minimum cost spanning tree 생성: {");
	for (int i = 0; i < 9; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < 9;i++) {
		if (Find(edges[i].vertex1)==Find(edges[i].vertex2)) continue;
		Union(edges[i].vertex1, edges[i].vertex2);
		printf(" (%d,%d) ", edges[i].vertex1, edges[i].vertex2);
	}
	printf("}\n");
}

void prim()
{
	int dist[TOTAL_VERTEX];
	int selected[TOTAL_VERTEX];
	int from[TOTAL_VERTEX];
	for (int i = 0; i < TOTAL_VERTEX; i++)
	{
		dist[i] = INF, selected[i] = FALSE, from[i] = i;
	}
	dist[0] = 0;
	from[0] = 0;

	for (int i = 0; i < TOTAL_VERTEX-1; i++)
	{
		int now;
		int min = INF;
		for (int j = 0; j < TOTAL_VERTEX; ++j) 
		{
			if (selected[j] == FALSE && dist[j] < min) 
			{
				min = dist[j]; 
				now = j;
			}
		}
		selected[now] = TRUE;

		for (int j = 0; j < TOTAL_VERTEX; ++j) 
		{
			if (graph[now][j] && selected[j] == FALSE && dist[j] > graph[now][j])
			{
				dist[j] = graph[now][j];
				from[j] = now;
			}
		}
	}
	printf("Prim’s Algorithm을 이용한 minimum cost spanning tree 생성: {");
	for (int i = 1; i < TOTAL_VERTEX; i++)
	{
		printf(" (%d,%d) ", from[i], i);
	}
	printf("}\n");
}

int main()
{
	
	kruskal();
	prim();
	return 0;
}