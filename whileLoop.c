#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    char line[100];
    int bracket1 = 0, bracket2 = 0, curly1 = 0, curly2 = 0, flag = 0, i, j;
    fp = fopen("testWhile.c", "r");
    if (fp == NULL)
    {
        printf("file cannot be opened \n");
        return 1;
    }
    while (fgets(line, 100, fp) != NULL)
    {
        for (j = 0; line[j] != '\0'; j++)
        {
            if (line[j] == '(')
            {
                bracket1++;
            }
            else if (line[j] == ')')
            {
                bracket2++;
            }
            else if (line[j] == '{')
            {
                curly1++;
            }
            else if (line[j] == '}')
            {
                curly2++;
            }
        }
        if (strstr(line, "while"))
        {
            flag = 1;
        }
    }
    fclose(fp);
    if (flag == 0)
    {
        printf("no while loop is found\n");
    }
    else
    {
        if (bracket1 == bracket2 && curly1 == curly2)
        {
            printf("no syntax error\n");
        }
        else
        {
            if (bracket1 != bracket2)
            {
                printf("mismatched parenthesis \n");
            }
            if (curly1 != curly2)
            {
                printf("mismatched curly brackets \n");
            }
        }
    }
    return 0;
}