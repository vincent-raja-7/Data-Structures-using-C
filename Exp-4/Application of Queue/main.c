# include<stdio.h>
# define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;
void display()
{
    int i;
	if((front == -1)&&(rear==-1))
	{
	    printf("Queue is empty\n");
		return;
    }
	printf("Queue elements : ");
    for(i=front;i<=rear;i++)
       printf("%d ",deque[i]);
}

void insert_rear()
{
	int x;
	if(front == -1 && rear == MAX-1)
	{
	    printf("Queue Overflow\n");
		return;
    }
	else if ((front == -1)&&(rear==-1))
	{
	    front = 0;
		rear = 0;
    }
	else if(rear == MAX-1)
	{
	    printf("Queue Overflow\n");
        return;
	}
    else
        rear++;
	printf("Enter The Data : ");
	scanf("%d", &x);
	deque[rear] = x;
	display();
}
void insert_front()
{	int x;
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
	    printf("Queue Overflow \n");
		return;
    }
	else if ((front == -1)&&(rear==-1))
	{
	    front = 0;
		rear = 0;
    }
	else if(front==0)
	     {
	        printf("Queue Overflow\n");
            return;
          }
	     else
		   front=front-1;
	printf("Enter The Data : ");
	scanf("%d", &x);
	deque[front] = x;
	display();
}
void delete_front()
{	if (front == -1)
	{
	    printf("Queue Underflows\n");
		return ;
    }
	printf("Element Deleted : %d\n",deque[front]);
	if(front == rear)
	{
	    front = -1;
		rear = -1;
    }
		else
			front = front+1;
    display();
}
void delete_rear()
{
   if (front == -1)
	{
	    printf("Queue Underflows\n");
		return ;
    }
	printf("Element Deleted : %d\n",deque[front]);
	if(front == rear)
	{
	    front = -1;
		rear = -1;
    }
    else
      rear = rear-1;
    display();
}
