/*
*开灯问题
*
*有n盏灯，编号1到n，第一个人把所有的打开，第二个人按下编号倍数为2的灯的开关，开的将被关闭，关的将被打开
*第三个人按下倍数为3.，，，以此类推，一共有k个人 问最后有哪些灯开着，输入n，k，输出开着灯的编号
*样例输入
*7 3
*样例输出
*1 5 6 7
*
*
*memset(a,b,c)  //定义在<string.h> a地址 b初始化值字符 c长度
*/


#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[1000];        //灯状态数组 1表示亮 -1表示暗
    int n,k;            //k个人 n盏灯
    scanf("%d%d",&n,&k);

    for(int i = 0;i<1000;i++){
        a[i] = -1;
    }
    for(int i = 1; i<=k;i++){           //人循环
        for(int j = 1;j<=n; j++){       //灯循环
            if(j % i == 0){
                a[j] = -a[j];
            }
        }
    }
    for(int m = 1;m<=n;m++){            //输出状态为1（亮）的灯
        if(a[m] == 1){
            printf("%d ",m);
        }
    }
    return 0;
}
