//线性表的顺序结构
//⌚️
#include<stdio.h>                                 //头文件
#define MAXSIZE 100
#define TRUE 1;
#define FLASE 0;
typedef int ElemType;
typedef int status;



typedef struct
    {
        ElemType data[MAXSIZE];                 //MyList的核心 数组data 最大长度100
        int length;                             //当前线性表长度 自然计数 1 2 ...

    }MyList;                                        //MyList 线性表结构体

status ListGet(MyList* list,int i,ElemType* e)      //获得第i个元素，并用e返回
{
    if(list->length == 0 || i >  list->length || i < 0 )
        return FLASE;
    *e = list->data[i-1];
    return TRUE;
}

status ListInsert(MyList* list,int i ,ElemType e)  //在第i个位置之前插入元素e
{
    if(list->length == MAXSIZE)                     //线性表已满
        return FLASE;
    if(i > list->length+1 || i < 1)                 //插入序号不在范围内
        return FLASE;
    if(i < list->length+1)                          //不在表尾插入
    {
        for(int k =list->length ; k > i-1 ; k--)
        {
            list->data[k] = list->data[k-1];        //从第i个元素开始往后移位

        }
    }

    list->data[i-1] = e;                        //在第i个位置插入e元素
    list->length++;
    return TRUE;

}

status ListDelete(MyList* list,int i)           //删除第i个位置的元素
{
    if(i < 1 || i > list->length)               //删除序号不在范围内
        return FLASE;
    for(int k = i; k <= list->length; k++)
    {
        list->data[k-1] = list->data[k];

    }
    list->length--;
    return true;

}

status  ListShow(MyList* list)                  //输出线性表
{
    for(int i = 0; i <= list->length-1 ; i++)
    {
        printf("%d ",list->data[i]);


    }
    printf("\n");
    return TRUE;

}



status ListCreate(MyList* list )
{
    printf("初始化线性表ing,请输入表的长度(int):");
    scanf("%d",&list->length);
    printf("请输入数据:\n");
    for(int i = 0; i <= list->length-1; i++)
    {
        scanf("%d",&list->data[i]);
    }
    printf("创建成功！\n");
    return TRUE;
}

int main()
{
    int e;
    MyList l;
    ListCreate(&l);
    ListShow(&l);
    ListGet(&l, 3, &e);
    printf("第三个元素是%d\n",e);
    ListInsert(&l,1, 6);
    printf("在第一个位置插入6后：\n");
    ListShow(&l);
    return 0;


}
