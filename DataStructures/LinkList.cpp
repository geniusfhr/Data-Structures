//LinkList
//⌚️

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1
#define FLASE 0
typedef int status;
typedef int ElemType;

struct Node
{
    ElemType data;
    struct Node* next;
};


typedef struct Node* LinkList;          //指向结点的指针变量 LinkList
status LinkGet(LinkList head,int i,ElemType* e)             //用e返回第i个元素
{
    LinkList p;
    p = head;
    for(int k = 1;k < i;k++)
    {
        p = p->next;                    //遍历链表 使p指向第i个元素

    }
    *e = p->data;                       //用e返回第i个元素
    return TRUE;
}

status LinkInsert(LinkList head,int i ,ElemType e)      //在第i个位置之后插入元素e
{
    LinkList p;
    p = head;
    for(int k = 1;k < i ;k++)
    {
        p = p->next;                        //p指向第i个结点  即第i个数据
    }

    LinkList s = (LinkList)malloc(sizeof(Node));    //新建结点s
    s->data = e;
    s->next = p->next;                              //将s结点和p前后结点连接
    p->next = s;

    return TRUE;
}


status LinkDelete(LinkList head,int i)              //删除第i个结点后面的结点
{
    LinkList p,q;
    p = head;
    for(int k = 1; k < i; k++)
    {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return TRUE;
}


status Link_all_delete(LinkList head)               //单链表的整表删除
{
    LinkList p = head;
    LinkList q;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    return TRUE;
}


status LinkCreate(LinkList head,int n)               //创建链表 头插法
{
    head->next = NULL;
    head->data = NULL;
    LinkList p;
    for(int i = 1; i <= n;i++)
    {
         p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100;
        p->next = head->next;
        head->next = p;
    }

    return TRUE;
}

status LinkCreate_end(LinkList head,int n )         //创建链表 尾插法
{
    LinkList p;
    p = head;
    p->next = NULL;
    LinkList s;
    for(int k =1; k < n;k++)
    {
        s =(LinkList)malloc(sizeof(Node));
        s->data = rand()%100;
        p->next = s;
        p = s;
    }
    s->next = NULL;
    return TRUE;
}



status LinkShow(LinkList head)              //输出链表
{
    LinkList p = head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return TRUE;
}

int main()
{
    Node Link;
    LinkCreate(&Link, 8);
    LinkShow(&Link);
    LinkInsert(&Link, 3, 1000);
    LinkShow(&Link);
    LinkDelete(&Link, 5);
    LinkShow(&Link);
}
