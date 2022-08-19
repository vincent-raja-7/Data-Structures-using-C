void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
     {
        for (j = i; j < num; j++)
          {
             for(k = j - i; k >= 0; k = k - i)
             {
                  if (arr[k+i] >= arr[k])
                      break;
                  else
                  {
                      tmp = arr[k];
                      arr[k] = arr[k+i];
                      arr[k+i] = tmp;
                  }
             }
          }
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
    shellsort(a,n);
    printf("\nAfter Swapping : \n");
    for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
