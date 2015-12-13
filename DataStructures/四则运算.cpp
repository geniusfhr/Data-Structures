//计算四则运算表达式的值
//假设输入的表达式只可能存在括号匹配问题，无其他语法错误。
//支持两位数运算
//暂不支持浮点运算


//*******************************************************//
//头文件

#include<stdio.h>
#include<iostream>
#include<string>
#define OK 1;
#define ERROE 0;
using namespace std;

//数据类型定义

typedef int Status;;

typedef struct{
    char oprt[20];       //操作符数组
    int top ;            //栈顶指针

}OprtStack;             //操作符栈


typedef struct {
    int opnd[20];       //数组域
    int top ;            //栈顶指针
}OpndStack;             //操作数栈


//**********************************************************
//操作符栈的pop和push


//OprtStack栈 pop
Status pop(OprtStack &s,char &c){
    if (s.top == 0) {
        printf("括号不匹配！\n");
        exit(1);
    }

    c = s.oprt[s.top-1];
    s.top--;
    return OK;

}


//OprtStack栈的push
Status push(OprtStack &s,char c){
    if (s.top == 19) {
        printf("括号不匹配！\n");
        exit(1);
    }

    s.oprt[s.top] = c;
    s.top++;

    return OK;
}



//**********************************************************
//操作数栈的pop和push

//opndStack栈的pop 出栈
Status pop(OpndStack &s,int &i){
    if (s.top == 0) {
        printf("括号不匹配！\n");
        exit(1);
    }

    i = s.opnd[s.top-1];
    s.top--;
    return OK;

}


//opndStack 的push 入栈
Status push(OpndStack &s,int i){
    if (s.top == 19) {
        printf("括号不匹配！\n");
        exit(1);
    }

    s.opnd[s.top] = i;
    s.top++;

    return OK;
}


//操作符优先级的比较
char operatorCompare(char o1 ,char o2){
    char result = ' ';
    if ((o1 == '+')||(o1 == '-')) {
        switch (o2) {
            case '+':result = '>';break;
            case '-':result = '>';break;
            case '*':result = '<';break;
            case '/':result = '<';break;
            case '(':result = '<';break;
            case ')':result = '>';break;
            case '[':result = '<';break;
            case ']':result = '>';break;
            case '{':result = '<';break;
            case '}':result = '>';break;
            case '#':result = '>';break;

            default:printf("输入非法字符！\n");exit(1);break;
            }
        }
    else if ((o1 == '*')||(o1 == '/')) {
        switch (o2) {
            case '+':result = '>';break;
            case '-':result = '>';break;
            case '*':result = '>';break;
            case '/':result = '>';break;
            case '(':result = '<';break;
            case ')':result = '>';break;
            case '[':result = '<';break;
            case ']':result = '>';break;
            case '{':result = '<';break;
            case '}':result = '>';break;
            case '#':result = '>';break;
            default:printf("输入非法字符！\n");exit(1);break;
            }
        }
    else if (o1 == '('||(o1 =='#')) {
        switch (o2) {
            case '+':result = '<';break;
            case '-':result = '<';break;
            case '*':result = '<';break;
            case '/':result = '<';break;
            case '(':result = '<';break;
            case ')':result = '=';break;
            case '[':result = '<';break;
            case ']':result = '>';break;
            case '{':result = '<';break;
            case '}':result = '>';break;
            case '#':result = '=';break;
            default:printf("输入非法字符！\n");exit(1);break;
        }
    } else if(o1 == ')'){
        switch (o2) {
            case '+':result = '>';break;
            case '-':result = '>';break;
            case '*':result = '>';break;
            case '/':result = '>';break;
            case '(':result = '>';break;
            case ')':result = '>';break;
            case '[':result = '>';break;
            case ']':result = '>';break;
            case '{':result = '>';break;
            case '}':result = '>';break;
            case '#':result = '>';break;
            default:printf("输入非法字符！\n");exit(1);break;
        }

    }

    return result;
}


//判断当前字符是否为运算符
int isOpnd(char c){

    if ((c == '+')||(c == '-')||(c == '*')||(c == '/')||(c == '(')||(c == ')')||(c == '{')||(c == '}')||(c == '[')||(c == ']')||(c == '#')) {
        return 0;
    }
    else return 1;

}

//表达式求值函数
Status caculate(){
    char c[20];
    OpndStack opndStack ;
    opndStack.top = 0;
    OprtStack oprtStack ;
    oprtStack.top = 0;

    OprtStack brackets;         //建立括号栈  用于判断括号是否匹配
    brackets.top = 0;

    push(oprtStack, '#');       //将栈底压入'#'字符作为表达式的开头
    printf("请输入需要计算的表达式,加'#'字符后按回车键结束.\n");
    scanf("%s",c);
    int i ;
    for (i = 0; c[i] != '#'; i++) {

        if ((c[i] == '{')||(c[i] == '(')||(c[i] == '[')) {              //
            push(brackets, c[i]);                                       //将左括号入栈
        }
        if ((c[i] == '}') ||(c[i] == ')')||(c[i] == ']')){
            char t ;
            pop(brackets, t);                                           //与栈顶元素比较是否匹配
            if (!(((c[i] == ')')&&(t == '('))
                  ||((c[i] == '}')&&(t == '{'))
                  ||((c[i] == ']')&&(t == '[')))) {

                printf("括号不匹配！\n");
                exit(1);
            }
        }
    }

    i = 0;

    while (c[i] != '#' || oprtStack.oprt[oprtStack.top-1] != '#') {         //遍历表达式 非##相遇时进入循环
        if (isOpnd(c[i])) {                                                 //当前字符是运算数
            char tt = c[i];
            i++;
            int temp;
            if (isOpnd(c[i])) {                                             //后一字符同为运算数
                 temp = ( (tt - '0')*10 +(c[i] -'0'));                      //组成两位数
                 i++;//
            }else{
                temp = tt- '0';

            }
            push(opndStack, temp);                                          //运算数入栈
//            printf("abc");

        }
        else{                                                                   //当前字符为运算符
            switch (operatorCompare(oprtStack.oprt[oprtStack.top-1], c[i])) {   //比较栈顶运算符与当前运算符优先级
                case '>':{                                  //栈顶元素优先级高 进行运算
                    char t;
                    int a,b;
                    pop(oprtStack, t);                                          //弹出运算符栈顶元素
                    pop(opndStack, b);                                          //连续弹出两个运算数
                    pop(opndStack, a);
                    int result;
                    switch (t) {
                        case '+':
                            result = a + b;
//                            printf("shisai");
                            break;
                        case '-':
                            result = a - b;
                            break;
                        case '*':
                            result = a * b;
                            break;
                        case '/':
                            result = a / b;
                            break;
                        default:
                            printf("表达式有误！\n");
                            exit(1);
                            break;
                    }

                    push(opndStack, result);                                    //运算结果入栈
                    break;
                }
                case '<':                                                       //栈顶元素优先级低
                    push(oprtStack, c[i]);                                      //当前元素压入栈
                    i++;                                                        //i数组下标指向下一字符
                    break;
                case '=':                                                       //优先级相等
                    char x;
                    pop(oprtStack, x);                                          //为（）括号相遇 弹出栈顶括号 消去括号
                    i++;                                                       //读下一个字符
                    break;
            }
        }
    }

        printf("运算结果是：%d\n",opndStack.opnd[opndStack.top-1]);           //##相遇 循环结束运算数栈栈顶元素为运算结果
        return OK;
}



int main()
{
    caculate();
}
