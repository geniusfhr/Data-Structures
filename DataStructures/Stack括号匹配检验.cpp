// 括号的匹配



//头文件
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define OK 1;
#define ERROR 0;



//类型定义
typedef  int status;
typedef struct Stack{
    char bracket[20];               //括号栈
    int top = 0;                    //栈顶指针
}Stack;



status push(Stack &s,char c) {              //入栈 push

    if (s.top == 20){
        printf("数据已溢出！\n");
        exit(1);
    }

    s.bracket[s.top] = c;
    s.top++;
    return OK;

}

status pop(Stack &s,char &c) {                //pop 出栈

    if (s.top == 0) {
        printf("栈已清空！无法pop！\n");
        exit(1);
    }
    c = s.bracket[s.top-1];
    s.top--;

    return OK;
}


status checkBrackets(Stack &s,char c){              //检查匹配

    if ((c == '{')||(c == '(')||(c == '[')) {
        push(s, c);
    }
    else if ( c == '}' ||(c == ')')||(c == ']')) {
        char t;
        pop(s,t);
        if (!(((c == ')')&&(t == '('))
            ||((c == '}')&&(t == '{'))
            ||((c == ']')&&(t == '[')))) {

            printf("括号不匹配！\n");
            exit(1);
        }

    } else {
        printf("输入非法字符！\n");
        exit(1);
    }


    return OK;
}


status getBrackets(Stack &s){                       //用户输入

    printf("请输入需要检查的括号字符序列：");
    char c ;
    while (true) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        checkBrackets(s,c);

    }

    if (s.top == 0) {
        printf("括号匹配正确！\n");
    }

    return OK;
}


int main(){

    Stack s;
    getBrackets(s);
}
