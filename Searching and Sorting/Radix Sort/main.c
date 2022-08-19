#include <stdio.h>
int largest(int a[], int n)
{
    int large = a[0], i;
    for(i=1;i<n;i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}
void RadixSort(int a[], int n)
{
    int bucket[10][10], bucket_count[10];
    int i,j,k,remainder,NOP=0,divisor=1,large, pass;
    large = largest(a, n);
    while(large > 0)
    {
        NOP++;
        large/=10;
    }
    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 10; i++)
            bucket_count[i] = 0;
        for(i = 0; i < n; i++)
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }
        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}

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
   RadixSort(a,n);
   printf("\nAfter Swapping : \n");
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
