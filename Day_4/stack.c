#include "stm32f1xx_hal.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // ������ �ִ� ũ��

// ���� ����ü ����
typedef struct {
    uint16_t data[MAX];
    uint16_t top;
} Stack;

// ���� �ʱ�ȭ
void initStack(Stack *s) {
    s->top = -1;
}

// ������ ����ִ��� Ȯ��
uint16_t isStackEmpty(Stack *s) {
    return s->top == -1;
}

// ������ ���� á���� Ȯ��
int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

// ���ÿ� ��� �߰� (push)
void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// ���ÿ��� ��� ���� (pop)
int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow\n");
        return -1; // ���� ���� ��ȯ
    }
    return s->data[(s->top)--];
}

// ������ �� �� ��� Ȯ�� (peek)
int peekS(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // ���� ���� ��ȯ
    }
    return s->data[s->top];
}

void doStackTest(void) {
    Stack stackdata;
    
    printf("<Stack Test>\n");
    initStack(&stackdata);

    push(&stackdata, 10);
    printf("Top element :%d\n", peekS(&stackdata));
    push(&stackdata, 20);
    printf("Top element :%d\n", peekS(&stackdata));
    push(&stackdata, 30);
    printf("Top element :%d\n", peekS(&stackdata));

    printf("Popped element is %d\n", pop(&stackdata));
    printf("Popped element is %d\n", pop(&stackdata));
    printf("Popped element is %d\n", pop(&stackdata));

    if (isStackEmpty(&stackdata)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

}