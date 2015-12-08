
//  Created by 方浩然 on 15/11/26.
//  Copyright (c) 2015年 方浩然. All rights reserved.
//线性表的顺序实现

//头文件
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define ERROR 0;
#define OVERFLOW 1;
using namespace std;


//类型定义
int MAXSIZE = 100;
typedef int status;
typedef int ElemType;
typedef struct ArrayList {                  //定义ArrayList数据类型
    ElemType* elem;                          //动态数组基地址
    int listLength;                          //表长
}ArrayList;


//创建顺序表
status createArrayList(ArrayList &list) {
    list.elem = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));        //动态分配数组 保存基地址
    if (list.elem == NULL) {                                         //分配失败
        printf("内存分配失败！程序已退出！\n");
        exit(0);
    }
    printf("线性表创建成功！\n" );
    list.listLength = 0;

    return OK;
}


//初始化list
status initArrayList(ArrayList &list){                              //初始化
    printf("初始化线性表，请输入线性表的元素个数:");
    int elemNum;
    scanf("%d",&elemNum);
    printf("请依次输入元素:");
    for (int i = 0; i< elemNum; i++) {
        scanf("%d",&list.elem[i]);
        list.listLength++;
    }
    printf("输入完毕！\n");

    return OK;
}


//在第i个位置插入元素e
status insertElem(ArrayList &list) {
    printf("你希望将元素插入第几个位置？请输入:" );
    int location;
    scanf("%d",&location);
    printf("需要插入的数据是:" );
    ElemType e ;
    scanf("%d",&e);
    if (location != list.listLength+1) {                    //插入位置不是表尾
        for (int i = list.listLength; i >= location; i--) {
            list.elem[i] = list.elem[i-1];                  //后移一位
        }
    }

    list.elem[location-1] = e;                              //在第location个位置插入
    list.listLength++;
    printf("插入成功！\n" );
    return OK;
}


status deleteElem(ArrayList &list){
    int location;
    printf("你希望删除第几个元素？" );
    scanf("%d",&location);
    for (int i = location;i < list.listLength; i++) {
        list.elem[i-1]  = list.elem[i];                     //往前覆盖
    }
    list.listLength--;
    printf("删除成功！\n");
    return OK;
}



//输出线性表
status showArrayList(ArrayList &list) {
    printf("线性表输出如下:\n" );
    for (int i = 1; i <= list.listLength; i++) {
        printf("%d ",list.elem[i-1] );                      //输出第i个元素
    }
    printf("\n");
    return OK;
}


//main
int main(){
    ArrayList list;
    createArrayList(list);              //创建
    initArrayList(list);                //初始化
    showArrayList(list);                //输出
    insertElem(list);                   //插入
    showArrayList(list);
    deleteElem(list);                   //删除
    showArrayList(list);
    return 0;
}
