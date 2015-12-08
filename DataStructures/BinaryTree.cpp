/*
二叉树 Binary Tree
遍历 输出 根据根节点访问的次序 分位 前序 中序 后序 和层序
建立
*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;                          //数据域
    Node* lChild;                           //指针域 左孩子
    Node* rChild;                           //指向 右孩子

}Node;                                      //定义二叉树结点结构Binary Tree Node

status PreOrderTraverse(Node* T)            //前序递归遍历二叉树算法 T为根节点
{
    if(T->data == 0)
    {
        return TRUE;
    }

    printf("%d ",T->data);
    PreOrderTraverse(T->lChild);
    PreOrderTraverse(T->rChild);

    return TRUE;
}

status InOrderTraverse(Node* T)             //中序遍历
{
    if(T->data == 0)
    {
        return TRUE;
    }

    InOrderTraverse(T->lChild);
    printf("%d ",T->data);
    InOrderTraverse(T->rChild);

    return TRUE;
}

status PostOrderTraverse(Node* T)          //后序遍历算法
{
    if(T->data == 0)
    {
        return TRUE;
    }

    PostOrderTraverse(T->lChild);
    PostOrderTraverse(T->rChild);
    printf("%d ",T->data);

    return TRUE;
}


status CreateBinaryTree(Node* T)             //二叉树的建立 前序算法
{

    ElemType d;
    scanf("%d",&d);
    T->data = d;

    if(T->data == 0000)                       //虚构的孩子
    {
        T = NULL;
        return TRUE;
    }

    T->lChild = (Node*)malloc(sizeof(Node));    //左孩子指针域
    T->rChild = (Node*)malloc(sizeof(Node));    //右孩子指针域
    CreateBinaryTree(T->lChild);
    CreateBinaryTree(T->rChild);

    return TRUE;
}
