/*
*队列 Queue
*int is_empty(Queue q);
*Status enqueue(Queue& Q,int c);
*Status dequeue(queue& Q,int& c)
*
*/

#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct {         //Queue结构体
    int data[MAXSIZE];          //数据域
    int currentSize;           //当前长度
}MyQueue;

Status initQueue(Queue& Q){             //初始化队列
    for(int i = 0;i < MAXSIZE; i++){
        Q.data[i] = 0;              //数据置0
    }
    Q.currentSize = 0;              //当前长度置空
    return OK;
}

int is_empty(Queue Q){              //判空
    if(Q.currentSize == 0){
        return 1;
    } else {
        return 0;
    }
}


//将e入列Q
Status Enqueue(Queue& Q,int e){
    q.data[Q.currentSize] = e;  //入列
    currentSize++;              //长度增加
    return OK;
}

//出列 以e返回
Status Dequeue(Queue& Q,int& e){
    if(Q.currentSize == 0){
        printf("队中无元素，出列失败!\n");
        return ERROR;
    }
    e = Q.data[0];    //e返回
    for(int i = 1;i < Q.currentSize; i++){
        Q.data[i-1] = Q.data[i];     //往前挪
    }
    currentSize--;                  //长度减一
    return OK;
}
