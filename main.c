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
#include "pc_exec.h"
int main(int argc, char *argv[])
{
    // Pcode init
    pcode = (Pcode *) malloc (sizeof(Pcode));
    pcode->code_line = 0;

    FILE *fp = fopen(argv[1], "r");
    if(fp)
        pcCode = lex(fp);
    else {
        fp = fopen("test.asm","r");
        pcCode = lex(fp);
    }
    pcode->code = pcCode;

    pcStack = (pc_stack *) malloc (sizeof(pc_stack));
    pcStack->value = (pc_value *) malloc(sizeof(pc_value));
    pcStack->len = 0;
    pcode->stack = pcStack;

    pcVar = (pc_var *) malloc(sizeof(pc_var));
    pcode->var_table = pcVar;
//    pc_func_table *pcFuncTable;
//    pc_lable_table *pcLableTable;

    pcode->eip = 1;

    show(pcode);

    unsigned short i;
    char cmd = '\0';
    pc_value value; value.type=PC_STRING; value.string_value="Hello";
    pc_code * code_temp = pcode->code;
    for(i=0;i<pcode->code_line;i++) {
//        printf("\r");
        scanf("%c", &cmd);
        scanf("%c", &cmd);
        pcode->eip++;

//        if(i==0) stack_push(value);
//        else if(i==1) stack_pop();
        exec(code_temp);
        show(pcode);
        if(i != pcode->code_line-1) while (*code_temp->code != '\n') code_temp = code_temp->next;
        code_temp = code_temp->next;
    }

    return 0;
}