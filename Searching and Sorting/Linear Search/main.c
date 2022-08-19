#include <stdio.h>
void main()
{
   int n,i,f,c=0;
   printf("Enter The Number of Elements : ");
   scanf("%d",&n);
   printf("Enter The ELements : \n");
   int a[n];
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   printf("Enter The ELement to be searched : \n");
   scanf("%d",&f);
   for(i=0;i<n;i++)
      if(a[i]==f)
      {
          printf("Element found in the position %d",i+1);
          c++;
          break;
       }
    if(c==0)
      printf("Element not found");
}
