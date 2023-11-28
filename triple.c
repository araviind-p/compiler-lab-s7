#include <stdio.h>
#include <string.h>
int isop(char x);
int prio(char x);
char stack[100];
int top = -1;
void push(char x);
char pop();
int main()
{
    int i, j, k;
    char a[100], m[100], x, first, second, temp;
    push('$');
    printf("\nEnter The Expression:");
    scanf("%s", a);
    j = strlen(a);
    for (i = 0; i < j; i++)
        if (a[i] == '-' && (i == 0 || isop(a[i - 1])))
            a[i] = '_';
    k = 0;
    for (i = 0; i < j; i++)
    {
        if (isop(a[i]))
        {
            if (top <= 0 || stack[top] == '(' || a[i] == '(')
                push(a[i]);
            else if (a[i] == ')')
            {
                while ((x = pop()) != '(')
                    m[k++] = x;
            }
            else if (prio(a[i]) < prio(stack[top]))
                push(a[i]);
            else
            {
                m[k++] = pop();
                push(a[i]);
            }
        }
        else
            m[k++] = a[i];
    }

    while ((x = pop()) != '$')
        m[k++] = x;
    m[k++] = '\0';
    printf("\nPostfix Form:\n\n");
    puts(m);
    printf("\nPosition\tOperator\targ1\targ2\n");
    int g = 0;
    for (i = 0, x = '0'; m[i] != '\0'; i++)
    {
        if (!isop(m[i]))
            push(m[i]);
        else
        {
            if (m[i] == '_' || m[i] == '=')
                second = '_';
            else
                second = pop();
            first = pop();
            if (m[i] == '_')
            {
                printf("\n%d\t%s\t\t%c\t%c\n", g++, "UMinus", first, second);
                push(x++);
            }

            else
            {
                if (m[i] == '=')
                {
                    temp = pop();
                    printf("%d\t\t%c\t\t%c\t%c\n", g++, m[i], first, second);
                }
                else
                {
                    printf("%d\t\t%c\t\t%c\t%c\n", g++, m[i], first, second);
                    push(x++);
                }
            }
        }
    }
    return 0;
}
int isop(char x)
{
    switch (x)
    {
    case '(':
    case '_':
    case '^':
    case '%':
    case '/':
    case '*':
    case '+':
    case '-':
    case ')':
    case '=':
        return 1;
    default:
        return 0;
    }
}
int prio(char x)
{
    switch (x)
    {
    case '(':
        return 0;
    case '_':
        return 1;

    case '^':
        return 2;
    case '%':
        return 3;
    case '/':
        return 4;
    case '*':
        return 5;
    case '+':
        return 6;
    case '-':
        return 7;
    case ')':
        return 8;
    case '=':
        return 9;
    case '$':
        return 10;
    default:
        return 11;
    }
}

void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if (top >= 0)
        return stack[top--];
    else
        return '$';
}
