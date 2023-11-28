#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int issym(char b)
{
    char s[] = {',', '(', ')', ';', '{', '}', '%', '&', '[', ']', '#', '.'};
    int k = 0;
    for (k = 0; k < 12; k++)
        if (s[k] == b)
        {
            return 1;
            break;
        }
    return 0;
}

int isop(char b)
{
    char s[] = {'=', '+', '-', '>', '<', '*', '/'};
    int k = 0;
    for (k = 0; k < 7; k++)
        if (s[k] == b)
        {
            return 1;
            break;
        }
    return 0;
}

void main()
{
    int i, j, f, n = 0, flag = 0;
    char c, t[1000][100], tt[100][30];
    char nn[20][30];
    strcpy(nn[0], "for");
    strcpy(nn[1], "int");
    strcpy(nn[2], "void");
    strcpy(nn[3], "main");
    strcpy(nn[4], "printf");
    strcpy(nn[5], "scanf");
    strcpy(nn[6], "char");
    strcpy(nn[7], "include");
    FILE *fp;
    fp = fopen("lexText.c", "r");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    c = fgetc(fp);
    while (c != EOF)
    {
        // printf("%c", c);
        // isalpha
        if (isalnum(c))
        {
            t[i][j] = c;
            j++;
        }
        else
        {
            t[i++][j] = '\0';
            j = 0;
            if (issym(c) == 1)
            {
                t[i][j] = c;
                t[i][++j] = '\0';
                j = 0;
                strcpy(tt[i], "Special Symbol");
                i++;
            }
            if (isop(c) == 1)
            {
                t[i][j] = c;
                t[i][++j] = '\0';
                j = 0;
                strcpy(tt[i], "Operator");
                i++;
            }
            if (c == '"')
            {
                t[i][j] = c;
                c = fgetc(fp);
                do
                {
                    t[i][++j] = c;
                    c = fgetc(fp);
                } while (c != '"');
                t[i][++j] = c;
                t[i][++j] = '\0';
                j = 0;
                strcpy(tt[i], "String");
                i++;
            }
            if ((c == ' ') || (c == '\n'))
            {
                t[i][j] = '\0';
                j = 0;
                i++;
            }
        }
        c = fgetc(fp);
    }

    for (n = 0; n <= i; n++)
    {
        if (t[n][0] != '\0')
        {
            printf("%s\tis an\t", t[n]);
            for (f = 0; f < 8; f++)
            {
                if (strcmp(nn[f], t[n]) == 0)
                {
                    printf("Keyword \n");
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                if (isalpha(t[n][0]))
                    printf("Identifier \n");
                else if (isdigit(t[n][0]))
                    printf("Constant \n");
            }
            if ((issym(t[n][0]) == 1) || (isop(t[n][0]) == 1))
                printf("%s \n", tt[n]);
            if (t[n][0] == '"')
                printf("%s\n", tt[n]);
        }
        flag = 0;
    }
}