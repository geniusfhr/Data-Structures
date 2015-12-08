//
//  main.cpp
//  ArrayList
//
//  Created by 方浩然 on 15/11/8.
//  Copyright (c) 2015年 方浩然. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#define OK 1
#define ERROE 0


void initArrayList(float (&array)[20])//num 二项式项数
{
    int expn;               //指数
    float coef;             //系数
    int num;
    printf("请输入多项式的项数:");
    scanf("%d",&num);
    for (int i = 0; i<20; i++)
    {
        array[i] = 0;
    }
    
    printf("请按系数 指数的顺序输入多项式：\n");
    for (int i = 0; i<num; i++) {
        scanf("%f%d",&coef,&expn);
        array[expn] = coef;
        
    }
}



void add(float (&array1)[20],float (&array2)[20])
{
    for (int i = 0; i<20; i++)
    {
        array1[i] = array1[i] + array2[i];
    }
}



void show(float (&array)[20])
{
    printf("多项式输出如下:\n");
    for (int i = 0; i<20; i++)
    {
        if (array[i])
        {
            printf(" + %.2fx^%d",array[i],i);
        }
    }
}


int main()
{   float a[20],b[20];
    initArrayList(a);
    initArrayList(b);
    add(a,b);
    show(a);
}















