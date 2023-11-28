// language
// (a+b)*abb

#include <stdio.h>
#include <string.h>
int main()
{
    int i, cs = 0;
    char string[30], c;
    printf("Enter any string: ");
    scanf("%s", string);
    for (i = 0; string[i] != '\0'; i++)
    {
        c = string[i];
        switch (cs)
        {
        case 0:
            if (c == 'a')
                cs = 1;
            else if (c == 'b')
                cs = 0;
            else
            {
                printf("not acceptable\n");
                return 0;
            }
            break;

        case 1:
            if (c == 'b')
                cs = 2;
            else if (c == 'a')
                cs = 1;
            else
            {
                printf("not acceptable\n");
                return 0;
            }
            break;

        case 2:
            if (c == 'a')
                cs = 0;
            else if (c == 'b')
                cs = 3;
            else
            {
                printf("not acceptable\n");
                return 0;
            }
            break;

        case 3:
            if (c == 'a')
                cs = 1;
            else if (c == 'b')
                cs = 0;
            else
            {
                printf("not acceptable\n");
                return 0;
            }
            break;
        }
    }
    if (cs == 3)
        printf("string %s is accepted\n", string);
    else
        printf("string %s is not accepted\n", string);
    return 0;
}