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
   for (i=0;i<(n-1);i++)
  {
     min=i;
     for(j=i+1;j<n;j++)
    {
         if(a[min]>a[j])
             min=j;
    }
      t=a[i];
      a[i]=a[min];
      a[min]=t;
  }
  printf("\nAfter Swapping : \n");
  for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
