//Queue  (队列) 一端删除 一端插入的线性表
//LinkQueue 的c语言实现 链式存储结构 的队列

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int status;
typedef int ElemType;

typedef struct  Node
{
    ElemType data;
    Node* next;
    
}Node;                                      //定义结点

typedef struct
{
    Node* front;
    Node* rear;
    
}LinkQueue;                                 //LinkQueue结构体

status Enqueue(LinkQueue* Q,ElemType e)     //入队列操作
{
    Node* s = (Node*)malloc(sizeof(Node));
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    
    return TRUE;
}



status DeQueue(LinkQueue* Q,ElemType* e)    //出队列操作
{
    if(Q->front == Q->rear)                 //队列为空
    {
        return FALSE;
    }
    
    *e = Q->front->next->data ;            //释放第一个结点
    Node* p = Q->front->next;
    Q->front->next = p->next;
    free(p);
    
    return TRUE;
}
















