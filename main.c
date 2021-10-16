/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */

#include <stdlib.h>
#include <stdio.h>
#include "pcode.h"
#include "pc_screen.h"
#include "pc_lexer.h"
int main()
{
    // Pcode init
    char * codes = ";hahaha\npush a\nexit 0";
    pc_code *pcCode = lex(codes);
    pc_stack *pcStack = (pc_stack *) malloc (sizeof(pc_stack));
    pc_var *pcVar;
    pc_func_table *pcFuncTable;
    pc_lable_table *pcLableTable;

    Pcode * pcode = (Pcode *) malloc (sizeof(Pcode));
    pcode->eip = 0;
    pcode->code = pcCode;

    show(pcode);

    return 0;
}