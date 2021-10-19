/*
 * Created by Lettle on 2021/10/16.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#include "pc_lexer.h"

pc_code * lex(FILE * fpin)
{
    char flag = 0;
    short i=0;
    char token[MAX_TOKEN_LEN];
    char ch = fgetc(fpin);
    pc_code *pc = (pc_code *) malloc (sizeof(pc_code));
    pc_code *result = pc;
    while (ch != EOF)
    {
        // ; 注释
        if (flag){
            if(ch=='\n' || ch=='\r')
                flag = 0;
            ch = fgetc(fpin);
            continue;
        }

        if (ch == ';'){
            flag = 1;
            ch = fgetc(fpin);
            continue;
        }

        // token 链表获取
        if (ch != '\n' && ch != '\r' && ch != ' ') {
            token[i++] = ch;
        } else if (ch == '\r' || ch == '\n' && *token) {
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
            pcode->code_line++;
        } else if(ch != '\n'){
            pc->code = (char *) malloc (strlen(token));
            strcpy(pc->code, token);
            memset(token, '\0', sizeof (token));
            i = 0;
            pc->next = (pc_code *) malloc (sizeof(pc_code));
            pc = pc->next;
        }

        ch = fgetc(fpin);
    }pc->code = (char *) malloc (strlen(token));strcpy(pc->code, token); pcode->code_line++;

    return result;
}