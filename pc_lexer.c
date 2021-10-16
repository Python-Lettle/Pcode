/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#include "pc_lexer.h"
#include <stdlib.h>
#include <string.h>
pc_code * lex(const char * code)
{
    char flag = 0;
    short i=0, j=0;
    char token[MAX_TOKEN_LEN];
    char ch[strlen(code)];
    strcpy(ch, code);
    pc_code *pc = (pc_code *) malloc (sizeof(pc_code));
    pc_code *result = pc;
    while (ch[j])
    {
        // ; 注释
        if (flag){
            if(ch[j]=='\n')
                flag = 0;
            j++;
            continue;
        }

        if (ch[j] == ';'){
            flag = 1; j++;
            continue;
        }

        // token 链表获取
        if (ch[j] != '\n' && ch[j] != ' ') {
            token[i++] = ch[j];
        } else if (ch[j] == '\n') {
            pc->code = (char *) malloc (strlen(token));
            strcpy(pc->code, token);
            memset(token, '\0', sizeof (token));
            i = 0;
            pc->next = (pc_code *) malloc (sizeof(pc_code));
            pc = pc->next;

            pc->code = (char *) malloc (strlen(token));
            strcpy(pc->code, "\n");
            pc->next = (pc_code *) malloc (sizeof(pc_code));
            pc = pc->next;
        } else {
            pc->code = (char *) malloc (strlen(token));
            strcpy(pc->code, token);
            memset(token, '\0', sizeof (token));
            i = 0;
            pc->next = (pc_code *) malloc (sizeof(pc_code));
            pc = pc->next;
        }

        j++;
    }pc->code = (char *) malloc (strlen(token));strcpy(pc->code, token);

    return result;
}