#include"main.c"
void main()
{
   int c,d;
   char ch;
   create();
   printf("Enter The Polynomial 1 :");
   do
   {
        printf("\nEnter The Coefficient : ");
        scanf("%d",&c);
        printf("Enter The Degree : ");
        scanf("%d",&d);
        createpoly1(d,c);
        printf("Do You Want to Continue(Y/N) : ");
        scanf("%c",&ch);
        scanf("%c",&ch);
   }while(ch!='n');
   printf("Enter The Polynomial 2 :");
   do
   {
        printf("\nEnter The Coefficient : ");
        scanf("%d",&c);
        printf("Enter The Degree : ");
        scanf("%d",&d);
        createpoly2(d,c);
        printf("Do You Want to Continue(Y/N) : ");
        scanf("%c",&ch);
        scanf("%c",&ch);
   }while(ch!='n');
   add();
   display();
}
