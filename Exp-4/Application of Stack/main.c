#include <stdio.h>
#include <stdlib.h>
char stack[20];
char exp[30];
int tops = -1;
void push(char x)
{
    tops++;
    stack[tops] = x;
}

char pop()
{
    if(tops == -1)
        return -1;
    else
        return stack[tops--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
void read()
{
    printf("Enter The Expression : ");
    scanf("%s",exp);
}
void print()
{
    char *e, x;
    e=exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[tops]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(tops != -1)
    {
        printf("%c",pop());
    }
}
