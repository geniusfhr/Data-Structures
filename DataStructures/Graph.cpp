/*
 *
 *BinaryInsertionSort.cpp
 *折半查找排序
 * 从小到大
 */


#include <stdio.h>
#include <queue>

#define INFINITY 9999           //无穷大
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int VertexType;         //顶点类型
typedef int EdgeType;           //边类型
typedef int Status;

typedef struct {
    VertexType vex[10];     //顶点数组
    EdgeType arc[10][10];   //邻接矩阵
    int numVerterxes;       //顶点数
    int numEdges;           //边数
}Graph;             //定义图 结构类型

/**********************************************************************/
typedef struct {         //Queue结构体
    int data[MAXSIZE];          //数据域
    int currentSize;           //当前长度
}MyQueue;

Status initQueue(MyQueue& Q){             //初始化队列
    for(int i = 0;i < MAXSIZE; i++){
        Q.data[i] = 0;              //数据置0
    }
    Q.currentSize = 0;              //当前长度置空
    return OK;
}

int is_empty(MyQueue Q){              //判空
    if(Q.currentSize == 0){
        return 1;
    } else {
        return 0;
    }
}


//将e入列Q
Status Enqueue(MyQueue& Q,int e){
    Q.data[Q.currentSize] = e;  //入列
    Q.currentSize++;              //长度增加
    return OK;
}

//出列 以e返回
Status Dequeue(MyQueue& Q,int& e){
    if(Q.currentSize == 0){
        printf("队中无元素，出列失败!\n");
        return ERROR;
    }
    e = Q.data[0];    //e返回
    for(int i = 1;i < Q.currentSize; i++){
        Q.data[i-1] = Q.data[i];     //往前挪
    }
    Q.currentSize--;                  //长度减一
    return OK;
}

/*********************************************************************/

//邻接矩阵的创建
//无向图
Status create_graph(Graph& g){
    printf("图的创建开始~请输入顶点数(Vertex):\n");
    scanf("%d",&g.numVerterxes);
    printf("请输入边数(Edges):\n");
    scanf("%d",&g.numEdges);
    for(int i = 0; i < g.numVerterxes; i++){
        for(int j = 0; j <  g.numVerterxes; j++ ){
            g.arc[i][j] = 0;                     //矩阵初始化为 0
        }
    }

    printf("请输入顶点信息:\n");
    for(int i = 0;i< g.numVerterxes;i++){
        scanf("%d",&g.vex[i]);
    }

    for(int n = 0 ;n < g.numEdges; n++){
        int i,j;
        printf("请输入边(Vi,Vj)的下标:\n");
        scanf("%d%d",&i,&j);
        g.arc[i][j] = 1;
        g.arc[j][i] = 1;           //undirected无向 矩阵对称
    }

    for(int i = 0; i < g.numVerterxes;i++){
        g.arc[i][i] = 0;            //主对称轴为0
    }

    printf("图构造完毕,邻接矩阵如下所示:\n");
    for(int i = 0; i < g.numVerterxes;i++){
        for(int j = 0; j <  g.numVerterxes;j++){
            printf("%d ",g.arc[i][j]);
        }
        printf("\n");
    }
    return OK;

}


//深度优先搜索算法
// depth first search

int visited[10];    //visited[]  访问标志数组 如果i被访问 i 否则为 0

Status depth_first_search(Graph g,int i ){        //对顶点i进行深度优先搜索
    printf("%d ",g.vex[i]);         //访问
    visited[i] = 1;
    for(int j = 0; j < g.numVerterxes; j++){
        if(g.arc[i][j] == 1 && !visited[j]){
            depth_first_search(g,j);                   //递归 对当前结点进行DFS
        }
    }
    return OK;
}


Status DFSTraversal(Graph g){
    //int visited[g.numVerterxes];        //1表示已访问 0未被访问
    for(int i = 0;i < g.numVerterxes; i++){
        visited[i] = 0 ;            //访问数组全置为0  标记为未访问
    }

    for(int k = 0;k < g.numVerterxes; k++){     //横向
        if(!visited[k]){
            depth_first_search(g,k);           //对所有未被访问顶点进行DFS深度优先搜索
        }
    }//若连通图只进行一次
    return OK;
}


Status breadth_first_search(Graph& g){
    MyQueue Q;
    initQueue(Q);
    for(int i = 0;i < g.numVerterxes; i++){
        visited[i] = 0;              // 访问标志数组置0
    }
    for(int i = 0;i < g.numVerterxes; i++){     //横向 对所有顶点进行BFS广度优先搜索
        if(!visited[i]){
            Enqueue(Q,i);
            printf("%d ",g.vex[i]);     //访问
            visited[i] = 1;

            while(!is_empty(Q)){
                int t;
                Dequeue(Q,t);
                for(int j = 0; j < g.numVerterxes; j++){            //搜索邻接点
                    if(g.arc[t][j] == 1 && !visited[j]){            //未被访问到
                        Enqueue(Q,j);                   //入列
                        printf("%d ",g.vex[j]);         //访问
                        visited[j] = 1;                 //标志已被访问
                    }
                }
            }
        }
    }
    return OK;
}


int main(){
    Graph g;
    create_graph(g);
    printf("深度优先搜索如下:\n");
    DFSTraversal(g);
    printf("\n广度优先搜索如下:\n");
    breadth_first_search(g);
    return 0;
}




//main func
int main(){
    Graph g;
    create_graph(g);
    DFSTraversal(g);
    return 0;
}
