/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef PCODE_PC_CODE_H
#define PCODE_PC_CODE_H

typedef struct pc_code_tag
{
    char *code;
    struct pc_code_tag *next;
} pc_code;

pc_code *pcCode;

#endif //PCODE_PC_CODE_H
