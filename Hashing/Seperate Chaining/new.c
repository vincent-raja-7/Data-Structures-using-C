#include <stdio.h>
struct node
{
   int key;
   struct node *next;
}a[10];
int s[10];
void init()
{
   int i=0;
   for(i=0;i<10;i++)
     s[i]=0;
}
void insert(int k)
{
   int index;
   index=k%10;
   struct node *ptr=a;
   ptr=ptr+index;
   struct node *temp=malloc(sizeof (struct node));
   temp->key=k;
   temp->next=NULL;
   while(ptr->next!=NULL)
     ptr=ptr->next;
   ptr->next=temp;
   s[index]++;
}
int search(int k)
{
   int index,c=0;
   index=k%10;
   if(s[index]>0)
   {
      struct node *ptr=a;
      ptr=ptr+index;
   while(ptr!=NULL)
   {
      if(ptr->key==k)
      {
        return 1;
        break;
      }
      ptr=ptr->next;
   }
   if(c==0)
      return 0;
      printf("Element Not Found");
   }
   else
     return 0;
}
void dele(int k)
{
    int index,c=0;
   index=k%10;
   struct node *temp;
   if(search(k))
   {
       if(s[index]>0)
   {
      struct node *ptr=a;
      ptr=ptr+index;
   while(ptr->next!=NULL)
         {
            if(ptr->next->key==k)
             {
                temp=ptr->next;
                ptr->next=temp->next;
                free(temp);
                s[index]--;
                return;
             }
             ptr=ptr->next;
        }
    }
   }
   else
      printf("No Such Element");
}
void display()
{
   int i;
   struct node *ptr=a,*ptr2;
   printf("\nThe Hash Table : \n");
   printf("Index\tValue\n");
   for(i=0;i<10;i++)
     {
        ptr2=ptr+i;
        printf("%d\t",i);
        if(s[i]>0)
        {
           //ptr=ptr->next;
          // printf("%d",ptr->next->key);
           while(ptr2->next!=NULL)
           {
               printf("-> %d",ptr2->next->key);
               ptr2=ptr2->next;
           }


            }
        else
          printf("NULL");
       printf("\n");
    }
}
void main()
{
    int n,i,p;
    init();
    while(1)
   {
    printf("\n\t\tMenu\n\n1.Insert\n2.Delete\n3.Display\n4.Find\n5.Exit\nEnter your choice:");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            {
            printf("Enter the element:");
            scanf("%d",&i);
            insert(i);
            break;
            }
        case 2:
            {
            printf("\nEnter the element:");
            scanf("%d",&i);
            dele(i);
            break;
            }
        case 3:
            {
            display();
            break;
            }
        case 4:
            {
                printf("\nEnter the element:");
                scanf("%d",&i);
                int f=search(i);
                if(f)
                    printf("Element Found");
                else
                    printf("Element Not Found");
                break;
            }
        case 5:
            exit(0);
    }
  }
}
