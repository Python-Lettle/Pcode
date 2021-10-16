/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#include "pc_screen.h"
#include <stdio.h>

//   Code                  | Stack          | Bind var
// ->push a                | /              | <- a

void show(Pcode *pcode)
{
    printf("  Code                | Stack          | Bind var\n");
    printf("%-2s%-20s| %-15s| %-2s %-s\n","->","push a","/","<-","a");
}

void showCode(pc_code *code)
{
    printf("%s\n", code->code);
    if(code)
        showCode(code->next);
}