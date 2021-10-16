/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */

#include "pcode.h"
#include <string.h>
#include <stdlib.h>

char * getStatement(pc_code *code)
{
    pc_code *c = code;
    static char temp [100] = {0};
    char * result;
    while (c)
    {
        if(*c->code != '\n') {
            strcat(temp, c->code);
            strcat(temp, " ");
            c = c->next;
        } else {
            result = (char *) malloc(sizeof (temp));
            strcpy(result, temp);
            memset(temp, '\0', sizeof(temp));
            return result;
        }
    }
    if(temp[0]) {
        result = (char *) malloc(sizeof(temp));
        strcpy(result, temp);
        memset(temp, '\0', sizeof(temp));
        return result;
    }
    return NULL;
}