
//
//  main.cpp
//  tj
//
//  Created by 方浩然 on 15/12/8.
//  Copyright (c) 2015年 方浩然. All rights reserved.
//

//头文件
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;




//结构体定义
typedef struct
{
    int weight;                 //保存权值
    int parent, lchild, rchild; //保存左右孩子的节点值
}HuffmanNode, *HuffmanTree;      //HuffmanTree  指向node的指针

typedef char** HuffmanCode;             //指向char*指针变量的指针变量HuffmanCode 二级指针



void HuffmanCoding(HuffmanTree &HT, int *w, int n);    //Huffman编码函数   w--权值数组
void select(HuffmanTree HT,int n, int &s1, int &s2);   //选择书中节点值较小的两个节点




static HuffmanCode HC;



//huffman编码函数

void HuffmanCoding(HuffmanTree &HT, int *w, int n)
{
    if (n <= 1){
        cout<<"太简单了吧!?"<<endl;
    }

    int m = 2 * n - 1;                               //  n个叶子结点编码 需要2n-1大小的数组
    HT = (HuffmanNode*)malloc((m + 1) * sizeof(HuffmanNode));//Huffman tree的所有节点

    int s1, s2; //record the two mini weights nodes  记录最小的两个权值

    memset(HT, 0, (m + 1) * sizeof(HuffmanNode));    //对所有节点初始化为-0

    for (int i = 1; i <= n; i++)
    {
        HT[i].weight = *w++;    //初始化各节点权值
    }

    //创建Huffman tree
    for(int i = n + 1; i <= m; ++i)
    {
        //选择剩余节点中权值较小的s1和s2
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;                          //连接父亲
        HT[i].lchild = s1;                          //连接左右孩子
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;           //权值相加
    }


    int start, c, f;
     HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
    char* cd = (char*)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for(int i = 1; i <= n; ++i)
    {
        start = n - 1;
        for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
        {
            if (HT[f].lchild == c)              //左孩子是 当前的叶子
                cd[--start] = '0';              //编码为- 0
            else
                cd[--start] = '1';              //右孩子 编码为- 1

        }

        HC[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }

    for (int i = 1; i <= n; i++)
    {
        char cc = i - 1 + ' ';
        cout<<cc<<"   ASCII---"<<i+31<<"    huffman-----"<<HC[i]<<endl;
    }

    free(cd);           //释放空间
    free(HT);
}





//找到两个最小的结点 以s1 s2返回
void select(HuffmanTree HT, int n, int &s1, int &s2)
{
    s1 = 1;
    s2 = 1;
    int min  = 99999;
    int i;


    //选择未被使用的第一个节点，
    for (i = 1; i <= n; ++i)
    {
        if (HT[i].parent == 0)
        {
            min = HT[i].weight;
            break;
        }
    }

    //找s1
    for (int p =  1; p <= n; ++p)
    {
        if(0 == HT[p].parent && min >= HT[p].weight)
        {
            s1 = p;
            min = HT[p].weight;
        }
    }

    //找s2
    min = 99999;
    for (int q =  1; q <= n; ++q)
    {
        if(0 == HT[q].parent && min >= HT[q].weight )
        {
            if( q == s1)
                continue;
            s2 = q;
            min = HT[q].weight;
        }
    }
}




static int charNum  = 0;



//********************************************************************//

int main()
{
    FILE* file = fopen("article.txt", "r+");                //打开文章
    if (file == NULL) {
        cout<<"打开文件失败!~~~"<<endl;
    } else{
        cout<<"成功打开文件!"<<endl;
    }
    char c ;
    int num[96];
    memset(num, 0, sizeof(int)*96);                     //频率数组置0

    while((c = fgetc(file)) != EOF){                    //字符统计
        int n = c - ' ';
        charNum++;
        num[n]++;
    }

//    fclose(file);

    HuffmanTree HT;                 //HuffmanNode*

    HuffmanCoding(HT, num, 96);         //huffman编码


    cout<<endl<<endl<<endl;


    FILE* huffmanFile = fopen("huffmanCode.txt","w");           //打开huffman编码压缩文件

    if (huffmanFile == NULL) {
        cout<<"huffmanCode.txt文件创建失败!"<<endl;
    } else{
        cout<<"huffmanCode.txt文件创建成功！"<<endl;
    }
    cout<<"对article.txt进行huffman编码后的结果如下"<<endl;


    fseek(file,0,SEEK_SET);                                     //光标定位文章到开头

    while((c = fgetc(file))!=EOF){
        if(c == 10){
            continue;
        }                                                      //编码过程 输入huffmanFile
        int tt = c - 32 + 1;
        cout<<HC[tt]<<" ";
        fputs(HC[tt],huffmanFile);
        fputc(' ', huffmanFile);                                //加空格分开


    }

    cout<<endl<<"文章输出完毕！"<<endl;
    cout<<"huffman编码已写入huffmanCode.txt！"<<endl;
    fclose(huffmanFile);

    FILE* decodeFile = fopen("decodeArticle.txt", "w");         //打开译码文件
    if (decodeFile == NULL) {
        cout<<"decodeAticle.txt文件创建失败!"<<endl;
    } else {
        cout<<"decodeArticle.txt创建成功!"<<endl;
    }

//    fseek(huffmanFile,0,SEEK_SET);
    huffmanFile = fopen("huffmanCode.txt", "r");          //打开huffman编码文件 只读

    char cd;
    string codewords[10000];
    int i = 0;
    string cw = "";
    while((cd = fgetc(huffmanFile)) != EOF){
        if (cd != ' ') {
            cw = cw +cd;                                //以空格为分割 读取huffman进数组
        }else{
            codewords[i] = cw;
            i++;
            cw = "";
            continue;
        }

    }


    for(int i = 0;i<=100;i++){
        for(int j = 1;j<=95;j++){                      //在HC[]huffman编码数组中查询huffman编码 返回下标
            if (HC[j] == codewords[i]) {
                fputc(j+31, decodeFile);               //下标转换为字符写进译码文件
            }
        }
    }

    return 0;

}
