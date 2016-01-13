/*
*Stack.cpp
*顺序栈
*2016-1-13
*
**/


#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define STACKOVERFLOW -1
#define SIZEINCREAMENT 5
#define INITSTACKSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Stack{
    ElemType* top;          //栈顶指针
    ElemType* base;         //栈底指针
    int stackSize;          //以分配空间
}Stack;

/***************************************************

Status initStack(Stack& S);
Status push(Stack& S,ElemType e);
Status pop(Stack& S,ElemType& e);
Status showStack(Stack S);

****************************************************/

Status initStack(Stack& S){
    S.base = (ElemType*)malloc(INITSTACKSIZE*sizeof(ElemType));
    if(!S.base){
        return ERROR;
    }
    S.top = S.base;             //栈顶指向栈底 栈为空
    S.stackSize = INITSTACKSIZE;
    return OK;
}


//将e进栈
Status push(Stack& S,ElemType e){
    if(S.top - S.base >= S.stackSize){
        S.base = (ElemType*)realloc(S.base,(S.stackSize+SIZEINCREAMENT)*sizeof(ElemType));
        S.top = S.base + S.stackSize;
        S.stackSize += SIZEINCREAMENT;
    }

    *S.top++ = e;          //进栈
    return OK;

}

//pop 以e返回
Status pop(Stack& S,ElemType& e){
    if(S.base == S.top){            //栈空
        exit(-1);
    }
    e = * --S.top
    return OK;

}

Status showStack(Stack S){
    ElemType p = S.base;

    while(p < S.top){
        printf("%d ",*p++);
    }
    return OK;
}

int main(){
    Stack s;
    initStack(s);
    for(int i = 1; i <= 100; i++){
        push(s,i);
    }
    showStack(s);
    int t;
    for(int i = 1; i<=50; i++){
        pop(s,t);
    }
    showStack(s);

}
