#include <stdio.h>
void main()
{
   int n,i,f,c=0,l=0,u,mid;
   printf("Enter The Number of Elements : ");
   scanf("%d",&n);
   printf("Enter The ELements : \n");
   int a[n];
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   printf("Enter The ELement to be searched : \n");
   scanf("%d",&f);
   u=n;
   while(l<u)
   {
       mid=(l+u)/2.0;
       if(a[mid]==f)
         {
             printf("Element found ");
             c++;
             break;
         }
       if(a[mid]>f)
               u=mid-1;
       if(a[mid]<f)
               l=mid+1;
   }
   if(c==0)
      printf("Element not found");
}
