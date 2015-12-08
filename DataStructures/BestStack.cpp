//BestStack
//栈的顺序实现
//2015.11.28

//head file
#include <iostream>
#include <stdio.h>
#define OK 1;
#define ERROR 0;
#define MAXSIZE 20;



//type define
typedef int Status;
typedef int ElemType;

typedef struct Stack{
    ElemType* data;                 //数组基地址
    int top;                        //栈顶指针 指向入栈的
}Stack;


//initStack 栈的初始化
Status initStack(Stack& S) {
    printf("正在初始化~.....\n" );
    top = 0;                                //栈顶指针指向第一个元素
    S.data = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));

    if (S.data == NULL) {                   //分配内存失败
        printf("初始化失败!\n" );
        exit(-1);
    }

    printf("Stack初始化完毕!\n" );
    return OK;
}


//push 入栈
Status push(Stack& S) {
    if (S.top == 49) {
        printf("栈已满!!" );
        exit(-1);
    }

    printf("请输入需要入栈的元素:" );
    scanf("%d",&S.data[S.top]);
    S.top++;                                //栈顶指针后移
    printf("入栈成功！\n" );
    return OK;

}


//pop出栈 以e返回
Status pop (Stack& S,ElemType& e) {
    if (S.top == 0) {                   //栈内无元素
        printf("栈已空！无法pop！\n" );
        exit(-1);
    }

    e = S.data[S.top-1];                //赋值给e 返回
    S.top--;                            //栈顶指针前移一位
    printf("pop成功！\n" );
    return OK;
}



//栈的遍历 输出
Status stackTraversal(Stack& S) {
    printf("遍历结果如下:", );

    for (int i = 0; i<= S.top-1; i++) {
        printf("%d \n",S.data[i] );             //遍历
    }
    return OK;

}
