#include<stdio.h>
#include<string.h>
void main()
{
int n,s=0;
int waiting[10],turnaround[10],completion[10];
printf("Enter The Number of Processes : ");
scanf("%d",&n);
char pr[n][10],gc[n][10];
int a[n],b[n],i,c=0,time,x[n],q[n];
double avg=0,tt=0,end;
for(i=0;i<n;i++)
{
    printf("\nEnter The Process Name : ");
    scanf("%s",pr[i]);
    printf("\nEnter The BURST TIME : ");
    scanf("%d",&b[i]);
    printf("\nEnter The Arrival Time : ");
    scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
 x[i]=b[i];
 b[n]=777;
 for(time=0;c!=n;time++)
 {
   s=n;
  for(i=0;i<n;i++)
  {
   if(a[i]<=time && b[i]<b[s] && b[i]>0 )
   s=i;
  }
  b[s]--;
  if(b[s]==0)
  {
   c++;
   end=time+1;
   completion[s] = end;
   waiting[s] = end - a[s] - x[s];
   turnaround[s] = end - a[s];
  }

 }
 printf("\n-----------------------------------------------------------------------------------------");
printf("\nPROCESS		BURST TIME		Arrival Time		WT		TAT		CT\n");
for(i=0;i<n;i++)
 {
   printf("\n %s		   %d	    	           %d		        %d	         %d	        %d\n",pr[i],x[i],a[i],waiting[i],turnaround[i],completion[i]);
   avg = avg + waiting[i];
   tt = tt + turnaround[i];
 }
 printf("\n\nAverage waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf",tt/n);
}
