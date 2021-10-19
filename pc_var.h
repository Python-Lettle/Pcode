/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef PCODE_PC_VAR_H
#define PCODE_PC_VAR_H

// value 的类型
enum
{
    PC_NONE,
    PC_INT,
    PC_FLOAT,
    PC_STRING
};

typedef struct pc_value_tag
{
    union {
        int int_value;
        char *string_value;
        float float_value;
    };
    unsigned char type;
} pc_value;

typedef struct
{
    unsigned short * var_position;
    unsigned char  * var_name[21];
} pc_var;

pc_var *pcVar;

#endif //PCODE_PC_VAR_H
