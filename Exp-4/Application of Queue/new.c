#include "main.c"
#include <stdlib.h>
void main()
{
int n,i,p;
while(1)
{
    printf("\n\t\tMenu\n\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Exit\nEnter your choice:");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            {
            insert_front();
            break;
            }
        case 2:
            {
            insert_rear();
            break;
            }
        case 3:
            {
            delete_front();
            break;
            }
        case 4:
           delete_rear();
            break;
        case 5:
            exit(0);
    }
}
}
