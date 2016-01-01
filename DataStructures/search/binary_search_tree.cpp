/*
*binary_search_tree
*BST 二叉搜索 二叉树查找 二叉排序树
*
*/
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct Node{
    int data;
    Node* lchild;
    Node* rchild;
}Node;

//二叉排序树的查找
// p指向查找到的结点 若找不到 指向父结点
//f指向父节点
Status search_BST(Node* & T,int key,Node* f,Node* &p){
    if(T == NULL){                     //未找到
        p = f;
        return ERROR;
    } else if(T->data == key) {       //找到
        p = f;
        return OK;
    } else if(key < T->data){       //key比当前结点的小 进入左子树找
       return  search_BST(T->lchild,key,T,p);
    } else {                        //key比当前结点大，进入右子树找
       return  search_BST(T->rchild,key,T,p);
    }

}


//二叉排序树的插入操作  利用查找方法中的 p
//未找到的时候执行插入

Status insert_BST(Node* & T,int key){
    Node* p = NULL;            //指向插入的结点
    Node* s = NULL;
    if(search_BST(T,key,NULL,p)){          //找到了，不再插入
        printf("BST树中已存在该元素。\n");
        return ERROR;
    } else {                    //找不到，需要插入新结点
        s = (Node*)malloc(sizeof(Node));
        s->data = key;
        s->lchild = s->rchild = NULL;

        if(!p){         //空树
            T = s;
        } else if(key < p->data){          //  插入元素比父节点小
            p->lchild = s;          //插在左孩子上
        } else {
            p->rchild = s;          //插在右孩子上
        }
    }
    return OK;
}


Status InOrderTraversalBST(Node* T){
    if(!T){
        return OK;
    }
    InOrderTraversalBST(T->lchild);
    printf("%d ",T->data);
    InOrderTraversalBST(T->rchild);
    return OK;

}

int main(){
    Node* T = NULL;
    int a[] = {3,2,4,5,6,8,8};
    for(int i = 0; i < 6; i++){
        insert_BST(T,a[i]);
    }
    InOrderTraversalBST(T);
}
