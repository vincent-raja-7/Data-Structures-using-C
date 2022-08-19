#include<stdio.h>
#include<stdlib.h>
int n;
void insert(int a[],int hFn,int size,int element)
{
    int index,n=0;
   // printf("Enter key element to insert\n");
	//scanf("%d",&element);


    while(a[index]!= 0)
    {
		if(a[index]>0)
         {
            index = (index+1);
		    n++;
		    if(n==size)
		       break;
         }

	}
   if(n==size)
        printf("Hash table was full of elements\nNo Place to insert this element\n\n");
	else
        a[index]=element;
}
void main()
{
   int key,i,index;
   char ch;
   int size = 10;
   int a[size];
   for(i=0;i<size;i++)
     a[i]=0;
   do
   {
      printf("Enter The Number : ");
      scanf("%d",&key);
      index = key%10;
      //printf("%d",index);
       if(a[index]==0)
      {
         a[index]=key;
         n++;
      }
      else
            {
                i=index;
                do
                  {
                     if(((index+1)==(size))&&(a[index+1]!=0))
                        index=0;
                     else
                       index=index+1;
                     n++;

                   }while((a[index]!=0)&&(index!=i));
                 if(n==(size-1))
                   break;
                 else
                   a[index]=key;
            }
      printf("Do you want to Continue (Y/N): ");
      scanf("%c",&ch);
      scanf("%c",&ch);
      printf("\n");
   }while(ch=='Y');
   printf("Hash Table : \n");
   printf("Index\tValue\n");
   for(i=0;i<size;i++)
        printf("%d\t%d\n",i,a[i]);
}

