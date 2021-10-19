/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef PCODE_PC_LEXER_H
#define PCODE_PC_LEXER_H

#include "pc_code.h"
#include "pcode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LEN 10
pc_code * lex(FILE * fpin);

#endif //PCODE_PC_LEXER_H
