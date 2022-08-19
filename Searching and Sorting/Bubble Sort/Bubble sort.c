#include <stdio.h>
void main()
{
   int n,i,f,c=0,j,t,min;
   printf("Enter The Number of Elements : ");
   scanf("%d",&n);
   printf("Enter The ELements : \n");
   int a[n];
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   printf("Before Swapping : \n");
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
   for(i=0;i<(n-1);i++)
  {
      for(j=0;j<(n-i)-1;j++)
     {
         if (a[j]>a[j+1])
         {
             t=a[j];
             a[j]=a[j+1];
             a[j+1]=t;
         }
     }
  }
 printf("\nAfter Swapping : \n");
 for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
