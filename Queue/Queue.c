#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 5
// ��������� �� �� ����
typedef struct { // ��� Ÿ��
	int id;
	int arrival_time;
	int service_time;
} element;

// ���� ���� ��� ��
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// ���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ť �ʱ�ȭ �Լ�
void init_queue(QueueType *q)
{
	q->front = -1;
	q->rear = -1;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType *q)  // ��������� 0, �ƴϸ� -1
{
	if (q->front == q->rear)
	{
		return 0;
	}
	return -1;
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q) // ���� �� ������ 0, �ƴϸ� -1
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
	{
		return 0;
	}
	return -1;
}

// ���� �Լ�
void enqueue(QueueType *q, element item)
{
	if (is_full(q) == -1)
	{
		q->data[++(q->rear)] = item;
	}
}

// ���� �Լ�
element dequeue(QueueType *q)
{
	if (is_empty(q) == -1)
	{
		return q->data[++(q->front)];
	}
}
// ���� �Լ�
int main(void)
{
	// ����
	int minutes = 10; // �ùķ��̼� �ð�
	int total_wait = 0; //������ ��ٸ� �ð�
	int total_customers = 0; // ���� ���� �� ��
	int employee = 2; // ���� ���� â�� ����
	QueueType queue;
	init_queue(&queue);
	element customer[2] = { -1, -1, -1, -1, -1, -1 };
	srand(time(NULL));
	element come;
	int pop_count = 0;

	for (int clock = 0; clock < minutes; clock++) {
		printf("����ð�=%d\n", clock);
		if ((rand() % 10) < 3) {
			// ������ ���� üũ�ϰ� ���� 
			come = (element){ total_customers++, clock, rand() % 3 + 1 };
			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð� = %d��\n", come.id, come.arrival_time, come.service_time);

			if (customer[0].service_time == -1)
			{
				customer[0] = come;
			}
			else if (customer[1].service_time == -1)
			{
				customer[1] = come;
			}
			else
				enqueue(&queue, come);
		}
		for (int i = 0; i < 2; ++i) {
			if (customer[i].arrival_time == clock || pop_count == i + 1 || pop_count == 3) // â���� ���� ó�� ������ ��
			{
				printf("%d�� â������ �� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n", i + 1, customer[i].id, clock, clock - customer[i].arrival_time);
				total_wait += clock - customer[i].arrival_time;
			}
			else if (customer[i].service_time > -1) // â���� ���� ���� ��
			{
				printf("%d�� â������ �� %d ����ó�����Դϴ�.\n", i + 1, customer[i].id);
			}
		}
		pop_count = 0;
		for (int i = 0; i < employee; i++) {
			// â�� �� ������ ���� ���� ���� ������� ������ ó���ϴ� �κ�
			if (customer[i].service_time != -1)
			{
				customer[i].service_time--;
				if (customer[i].service_time == -1) {
					if (is_empty(&queue) == -1) {
						customer[i] = dequeue(&queue);
						pop_count += i + 1; // 1�� â���� �������� 1, 2�� â���� �������� 2, �� �� �������� 3
					}
				}
			}
		}
	}
	printf("��ü ��� �ð�=%d�� \n", total_wait);
	return 0;
}