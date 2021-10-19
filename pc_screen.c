/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#include "pc_screen.h"
#include <stdio.h>
#include <string.h>

//   Code                  | Stack          | Bind var
// ->push a                | /              | <- a

void show(Pcode *pcode)
{
    system("clear");
    short i=0;                                // 输出行数
    pc_code *c = pcode->code;
    printf("  Code                | Stack          | Bind var\n");
    char statement[100] = {0};
    while (c->next) {
        strcpy(statement, getStatement(c));                         // 获取语句
        if(*statement) {
            i++;

            // 要显示的数据
            char stat_p[3] = {0};                                   // 语句指针
            char stack_p[3] = {0};                                  // 栈指针
            pc_value stack_value; stack_value.string_value = " ";   // 栈
            stack_value.type = PC_NONE;

            // 判断是否有语句指针
            if(i == pcode->eip)     strcpy(stat_p, "->");
            else                    memset(stat_p, '\0',sizeof stat_p);
            // 判断有无栈值
            if(!pcode->stack->len) {
                stack_value.string_value = "";
                stack_value.type = PC_NONE;
            }
            else if(i <= pcode->stack->len)
                if(pcode->stack->value) {
                    stack_value = pcode->stack->value[i-1];
                }

            // 判断栈指针位置
            if(i == pcode->stack->len+1)    strcpy(stack_p ,"<-");
            else                            memset(stack_p,'\0',sizeof stack_p);

            if(stack_value.type==PC_NONE || stack_value.type==PC_STRING)
                printf("%-2s%-20s| %-15s| %-2s %-s\n",stat_p, statement,stack_value.string_value, stack_p,"");
            else
                printf("%-2s%-20s| %-15d| %-2s %-s\n",stat_p, statement,stack_value.int_value,stack_p,"");

            memset(statement, '\0',sizeof statement);           // 语句清空
            stack_value.string_value = " ";                        // 栈值清空
            stack_value.type = PC_NONE;
        }
        while (c && *c->code != '\n') c = c->next;
        if(c) c = c->next;
        else break;
    }
    printf("---------------------------------------------------\n");
}

void showCode(pc_code *code)
{
    printf(" %s", code->code);
    if(code->next)
        showCode(code->next);
}