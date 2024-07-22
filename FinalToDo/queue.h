#ifndef QUEUE_CODE_H
#define QUEUE_CODE_H

#define MAX 10 // 큐의 최대 크기

// 큐 구조체 정의
typedef struct {
    uint16_t  data[MAX];
    int16_t front;
    int16_t rear;
} Queue;

void initQueue(Queue *q);
int isEmptyQ(Queue *q);
void enqueue(Queue *q, int value) ;
int dequeue(Queue *q) ;
int peekQ(Queue *q) ;

void doQueueTest(void);

#endif //QUEUE_CODE_H