#include <stdio.h>
#include <stdlib.h>
struct node
{
 int elem;
 struct node *next;
};
struct node *start;
int cap=5;
int count=0;
void create()
{
start=malloc(sizeof(struct node));
start->elem=0;
start->next=NULL;
}

void append(int x)
{
    struct node *temp,*ptr;
    temp=malloc(sizeof(struct node));
    temp->elem=x;
    temp->next=NULL;
    ptr=start;
    if(count<=(cap-1))
    {
    while((ptr->next!=NULL))
          ptr=ptr->next;
    temp->next=ptr->next;
    ptr->next=temp;
    count++;
    }
    else
    printf("LIST IS FULL");
}

int find(int x)
{
  struct node *temp,*ptr;
   ptr=start->next;
   while((ptr!=NULL))
   {
      if(ptr->elem==x)
      {
       return 1;
      }
       ptr=ptr->next;
    }
     return 0;

}
void insert(int x,int l)
{
    int c=1;
    if(count==cap)
        printf("List is Full");
    else
    {
       struct node *temp,*ptr,*t;
    temp=malloc(sizeof(struct node));
    temp->elem=x;
    temp->next=NULL;
    ptr=start;
    while((ptr!=NULL)&&(c<(l)))
    {
       ptr=ptr->next;
       c++;
    }
    t=ptr->next;
    ptr->next=temp;
    temp->next=t;
    count++;
    }
}
void dele(int x)
{
   struct node *temp,*ptr;
   ptr=start;
   int i;
   if(count==0)
      printf("List is Empty");
   else
   {
       if(find(x))
    {
       while(ptr->next!=NULL)
         {
            if(ptr->next->elem==x)
             {
                temp=ptr->next;
                ptr->next=temp->next;
                free(temp);
                count--;
                return;
             }
             ptr=ptr->next;
          }
    }
    else
      printf("Element Not Found");
   }


}
void display()
{
struct node *ptr;
int i;
if(count==0)
    printf("List is Empty");
else
{
    ptr=start->next;
printf("The Elements are : \n");
for(i=1;ptr!=NULL;i++)
    {
      printf("\nELement in postion %d is %d\n",i,ptr->elem);
      ptr=ptr->next;
    }
}
}



