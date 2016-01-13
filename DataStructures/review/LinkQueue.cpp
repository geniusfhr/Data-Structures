/*
*LinkQueue.cpp
*2016-1-13
*
*/

#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define ERROR 0;

typedef int Status;
typedef int ElemType;

typedef struct Node{            //Queue结点类型
    ElemType data;
    struct Node* next;
}Node,*QueuePtr;

typedef struct LinkQueue{
    QueuePtr front;             //Queue头指针
    QueuePtr rear;              //尾指针
}LinkQueue;


/***************************************************

Status initLinkQueue(LinkQueue& Q);
Status enQueue(LinkQueue& Q,ElemType e);
Status deQueue(LinkQueue& Q,ElemType& e);
Status destroyQueue(LinkQueue& Q);

****************************************************/


Status initLinkQueue(LinkQueue& Q){
    Q.front = (QueuePtr)malloc(sizeof(Node));
    if(!Q.front){
        exit(-1);
    }

    Q.rear = Q.front;               //空队列 指针
    Q.front->next = NULL;           //头结点的指针域为空
    return OK;
}


Status enQueue(LinkQueue& Q,ElemType e){
    QueuePtr s = (QueuePtr)malloc(sizeof(Node));
    if(!s){
        exit(-1);                   //分配失败
    }
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;               //连接
    Q.rear = s;                     //队尾指针后移
    return OK;
}

Status deQueue(LinkQueue& Q,ElemType& e){
    if(Q.front == Q.rear){
        exit(-1);                       //队列空
    }

    QueuePtr q = Q.front->next;
    e = q->data;
    Q.front->next = q->next;
    if(!q->next){                     //只有一个元素
        Q.rear = Q.front;             //尾指针指向头结点
    }
    free(q);

    return OK;
}


Status destroyQueue(LinkQueue& Q){
    QueuePtr q;
    while(Q.front){
        q = Q.front->next;          //即将销毁的下一位
        free(Q.front);
        Q.front = q;

    }
    return OK;
}
