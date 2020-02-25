#include <stdio.h>
#include <string.h>
struct Data {
	char work[20];
	int time;
};
struct Heap {
	int heap_size;
	struct Data data[11];
};

void InsertMaxHeap(struct Heap *h) {
	int i = (h->heap_size);
	int temp_time = h->data[i].time;
	char temp_work[20];
	strcpy(temp_work, h->data[i].work);
	while (i != 1 && h->data[i / 2].time < temp_time) {
		h->data[i].time = h->data[i / 2].time;
		strcpy(h->data[i].work, h->data[i / 2].work);
		i /= 2; 
	}
	h->data[i].time = temp_time;
	strcpy(h->data[i].work, temp_work);
}

struct Data DeleteMaxHeap(struct Heap * h, int idx) {
	struct Data data;
	data.time = h->data[1].time;
	strcpy(data.work, h->data[1].work);

	int temp_time = h->data[h->heap_size].time;
	char temp_work[20];
	strcpy(temp_work, h->data[h->heap_size--].work);

	int parent = idx;
	int child = parent * 2;
	while (child <= h->heap_size) { 
		if (child < h->heap_size && h->data[child].time < h->data[child + 1].time) child++;
	
		if (h->data[child].time < temp_time) break;
	
		h->data[parent].time = h->data[child].time;
		strcpy(h->data[parent].work, h->data[child].work);
		parent = child;
		child *= 2;
	}
	h->data[parent].time = temp_time;
	strcpy(h->data[parent].work, temp_work);
	return data;
}
int main()
{
	char input[3];

	struct Heap heap;
	heap.heap_size = 0;

	while (input[0] != 'p')
	{
		printf("삽입(i), 삭제(d), 출력(p): ");
		scanf("%s", &input);
		if (input[0] == 'i')
		{
			printf("해야 할 일: ");
			scanf("%s", heap.data[++heap.heap_size].work);
			
			printf("소요시간(분): ");
			scanf("%d", &heap.data[heap.heap_size].time);
			InsertMaxHeap(&heap);
			printf("\n");
		}
		else if (input[0] == 'd')
		{
			char input_work[20];
			printf("삭제 할 일: ");
			scanf("%s", input_work);
			for (int i = 1; i <= heap.heap_size; ++i) {
				if (strcmp(heap.data[i].work, input_work) == 0) {
					DeleteMaxHeap(&heap, i);
					printf("%s이 삭제됨\n\n", input_work);
					break;
				}
			}
		}
		else if (input[0] == 'p') {
			printf("\n");
			int len = heap.heap_size;
			for (int i = 1; i <= len; i++)
			{
				if (heap.heap_size == 0) break;
				struct Data data = DeleteMaxHeap(&heap, 1);
				printf("%s-%d분\n", data.work, data.time);
			}
			break;
		}
	}

}