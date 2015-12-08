//
//  main.cpp
//  DataStructureHomework
//
//  Created by 方浩然 on 15/10/20.
//  Copyright (c) 2015年 方浩然. All rights reserved.

//头文件定义


#include<iostream>
#include<stdlib.h>
#define OK 1
#define ERROR 0


//结构体定义

typedef int status;

//数据域类型
typedef struct {
    float coef;         //系数
    int expn;           //指数
}ElemType;


//结点类型
typedef struct Node{
    ElemType data;      //数据域
    Node* next;         //指针域
}Node;

//链表类型
typedef struct {
    Node* headPoint;    //头指针
    int length;         //LinkList长度
}LinkList;


//创建链表

status initLinkList(LinkList &L,int ElemNum){
    L.headPoint = (Node*)malloc(sizeof(Node));          //头指针
    Node* p = L.headPoint;
    Node* t = p;
    printf("请按升幂输入多项式的系数和指数:");
    for (int i = 0; i<ElemNum; i++) {
        p->next = (Node*)malloc(sizeof(Node));
        p = p->next;
        scanf("%f%d",&p->data.coef,&p->data.expn);
    }
    p->next = NULL;
    t = t->next;                                        //第一个结点
    printf("当前输入的多项式为:\n");
    while (t) {
        printf(" + %.2fx^%d",t->data.coef,t->data.expn);
        t = t->next;                                //指向下一个结点
    }
    printf("\n");
    return OK;

}

status printLinkList(LinkList &L){
    Node* p;
    printf("两个多项式相加后为:\n");
    p = L.headPoint->next;
    while (p) {
        printf(" + %.2fx^%d",p->data.coef,p->data.expn);
//        printf("nini");
        p = p->next;
    }
    return OK;

}

int compare(float a,float b ){
    if(a>b){
        return 1;
    }else if(a<b){
        return -1;
    }else{
        return 0;
    }

}


status addLinkList(LinkList &L1,LinkList &L2){
    Node* ta = L1.headPoint;
    Node* tb = L2.headPoint;
    Node* pa = ta->next;
    Node* pb = tb->next;
    while (pa && pb) {
    switch (compare(pa->data.expn, pb->data.expn)) {
        case -1:
        {
            ta = pa;
            pa = pa->next;             //当前元素后移 临时元素也后移1位
            break;
        }
        case 0:
        {
            float sum = pa->data.coef + pb->data.coef;
            if(sum != 0){               //系数相加不为0
                pa->data.coef = sum;
                tb->next = pb->next;
                pb = pb->next;
                ta = pa;
                pa = pa->next;
            }else{                      //系数为0
                pa = pa->next;
                free(ta->next);         //1中删除结点
                ta->next = pa;

                pb = pb->next;
                free(tb->next);         //2中删除结点
                tb->next = pb;
            }
            break;
        }
        case 1:
        {
            tb->next = pb->next;
            pb->next = pa;
            ta->next = pb;          //当前元素插入1  头结点和下一结点连接
            pb = tb->next;

        }
     }
 }
                                      //a中已到最后元素 b仍有结点未比较 将b接入a的尾部
    if(tb->next != NULL)
        ta->next = tb->next;

    return OK;
}



void firstView()
{
    printf("***********************************\n");
    printf("****                            ***\n");
    printf("****     多项式加法计算器        ***\n");
    printf("****                            ***\n");
    printf("***********************************\n\n\n");

}


int main(){
    int aNum,bNum;                      //多项式的系数
    LinkList L1,L2;                     //两个链表
    firstView();
    printf("请输入第一个多项式的项数:");
    scanf("%d",&aNum);
    initLinkList(L1, aNum);
    printf("请输入第二个多项式的项数:");
    scanf("%d",&bNum);
    initLinkList(L2, bNum);
    addLinkList(L1, L2);
    printLinkList(L1);


}
