#include "stm32f1xx_hal.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // ť�� �ִ� ũ��

// ť ����ü ����
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// ť �ʱ�ȭ
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// ť�� ����ִ��� Ȯ��
int isEmptyQ(Queue *q) {
    return q->front == -1;
}

// ť�� ���� á���� Ȯ��
int isFullQ(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// ť�� ��� �߰� (enqueue)
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

// ť���� ��� ���� (dequeue)
int dequeue(Queue *q) {
    if (isEmptyQ(q)) {
        printf("Queue underflow\n");
        return -1; // ���� ���� ��ȯ
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // ť�� ����ִ� ���·� ����
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

// ť�� �� �� ��� Ȯ�� (peek)
int peekQ(Queue *q) {
    if (isEmptyQ(q)) {
        printf("Queue is empty\n");
        return -1; // ���� ���� ��ȯ
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
