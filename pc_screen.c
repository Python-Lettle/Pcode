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
    pc_code *c = pcode->code;
    printf("  Code                | Stack          | Bind var\n");
    char statement[100] = {0};
    while (c->next) {
        strcpy(statement, getStatement(c));
        if(*statement) {
            printf("%-2s%-20s| %-15s| %-2s %-s\n","->", statement,"/","<-","a");
            memset(statement, '\0',sizeof statement);
        }
        while (*c->code != '\n') c = c->next;
        c = c->next;
    }
}

void showCode(pc_code *code)
{
    printf(" %s", code->code);
    if(code->next)
        showCode(code->next);
}