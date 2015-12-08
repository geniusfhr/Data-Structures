//BestTree.cpp
//二叉树的建立


//头文件

#include <stdio.h>
#include <iostream>
using namespace std;


//类型定义
#define OK 1;
#define ERROR 0;
typedef int Status;
typedef int ElemType;


//树结点
typedef struct Node{
    ElemType data;              //数据域
    Node* lchild;               //左孩子指针
    Node* rchild;               //右孩子指针
}Node;



//前序遍历  递归算法
Status PreOrderTraversalTree(Node* T) {
    //如果data域为999 直接返回 该结点为虚构的孩子
    if (T->data == 999) {
        return OK;
    }

    printf("%d ",T->data);
    PreOrderTraversalTree(T->lchild);
    PreOrderTraversalTree(T->rchild);
    return OK;

}


//中序遍历  递归算法
Status InOrderTraversalTree(Node* T) {
    //如果data域为空 直接返回 该结点为虚构的孩子
    if (T->data == 999) {
        return OK;
    }

    InOrderTraversalTree(T->lchild);
    printf("%d ",T->data);
    InOrderTraversalTree(T->rchild);
    return OK;

}



//后序递归遍历
Status LostOrderTraversalTree(Node* T) {

    if (T->data == 999) {
        return OK;
    }

     LostOrderTraversalTree(T->lchild);
     LostOrderTraversalTree(T->rchild);
     printf("%d ",T->data);
     return OK;

}




//前序递归建立二叉树
Status PreOrderCreateTree(Node* T) {
    scanf("%d",&T->data );
    if (T->data == 999) {
        return OK;
    }

    T->lchild = (Node*)malloc(sizeof(Node));
    T->rchild = (Node*)malloc(sizeof(Node));
    PreOrderCreateTree(T->lchild);
    PreOrderCreateTree(T->rchild);
    return OK;

}
