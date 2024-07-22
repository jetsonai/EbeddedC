#include "stm32f1xx_hal.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // 스택의 최대 크기

// 스택 구조체 정의
typedef struct {
    uint16_t data[MAX];
    uint16_t top;
} Stack;

// 스택 초기화
void initStack(Stack *s) {
    s->top = -1;
}

// 스택이 비어있는지 확인
uint16_t isStackEmpty(Stack *s) {
    return s->top == -1;
}

// 스택이 가득 찼는지 확인
int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

// 스택에 요소 추가 (push)
void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// 스택에서 요소 제거 (pop)
int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow\n");
        return -1; // 에러 값을 반환
    }
    return s->data[(s->top)--];
}

// 스택의 맨 위 요소 확인 (peek)
int peekS(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // 에러 값을 반환
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