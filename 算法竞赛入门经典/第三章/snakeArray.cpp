/*
*在n*n的数组里填入1 2 。。n*n 要求填成蛇形
*
*
*10  11  12 1
*9   16  13 2
*8   15  14 3
*7   6   5  4
*下左上右
*
*
*/
#include <stdio.h>
#include <string.h>
#define max 20

int a[max][max];
int main(){
    int n;           //输入的数组边数
    int x,y;                    //x y表示该点坐标
    while(scanf("%d",&n) == 1 && n<=10){
    int total = 0;
    memset(a,0,sizeof(a));      //置空
    total = a[x = 0][y = n-1] = 1;
    while(total < n*n){
        while(x+1<n && !a[x+1][y]){         //先把向下的全部走完
            a[++x][y] = ++total;
        }
        while(y-1>=0 && !a[x][y-1]){        //向左走完
            a[x][--y] = ++total;
        }
        while(x-1>=0 && !a[x-1][y]){        //向上走完
            a[--x][y] = ++total;
        }
        while(y+1<n && !a[x][y+1]){         //向右走完
            a[x][++y] = ++total;
        }
    }           //一轮循环过后 检查数是否被填完 否，继续循环 继续向下

for(int i = 0;i<n;i++){                 //输出数组
    for(int j = 0;j<n;j++){
        printf("%3d",a[i][j]);
    }
    printf("\n");
}

printf("\n");
}

return 0;






}
