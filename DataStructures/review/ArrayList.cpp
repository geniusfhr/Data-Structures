/*
*ArrayLsit 数组实现 Linear List线性表
*2016-1-12
*
*
**/

//头文件
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 20
#define INCREASE 5
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct ArrayLsit{
    ElemType* elem;             //元素基地址
    int length;                 //当前长度
    int listSize;              //总长
}ArrayList;


/**************************************************

Status initArrayList(ArrayList& L);
Status insertArrayList(ArrayList& L,int e,int location);
Status deleteArrayList(ArrayList& L,int location);
Status showArrayList(ArrayList L);

***************************************************/


Status initArrayList(ArrayList& L){
    L.elem = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
    if(!L.elem){
        return ERROR;                   //分配失败
    }

    L.length = 0;
    L.listSize = INIT_SIZE;
    return OK;
}

//插入 元素e 位置location之前插入
Status insertArrayList(ArrayList& L,int e,int location ){
    if(L.length >= L.listSize){         //空间已满
        ElemType* newbase;
         newbase = (ElemType*)realloc(L.elem, (L.listSize+INCREASE) * sizeof(ElemType));
         if(!newbase){
             return ERROR;           //分配失败
         }
         L.listSize += INCREASE;        //表长增加
         L.elem = newbase;
    }

    for(int i = L.length; i >= location; i--){
        L.elem[i-1+1] = L.elem[i-1];        //从第location个元素起后移
    }
    L.elem[location-1] = e;                 //插入
    L.length++;                             //当前长度加1
    return OK;

}


//删除第location个元素
Status deleteArrayList(ArrayList& L,int location){
    if(location <= L.length && L.length == 0){
        return ERROR;               //删除失败
    }
    for(int i = location+1; i <= L.length; i++){
        L.elem[i-1-1] = L.elem[i-1];                //从第location+1开始前移
    }

    return OK;

}

Status showArrayList(ArrayList L){
    for(int i = 1;i <= L.length; i++){
        printf("%d ",L.elem[i-1] );
    }
    printf("\n");
}

int main(){
    ArrayList l;
    initArrayList(l);
    for(int i = 1; i<= 100; i++){
        insertArrayList(l,i,1);
    }
    showArrayList(l);
    deleteArrayList(l,1);

    return 0;

}
