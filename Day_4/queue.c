#include "stm32f1xx_hal.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // 큐의 최대 크기

// 큐 구조체 정의
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// 큐 초기화
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// 큐가 비어있는지 확인
int isEmptyQ(Queue *q) {
    return q->front == -1;
}

// 큐가 가득 찼는지 확인
int isFullQ(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// 큐에 요소 추가 (enqueue)
void enqueue(Queue *q, int value) {
    if (isFullQ(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmptyQ(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
}

// 큐에서 요소 제거 (dequeue)
int dequeue(Queue *q) {
    if (isEmptyQ(q)) {
        printf("Queue underflow\n");
        return -1; // 에러 값을 반환
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // 큐가 비어있는 상태로 만듦
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

// 큐의 맨 앞 요소 확인 (peek)
int peekQ(Queue *q) {
    if (isEmptyQ(q)) {
        printf("Queue is empty\n");
        return -1; // 에러 값을 반환
    }
    return q->data[q->front];
}

void doQueueTest(void) {
    Queue qdata;
    
    printf("<Queue Test>\n");
    initQueue(&qdata);

    enqueue(&qdata, 10);
    printf("Front element is %d\n", peekQ(&qdata));
    enqueue(&qdata, 20);
    printf("Front element is %d\n", peekQ(&qdata));
    enqueue(&qdata, 30);
    printf("Front element is %d\n", peekQ(&qdata));

    printf("Dequeued element is %d\n", dequeue(&qdata));
    printf("Dequeued element is %d\n", dequeue(&qdata));
    printf("Dequeued element is %d\n", dequeue(&qdata));

    if (isEmptyQ(&qdata)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

}
