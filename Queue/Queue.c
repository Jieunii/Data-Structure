#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 5
// 은행업무를 볼 고객 정보
typedef struct { // 요소 타입
	int id;
	int arrival_time;
	int service_time;
} element;

// 은행 서비스 대기 열
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 큐 초기화 함수
void init_queue(QueueType *q)
{
	q->front = -1;
	q->rear = -1;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)  // 비어있으면 0, 아니면 -1
{
	if (q->front == q->rear)
	{
		return 0;
	}
	return -1;
}

// 포화 상태 검출 함수
int is_full(QueueType *q) // 가득 차 있으면 0, 아니면 -1
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
	{
		return 0;
	}
	return -1;
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q) == -1)
	{
		q->data[++(q->rear)] = item;
	}
}

// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q) == -1)
	{
		return q->data[++(q->front)];
	}
}
// 메인 함수
int main(void)
{
	// 변수
	int minutes = 10; // 시뮬레이션 시간
	int total_wait = 0; //고객들이 기다린 시간
	int total_customers = 0; // 서비스 받은 고객 수
	int employee = 2; // 은행 업무 창구 갯수
	QueueType queue;
	init_queue(&queue);
	element customer[2] = { -1, -1, -1, -1, -1, -1 };
	srand(time(NULL));
	element come;
	int pop_count = 0;

	for (int clock = 0; clock < minutes; clock++) {
		printf("현재시각=%d\n", clock);
		if ((rand() % 10) < 3) {
			// 들어오는 고객을 체크하고 저장 
			come = (element){ total_customers++, clock, rand() % 3 + 1 };
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n", come.id, come.arrival_time, come.service_time);

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
			if (customer[i].arrival_time == clock || pop_count == i + 1 || pop_count == 3) // 창구에 고객이 처음 들어왔을 때
			{
				printf("%d번 창구에서 고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", i + 1, customer[i].id, clock, clock - customer[i].arrival_time);
				total_wait += clock - customer[i].arrival_time;
			}
			else if (customer[i].service_time > -1) // 창구에 고객이 있을 때
			{
				printf("%d번 창구에서 고객 %d 업무처리중입니다.\n", i + 1, customer[i].id);
			}
		}
		pop_count = 0;
		for (int i = 0; i < employee; i++) {
			// 창구 두 곳에서 각각 들어온 고객의 순서대로 업무를 처리하는 부분
			if (customer[i].service_time != -1)
			{
				customer[i].service_time--;
				if (customer[i].service_time == -1) {
					if (is_empty(&queue) == -1) {
						customer[i] = dequeue(&queue);
						pop_count += i + 1; // 1번 창구에 들어왔으면 1, 2번 창구에 들어왔으면 2, 둘 다 들어왔으면 3
					}
				}
			}
		}
	}
	printf("전체 대기 시간=%d분 \n", total_wait);
	return 0;
}