//LinkStack 栈的链式存储结构的实现

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    Node* next;
}Node;                                  //定义链栈的结点结构体

typedef struct
{
    Node* top;                          //栈顶指针
    int count;                          //计数器
}LinkStack;                             //定义链栈LinkStack结构体

status Push(LinkStack* S,ElemType e)  //将e元素压入栈
{
    Node* s;
    s = (Node*)malloc(sizeof(Node));
    s->next = S->top;
    s->data = e;
    S->top = s;
    S->count++;
    
    return TRUE;
}

status Pop(LinkStack* S,ElemType *e)    //将栈顶元素弹出 并以e返回
{
    if(S->top == NULL)
    {
        return FALSE;
    }
    
    *e = S->top->data;
    Node* p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    
    return TRUE;

}


