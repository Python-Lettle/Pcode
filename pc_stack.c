/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#include "pc_stack.h"

void stack_push(pc_value value)
{
    pcStack->len++;
    pcStack->value = (pc_value*) realloc(pcStack->value,sizeof(pc_value) * pcStack->len);
    pcStack->value[pcStack->len-1] = value;
}

pc_value *stack_pop()
{
    return pcStack->len?&pcStack->value[--pcStack->len]:NULL;
}

