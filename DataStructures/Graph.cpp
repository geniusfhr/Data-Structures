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
Status create_graph(Graph& g){
    printf("图的创建开始~请输入顶点数(Vertex):\n");
    scanf("%d",&g.numVerterxes);
    printf("请输入边数(Edges):\n ");
    scanf("%d",&g.numEdges);
    for(int i = 0; i < g.numVerterxes; i++){
        for(int j = 0; j <  g.numVerterxes; j++ ){
            g.arc[i][j] = 0;                     //矩阵初始化为 0
        }
    }

    printf("请输入顶点信息");
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

Status DFS(Graph g,int i ){        //对顶点i进行深度优先搜索
    printf("%d ",g.vex[i]);         //访问
    visited[i] = 1;
    for(int j = 0; j < g.numVerterxes; j++){
        if(g.arc[i][j] == 1 && !visited[j]){
            DFS(g,j);                   //递归 对当前结点进行DFS
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
            DFS(g,k);           //对所有未被访问顶点进行DFS深度优先搜索
        }
    }//若连通图只进行一次
    return OK;
}


//main func
int main(){
    Graph g;
    create_graph(g);
    DFSTraversal(g);
    return 0;
}
