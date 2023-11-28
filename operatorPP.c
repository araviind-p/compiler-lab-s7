#include <stdio.h>
#include <string.h>
void push(char x);
char pop();
int value(char x);
char stack[100];
char pre[][6] = {
    // i + * $ ( )
    {' ', '>', '>', '>', ' ', '>'}, // i
    {'<', '>', '<', '>', '<', '>'}, // +
    {'<', '>', '>', '>', '<', '>'}, // *
    {'<', '<', '<', ' ', '<', ' '}, // $
    {'<', '<', '<', ' ', '<', '='}, // (
    {' ', '>', '>', '>', ' ', '>'}  // )
};
char input[100];
int top = 0;
int main()
{
    int i, j, k, l, m;
    char a, b, c;
    stack[0] = '$';
    printf("\nEnter Input String: ");
    scanf("%s", input);
    i = strlen(input);
    input[i] = '$';
    input[i + 1] = '\0';
    j = 0;
    while (1)
    {
        a = stack[top];
        b = input[j];
        c = pre[value(a)][value(b)];
        // printf("%c %c %c\n",a,b,c);
        if (a == '$' && b == '$')
        {
            printf("Accepted :)\n");
            break;
        }
        else if (c == '<' || c == '=')
        {
            push(c);
            push(b);
            j++;
        }
        else if (c == '>')
        {
            while (top != 0 && stack[top] != '<')
            {
                pop();
            }
            if (stack[top] == '<')
                pop();
        }
        else
        {
            printf("Error In Parsing !\n");
            break;
        }
    }
    return 0;
}
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    return stack[top--];
}
int value(char x)
{
    switch (x)
    {
    case 'i':
        return 0;
    case '+':
        return 1;
    case '*':
        return 2;
    case '$':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    default:
        return 0;
        break;
    }
}