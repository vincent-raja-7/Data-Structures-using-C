#include <stdio.h>
#include <stdlib.h>
struct node
{
 int elem;
 struct node *next;
};
struct node *start;
int cap=5;
int top=-1;
void create()
{
start=malloc(sizeof(struct node));
start->elem=0;
start->next=NULL;
}

void push(int x)
{
    struct node *temp,*ptr;
    temp=malloc(sizeof(struct node));
    temp->elem=x;
    temp->next=NULL;
    ptr=start;
    if(top<(cap-1))
    {
    top++;
    while((ptr->next!=NULL))
          ptr=ptr->next;
    temp->next=ptr->next;
    ptr->next=temp;
    }
    else
      printf("Stack IS FULL");
}
void pop()
{
   struct node *temp,*ptr;
   ptr=start;
   if(top==-1)
      printf("Stack is Empty");
   else
   {
       while((ptr->next->next!=NULL))
          ptr=ptr->next;
       printf("Popped Element : %d",ptr->next->elem);
       temp=ptr->next;
       ptr->next=NULL;
       free(temp);
       top--;
    }
}
void display()
{
struct node *ptr;
int i;
if(top==-1)
    printf("Stack is Empty");
else
{
    ptr=start->next;
printf("The Stack is : \n");
while((ptr!=NULL))
  {
    printf("%d\n",ptr->elem);
    ptr=ptr->next;
  }
}
}
