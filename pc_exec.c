/*
 * Created by Lettle on 2021/10/18.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#include "pc_exec.h"
#include "pc_stack.h"


void exec(pc_code *code)
{
    pc_value *value = (pc_value *) malloc(sizeof (pc_value));
    value->string_value = (char *) malloc(1);
    if (strcmp(code->code,"push") == 0) {
        if (*code->next->code == '\"') {
            value->type = PC_STRING;
//            value->string_value = (char *) realloc(value->string_value,sizeof (code->next->code));
            strcpy(value->string_value,code->next->code);
            stack_push(*value);
        } else if (strcmp(code->next->code,"\n")) {
            value->type = PC_INT;
            value->int_value = atoi(code->next->code);
            stack_push(*value);
        } else {
            printf("err\n");
        }

    } else if (strcmp(code->code,"pop") == 0) {
        stack_pop();
    } else if (strcmp(code->code,"add") == 0) {
        pc_value *a,*b,*result = (pc_value *) malloc(sizeof (pc_value));
        a = stack_pop();
        if(a->type == PC_INT) {
            b = stack_pop();
            if(b && b->type == PC_INT) {
                result->type = PC_INT;
                result->int_value = b->int_value + a->int_value;
                stack_push(*result);
            }

        }
    } else if (strcmp(code->code,"sub") == 0) {
        pc_value *a,*b,*result = (pc_value *) malloc(sizeof (pc_value));
        a = stack_pop();
        if(a->type == PC_INT) {
            b = stack_pop();
            if(b && b->type == PC_INT) {
                result->type = PC_INT;
                result->int_value = b->int_value - a->int_value;
                stack_push(*result);
            }

        }
    } else if (strcmp(code->code,"mul") == 0) {
        pc_value *a,*b,*result = (pc_value *) malloc(sizeof (pc_value));
        a = stack_pop();
        if(a->type == PC_INT) {
            b = stack_pop();
            if(b && b->type == PC_INT) {
                result->type = PC_INT;
                result->int_value = b->int_value * a->int_value;
                stack_push(*result);
            }

        }
    } else if (strcmp(code->code,"div") == 0) {
        pc_value *a,*b,*result = (pc_value *) malloc(sizeof (pc_value));
        a = stack_pop();
        if(a->type == PC_INT) {
            b = stack_pop();
            if(b && b->type == PC_INT) {
                result->type = PC_INT;
                result->int_value = b->int_value / a->int_value;
                stack_push(*result);
            }

        }
    } else if (strcmp(code->code,"exit") == 0) {
        exit(atoi(code->next->code));
    }

}