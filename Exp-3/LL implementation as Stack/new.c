#include "main.c"
#include <stdlib.h>

void main()
{

int n,i,p;
while(1)
{
    printf("\n\t\tMenu\n\n1.Create\n2.Push\n3.Pop\n4.Display\n5.Exit\nEnter your choice:");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            {
            create();
            break;
            }
        case 2:
            {
            printf("\nEnter the element:");
            scanf("%d",&i);
            push(i);
            break;
            }
        case 3:
            {
            pop();
            break;
            }
        case 4:
            display();
            break;
        case 5:
            exit(0);
    }
}
}
