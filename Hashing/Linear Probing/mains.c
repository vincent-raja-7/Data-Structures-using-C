#include<stdlib.h>
#include<stdio.h>
void main()
{
    int size,hFn=10,n,i,j,index,s;
    char ch;
    size=hFn-1;
    int ht[hFn];
    for(i=0;i<=size;i++)
        ht[i]=0;
    do
    {
        printf("Enter The Number : ");
        scanf("%d",&s);
        index=s%hFn;
        if(ht[index]==0)
        {
          ht[index]=s;
          n++;
        }
        else if(n==size)
            printf("\nHash Table is Full");
             else
             {
                 if(index==size)
                 {
                     j=0;
                     while((ht[j]!=0)&&(j!=index))
                         j=j+1;
                     ht[j]=s;
                     n++;
                 }
                 else
                 {
                     while((ht[index]!=0)&&(index<=size))
                        index=index+1;
                     ht[index]=s;
                     n++;
                 }
             }
             printf("Do you want to continue (Y/N):");
             scanf("%c",&ch);
             scanf("%c",&ch);
    }while(ch=='Y');
printf("Hash Table :\n");
printf("Indext\tValue\n");
for(i=0;i<=size;i++)
{
    printf("%d\t%d",i,ht[i]);
    printf("\n");
}
}
