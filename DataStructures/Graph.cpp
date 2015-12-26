/*
*图的邻接矩阵表示
*undirected
*
*/

#include <stdio.h>
#define INFINITY 9999           //无穷大
#define OK 1
#define ERROE 0


typedef int VertexType;         //顶点类型
typedef int EdgeType;           //边类型
typedef int Status;

typedef struct {
    VertexType vex[10];     //顶点数组
    EdgeType arc[10][10];   //邻接矩阵
    int numVerterxes;       //顶点数
    int numEdges;           //边数
}Graph;             //定义图 结构类型


//邻接矩阵的创建
//无向图
Status createGraph(Graph& g){
    printf("图的创建开始~请输入顶点数(Vertex):\n");
    scanf("%d",&g.numVerterxes);
    printf("请输入边数(Edges):\n ");
    scanf("%d",&g.numEdges);
    for(int i = 0; i < numVerterxes; i++){
        for(int j = 0; j <  numVerterxes; j++ ){
            g.arc[i][j] = INFINITY;                     //邻接矩阵的初始化init 各顶点间权为无穷大
        }
    }

    for(int n = 0 ;n < numEdges; n++){
        int i,j,w;
        printf("请输入边(Vi,Vj)的下标以及之间的权值w,Vi与Vi之间w为0:\n");
        scanf("%d%d%d",&i,&j,&w);
        g.arc[i][j] = w;
        g.arc[j][i] = w;           //undirected无向 矩阵对称
    }

    printf("图构造完毕。\n");
    
    return OK;

}
