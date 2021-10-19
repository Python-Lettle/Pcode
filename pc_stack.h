/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef PCODE_PC_STACK_H
#define PCODE_PC_STACK_H

#include "pc_var.h"
#include <stdlib.h>
typedef struct
{
    pc_value *value;
    unsigned short len;
} pc_stack;

pc_stack *pcStack;

void stack_push(pc_value value);
pc_value *stack_pop();

#endif //PCODE_PC_STACK_H
