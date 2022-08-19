#include <stdio.h>
#include <stdlib.h>
struct node
{
 int elem;
 struct node *next;
};
struct node *start;
int cap=5;
int rear=-1;
int front=0;
int count=0;
void create()
{
start=malloc(sizeof(struct node));
start->elem=0;
start->next=NULL;
}

void Enqueue(int x)
{
    struct node *temp,*ptr;
    temp=malloc(sizeof(struct node));
    temp->elem=x;
    temp->next=NULL;
    ptr=start;
    if(count<cap)
    {
    count++;
    rear++;
    while((ptr->next!=NULL))
          ptr=ptr->next;
    temp->next=ptr->next;
    ptr->next=temp;
    }
    else
    printf("Queue IS FULL");
}
void Dequeue()
{
   struct node *temp,*ptr;
   ptr=start;
   int i;
   if(count==0)
      printf("Queue is Empty");
   else
   {
       printf("Deleted Element : %d",ptr->next->elem);
       temp=ptr->next;
       ptr->next=temp->next;
       free(temp);
       front++;
       count--;
    }
}
void display()
{
struct node *ptr;
int i;
if(count==0)
    printf("Queue is Empty");
else
{
    ptr=start->next;
printf("The Queue is : \n");
while((ptr!=NULL))
  {
    printf("%d\n",ptr->elem);
    ptr=ptr->next;
  }
 }
}
