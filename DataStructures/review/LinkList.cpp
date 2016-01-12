/*
*LinkList.cpp
*单链表
*2016-1-12
*/

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct Node{
    ElemType data;                  //数据域
    struct Node* next;              //指针域
}Node,* LinkList;


/*******************************************************

Status initLinkListFront(LinkList& L,int n );
Status initLinkListEnd(LinkList& L,int n );
Status  insertLinkList(LinkList& L,int location,int e);
Status deleteLinkList(LinkList& L,int location);
Status showLinkList(LinkList L);

*********************************************************/


//头插法 L头指针 n元素个数 逆序输入数据元素
Status initLinkListFront(LinkList& L,int n ){
    L = (LinkList)malloc(sizeof(Node));      //L头指针指向--头结点
    L->next = NULL;

    for(int i = n; i > 0; i--){            //第i个
        LinkList s = (LinkList)malloc(sizeof(Node));
        scanf("%d",&s->data);
        s->next = L->next;                  //头插  在头结点和第一个结点之间插入
        L->next = s;
    }

    return OK;
}


//尾插法 n个元素
Status initLinkListEnd(LinkList& L,int n ){
    L = (LinkList)malloc(sizeof(Node));     //头指针L指向  头结点
    LinkList p = L ;
    for(int i = 1; i<= n; i++){
        LinkList s = (LinkList)malloc(sizeof(Node));
        scanf("%d",&s->data);
        s->next = NULL;
        p->next = s;                        //尾部插入
        p = p->next;                        //指针后移
    }

    return 0;
}


//插入元素e 在第location个位置
Status  insertLinkList(LinkList& L,int location,int e){
    LinkList p = L;                    //指向头结点
    for(int i = 1; i< location; i++){
        p = p->next;                    //p指向第location - 1 个结点
    }
    LinkList s = (LinkList)malloc(sizeof(Node));    //新结点

    s->data = e;                        //数据域赋值
    s->next = p->next;                  //连后线
    p->next = s;                        //连前线

    return OK;

}


//删除第location个元素
Status deleteLinkList(LinkList& L,int location){
    LinkList p  = L;
    for(int i = 1; i < location; i++){
        p = p->next;            //p指向第location - 1个元素
    }

    LinkList s = p->next;       //指向location
    p->next = s->next;         //连location前后元素
    free(s);
    return OK;
}


Status showLinkList(LinkList L){
    LinkList p = L;
    while(p){                       //当前指针不空
        printf("%d ",p->data);
        p = p->next;                //指针后移
    }

    return OK;
}


int main(){
    LinkList l;
    initLinkListFront(l,5);
    showLinkList(l);
    insertLinkList(l,1,0);
    showLinkList(l);
    deleteLinkList(l,5);
    showLinkList(l);
}
