/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef PCODE_PCODE_H
#define PCODE_PCODE_H

#include "pc_stack.h"
#include "pc_var.h"
#include "pc_code.h"
#include "pc_func_table.h"
#include "pc_lable_table.h"


typedef struct pcode_tag
{
    pc_code * code;                 // 代码区
    int eip;                        // 指令指针
    pc_stack * stack;               // 栈
    pc_var * var_table;             // 变量表
    pc_func_table * func_table;     // 函数表
    pc_lable_table * lable_table;   // 标签表

} Pcode;

#endif //PCODE_PCODE_H
