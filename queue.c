#include "queue.h"


/*
 * purpose:DeQueue
 * how it works:change the pointer of front
 * how related:Empty()*/
bool DeQueue(LinkQueue *Q,ElemType *x){
    if(Empty(Q))
        return false;
    LinkNode *p=Q->front->next;
    *x=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return true;
}
/*
 * purpose:EnQueue
 * how it works:change the pointer of rear
 * how related:Empty()*/
void EnQueue(LinkQueue *Q,ElemType x){
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
}
/*
 * purpose:InitQueue
 * how it works:Make rear and front point to the same place
 * how related:*/
void InitQueue(LinkQueue *Q){
    Q->front=Q->rear=(LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next=NULL;
}
/*
 * purpose:Determine whether the queue is empty
 * how it works:
 * how related:*/
bool Empty(LinkQueue *Q){
    if(Q->front->next==NULL)
        return true;
    else
        return false;
}