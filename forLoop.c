#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    char line[100];
    int semicolon = 0, bracket1 = 0, bracket2 = 0, curly1 = 0, curly2 = 0, flag = 0, i, j;
    fp = fopen("testFor.c", "r");
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
            else if (line[j] == ';')
            {
                semicolon++;
            }
        }
        if (strstr(line, "for"))
        {
            flag = 1;
        }
    }
    fclose(fp);
    if (flag == 0)
    {
        printf("no for loop is found\n");
    }
    else
    {
        if (semicolon >= 2 && bracket1 == bracket2 && curly1 == curly2)
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
            if (semicolon < 2)
            {
                printf("missing semicolon\n");
            }
        }
    }
    return 0;
}