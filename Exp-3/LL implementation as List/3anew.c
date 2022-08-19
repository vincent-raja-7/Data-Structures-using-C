#include "3amain.c"
#include <stdlib.h>

void main()
{

int n,i,p;
while(1)
{
    printf("\n\t\tMenu\n\n1.Create\n2.Append\n3.Insert\n4.Delete\n5.Find\n6.Display\n7.Exit\nEnter your choice:");
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
            append(i);
            break;
            }
        case 3:
            {
            printf("\nEnter the element:");
            scanf("%d",&i);
            printf("\nEnter the position :");
            scanf("%d",&p);
            insert(i,p);
            break;
            }
        case 4:
            printf("\nEnter the element:");
            scanf("%d",&i);
            dele(i);
            break;
        case 5:
            printf("\nEnter the element:");
            scanf("%d",&i);
            if(find(i))
                printf("Element Located");
            else
                printf("Element Not Found");
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
    }
}
}
