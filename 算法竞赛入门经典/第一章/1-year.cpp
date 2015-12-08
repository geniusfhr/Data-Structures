/*
*
*输入年份，判断是否为闰年 ，如果是，输出yes，否则输出no
*闰年定义  普通年 能被4整除  整百年 能被400整除
*/

#include <stdio.h>
int main()
{
    int year;
    scanf("%d",&year );
    if (year % 100 == 0 ) {     //整百年
        if(year % 400 == 0)     //能被400整除
        {
            printf("yes\n" );
        }
        else
        {
            printf("no\n" );
        }
    }
    else//非整百年
    {
        if (year % 4 == 0) {        //能被4整除
            printf("yes\n" );
        }
        else                    //不能被4整除
        {
            printf("no\n" );

        }
    }

//***********************************************//
if(year % 100 != 0 && year % 4 == 0 || year % 400 == 0)     //可以被400整除或普通年可以被4整除
{
    printf("yes\n" );
}
else
{
    printf("no\n" );

}

    return 0;
}
