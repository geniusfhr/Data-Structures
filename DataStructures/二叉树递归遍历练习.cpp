// BinaryTree
//二叉树的遍历


//头文件
#include<stdio.h>
#include<iostream>
#define OK 1;
#define ERROE 0;


//类型定义
typedef int Status;
typedef int ElemType;

typedef struct  Node{           //定义树结点 结构体类型
    ElemType data;              //数据域
    Node* lchild;               //左孩子
    Node* rchild;               //右孩子
}Node;

typedef Node*  TNode;




Status createBinaryTree(TNode T){          //二叉树的先序建立
    scanf("%d",&T->data);

    if (T->data == 0) {                     //虚构的孩子 该结点为空 不存在子节点 直接return
        return OK;
    }

    T->lchild = (TNode)malloc(sizeof(Node));
    T->rchild = (TNode)malloc(sizeof(Node));
    createBinaryTree(T->lchild);            //递归构造左子树
    createBinaryTree(T->rchild);            //递归构造右子树


    return OK;
}



Status preOrderTraversalTree(TNode T){       //先序递归遍历算法

    if (T->data == 0) {
        return OK;
    }

    printf("%d ",T->data);

    preOrderTraversalTree(T->lchild);       //递归遍历左子树
    preOrderTraversalTree(T->rchild);       //递归遍历右子树

    return OK;
}





Status midOrderTraversalTree(TNode T){     //中序递归遍历算法
    if (T->data == 0) {                     //虚构的孩子
        return OK;
    }

    midOrderTraversalTree(T->lchild);
    printf("%d ",T->data);                   //visit访问该结点
    midOrderTraversalTree(T->rchild);


    return OK;
}



Status lostOrderTraversalTree(TNode T){        //后序递归遍历
    if (T->data == 0) {
        return OK;                      //虚构的孩子 直接return
    }

    lostOrderTraversalTree(T->lchild);
    lostOrderTraversalTree(T->rchild);
    printf("%d ",T->data);


    return OK;
}



int main(){
    Node rootTree;
    printf("先序输入BinaryTree数据:");
    createBinaryTree(&rootTree);
    printf("先序输出：");
    preOrderTraversalTree(&rootTree);
    printf("\n中序输出：");
    midOrderTraversalTree(&rootTree);
    printf("\n后序输出：");
    lostOrderTraversalTree(&rootTree);
    return OK;

}
