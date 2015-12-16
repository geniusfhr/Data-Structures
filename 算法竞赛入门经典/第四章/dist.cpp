/*
*第四章 函数和递归 计算距离
*
*double dist()
*
*/

#include <stdio.h>
#include <math.h>

typedef struct {        // define the Struct of Point
    double x;           // x filed
    double y;           // y filed
}Point;


//函数声明
double dist(double x1,double y1,double x2,double y2);
double my_dist(Point a,Point b );



//计算两点间的距离
double dist(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}


//Point结构体作为参数 可读性更强
double my_dist(Point a,Point b ){
    double t = pow(a.x - b.x,2) + pow(a.y - b.y,2);
    return sqrt(t);
}


int main(){
    double x1,x2,y1,y2;
    printf("hello,please input x1,x2,y1,y2\n");
    scanf("%lf%lf%lf%lf",&x1,&x2,&y1,&y2);
    printf("您输入的两点之间的长度是%.5f\n",dist(x1,x2,y1,y2));

    Point a = {.x = 12,.y = 12};            //结构体变量的初始化 initialize
    Point b = {.x = 10,.y = 10};
    printf("两点之间的长度是%.5f\n",my_dist(a,b));

    return 0;
}
