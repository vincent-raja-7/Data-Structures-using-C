#include <stdio.h>
#include <math.h>
int heap[100], n;
void display()
{
    int i,s;
    if (n == 0)
      printf("Heap is empty \n");
    for (i = 1; i <=n; i++)
       printf("%d\t",heap[i]);
    printf("\n");
}
void insert(int p)
{
        n++;
        heap[n] = p;
        int now = n;
        while (heap[now / 2] >p)
         {
            heap[now] = heap[now / 2];
            now /= 2;
          }
        heap[now] = p;
}
int deleteMin()
{
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[n--];
for (now = 1; now * 2 <= n; now = child)
{
child = now * 2;
if (child != n && heap[child + 1] < heap[child])
child++;
if (lastElement > heap[child])
heap[now] = heap[child];
else
break;
}
heap[now] = lastElement;
return minElement;
}
void main()
{
int choice, num;
n = 0;
while(1)
{
    printf("\nMenu : \n");
    printf("1.Insert the element \n");
    printf("2.Delete the element \n");
    printf("3.Display all elements \n");
    printf("4.Quit \n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch(choice)
      {
        case 1:
           printf("Enter the element to be inserted to the list : ");
           scanf("%d", &num);
           insert(num);
           break;
        case 2:
           deleteMin();
           break;
        case 3:
           display();
           break;
        case 4:
          exit(0);
}
}
}




