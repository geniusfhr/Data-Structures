/*
*输入一行整数 逆序输出
*
*/

#include <stdio.h>
#define max 105
int a[max];

int main(){
    int x,i = 0;    //i表示当前输入的下标
    while(scanf("%d",&x ) == 1 ){       //成功读到整数
        a[i] = x;           //读进a[i]
        i++;                //i后移 即将读进
    }

    for(int j = i-1; j>=0;j--){         //第一个输出的为读取失败的i-1
        printf("%d ",a[j]);
    }
    return 0;
}

/*
#include <stdio.h>
int main(){
    int i = 0;
    while(scanf("%d",a[i++]) != EOF){
            //  出错！！！即将读第1个，Ctrl+D 第一个读进去为EOF  i++  == 2
    }

    for (int j = i-1;j>=0;j--){
        printf("%d ",a[j] );
    }
    return 0;
}
*/
