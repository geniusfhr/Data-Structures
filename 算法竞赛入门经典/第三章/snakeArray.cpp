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
    int n,total = 0;            //输入的数组边数
    int x,y;                    //x y表示该点坐标
    scanf("%d",&n);
    memset(a,0,sizeof(a));      //置空
    total = a[x = 0][y = n-1] = 1;
    while(total < n*n){
        while(x+1<n && !a[x+1][y]){
            a[++x][y] = ++total;

        }
        while(y-1>=0 && !a[x][y-1]){
            a[x][--y] = ++total;
        }
        while(x-1>=0 && !a[x-1][y]){
            a[--x][y] = ++total;
        }
        while(y+1<n && !a[x][y+!]){
            a[x][++y] = ++total;
        }
    }

for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        printf("%3d",a[i][j]);
    }
    printf("\n");
}

return 0;






}
