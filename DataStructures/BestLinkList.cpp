//BestLinkList
//2015.11.26

//头文件
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define ERROR 0;
using namespace std;


//类型定义
typedef int ElemType;
typedef int status;
typedef struct Node{                    //结点类型
    ElemType data;                      //数据域
    Node* next;                         //指针域
}Node;
typedef Node* LinkList;                 //LinkList指向结点的指针类型



//链表的创建

//带头结点的LinkList
status createLinkList(LinkList &L) {
    L = (LinkList)malloc(sizeof(Node));         //指向头结点的头指针 L
    if (L == NULL) {
        printf("创建失败！\n" );
        exit(0);
    }
    LinkList p = L;                             //p也指向头结点
    L->next = NULL;
    printf("请输入链表的长度:" );
    int length;
    scanf("%d",&length);
    printf("请依次输入元素:");
    for (int i = 1; i<=length; i++ ){
        p->next = (LinkList)malloc(sizeof(Node));
        scanf("%d",&p->next->data);
        p = p->next;
    }

    p->next = NULL;                             //尾结点的指针域为空
    printf("链表创建成功!\n" );
    return OK;
}


status showLinkList(LinkList L) {
    LinkList p = L->next;                       //p指向第一个结点
    printf("链表输出如下:");
    while (p != NULL) {                         //当前结点不为空
        printf("%d ",p->data);
        p = p->next;                            //p指针后移
    }
    printf("\n");

    return OK;
}


status insertElem(LinkList L) {
    int location;
    printf("请输入在第几个元素之后插入:" );
    scanf("%d",&location);
    ElemType e;
    printf("请输入需要插入的元素：");
    scanf("%d",&e);
    LinkList p = L;                       //p指向头结点
    for (int i = 1; i<=location ; i++) {
        p = p->next;                     //p指向第location个结点
    }

    LinkList s = (LinkList)malloc(sizeof(Node));
    s->data = e;                        //赋值
    s->next = p->next;                  //连接后一结点和s
    p->next = s;                        //连接s和前一结点
    printf("插入成功!\n" );
    return OK;

}


//删除元素
status deleteElem(LinkList &L) {
    int location;
    printf("需要删除第几个元素？" );
    scanf("%d",&location);
    LinkList p = L;
    for (int i = 1;i<location;i++) {
        p = p->next;                        //指向第 location-1 个元素
    }

    LinkList t = p->next;
    p->next = t->next;
    free(t);
    printf("删除成功！\n" );
    return OK;
}

//main
int main(){
    LinkList L;                         //头指针变量LinkList
    createLinkList(L);                  //建表
    showLinkList(L);
    insertElem(L);                      //插入
    showLinkList(L);
    deleteElem(L);                      //删除
    showLinkList(L);
    return OK;

}
