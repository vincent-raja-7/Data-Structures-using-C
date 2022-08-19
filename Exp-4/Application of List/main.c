#include <stdio.h>
#include <stdlib.h>
struct poly
{
 int coef;
 int degree;
 struct node *next;
};
struct poly *sl1,*sl2,*sl3;
void create()
{
sl1=malloc(sizeof(struct poly));
sl1->coef=0;
sl1->degree=0;
sl1->next=NULL;
sl2=malloc(sizeof(struct poly));
sl2->coef=0;
sl2->degree=0;
sl2->next=NULL;
sl3=malloc(sizeof(struct poly));
sl3->coef=0;
sl3->degree=0;
sl3->next=NULL;
}
void createpoly1(int d,int c)
{
    struct poly *temp,*ptr;
    ptr=sl1;
    temp=malloc(sizeof(struct poly));
        while(ptr->next!=NULL)
            ptr=ptr->next;
        temp->coef=c;
        temp->degree=d;
        temp->next=NULL;
        ptr->next=temp;
}

void createpoly2(int d,int c)
{
    struct poly *temp,*ptr;
    ptr=sl2;
    temp=malloc(sizeof(struct poly));
    while(ptr->next!=NULL)
            ptr=ptr->next;
        temp->coef=c;
        temp->degree=d;
        temp->next=NULL;
        ptr->next=temp;
    }

void add()
{
   struct poly *ptr1,*ptr2,*ptr3,*temp;
   ptr1=sl1->next;
   ptr2=sl2->next;
   temp=malloc(sizeof(struct poly));
   ptr3=sl3->next;
   while((ptr1->next!=NULL)&&(ptr2->next!=NULL))
   {
        if(ptr1->degree==ptr2->degree)
           {
              ptr3->degree=ptr1->degree;
              ptr3->coef=ptr1->coef+ptr2->coef;
           }
           ptr1=ptr1->next;
           ptr2=ptr2->next;
           ptr3=ptr3->next;
   }
}
void display()
{
    struct poly *ptr;
    ptr=sl1->next;
    printf("\nPolynomial 1: ");
    while(ptr!=NULL)
       {
            printf("%dx^%d + ",ptr->coef,ptr->degree);
            ptr=ptr->next;
        }
    ptr=sl2->next;
    printf("\nPolynomial 2: ");
    while(ptr!=NULL)
       {
            printf("%dx^%d + ",ptr->coef,ptr->degree);
            ptr=ptr->next;
        }
    printf("\nResulatant Polynamial is : ");
    ptr=sl3->next;
    printf("\nPolynomial 2: ");
    while(ptr->next!=NULL)
       {
            printf("%dx^%d + ",ptr->coef,ptr->degree);
            ptr=ptr->next;
        }
}
