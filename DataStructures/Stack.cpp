//Stack(栈) 的c语言实现
//Stack(栈) 仅能在表尾实现插入删除的线性表
//（存储结构）顺序结构的栈

#include<stdio.h>
#define MAXSIZE 50
#define TRUE 1
#define FALSE 0
typedef int status;
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];             //数组部分
    int top;                            //栈顶指针
    
}Stack;                                 //Stack结构体

status Push(Stack* s,ElemType e)        //将e元素压入栈中
{
    if(s->top == MAXSIZE -1)            //stack 已满
    {
        return FALSE;
    }
    
    s->top++;
    s->data[s->top] = e;
    return TRUE;
};


status Pop(Stack* s,ElemType *e)        //将栈顶元素弹出 并以e返回
{
    if(s->top == -1)                    //空栈 无法弹出
    {
        return FALSE;
    }
    
    *e = s->data[s->top];               //以e返回栈顶元素
    s->top--;
    
    return TRUE;
}





