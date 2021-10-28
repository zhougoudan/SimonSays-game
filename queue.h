#ifndef SIMON_QUEUE_H
#define SIMON_QUEUE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*each element in node*/
typedef struct {
    char command[40];
    void(*p)();
}ElemType;
/*node in QUEUE*/
typedef struct st{
    ElemType data;
    struct st *next;
}LinkNode;
/*the pointer of front and rear can represent a queue*/
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue *Q);
bool DeQueue(LinkQueue *Q,ElemType *x);
void EnQueue(LinkQueue *Q,ElemType x);
bool Empty(LinkQueue *Q);
#endif //SIMON_QUEUE_H
