/*#include<stdio.h>
#include<stdlib.h>
int *que,size,rear=-1,front=-1;
void enque(int val)
{
	if(front==0 && rear==size-1 || rear+1=front)
	{
		printf("Over flow");
	}
	else if(front==-1 && rear==-1)
	{
		rear=(rear+1)%size;
		que[rear]=val;
		front=0;
	}
	else
	{
		rear
	}
}
int deque()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}	
	else if(front==rear)
	{
		val=que[front];
		front=-1;
		rear=-1;
		return val;
	}
	else
	{
		val=que[front++];
	//	front++;
		return val;
	}
//	return val;
}
void display()
{
	int i;
	if(front=-1 && rear ==-1)
	{
		printf("under flow");
	}
	else
	{
	
	}
}
void main()
{
	int i,ch,val;
	scanf("%d",&size);
	que=(int *)calloc(size,sizeof(int));
	while(1)
	{
		printf("1.enque  2.deque 3.dispaly  4.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			enque(val);
		}
		else if(ch==2)
		{
			//deque
			val=deque();
			if(val!=-1)
			{
				printf("%d\n",val);
			}
			else
			{
				printf("under flow");
			}
		}
		else if(ch==3)
		{
			//display
			display();
		}
		else
		{
			break;
		}
	}
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f=-1,r=-1,n,*queue;
void enqueue(int val)
{
	if((f==0&&r==n-1)||f==r+1)
	{
		printf("Overflow\n");
	}
	else
	{
		if(f==-1)
		{
			f=0;
		}
		r=(r+1)%n;
    	queue[r] =val;
	}
}
int dequeue()
{
	int val;
	if(f==-1&&r==-1)
	{
		return -1;//return front;
	}
	else if(f==r)
	{
		val=queue[f];
		f=-1;
		r=-1;
		return val;
	}
	else
	{
		val=queue[f];
		f=(f+1)%n;
		return val;
	}
}
void display()
{
	int i;
	if(f==-1&&r==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=f;i!=r;i=(i+1)%n)
		{
			printf("%d ",queue[i]);
		}
		printf("%d",queue[i]);
		printf("\n");
	}
}
int main()
{
	int i,ch,val;
	scanf("%d",&n);
	queue=(int *)calloc(n,sizeof(int));//allocating the memory of queue
	while(1)//infinite loop
	{
		printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//enqueue
			scanf("%d",&val);
			enqueue(val);
		}
		else if(ch==2)
		{
			//dequeue
			val=dequeue();//it works with return value
			if(val==-1)
			{
				printf("Underflow\n");
			}
			else
			{
				printf("%d\n",val);//displaying what element is deleted from queue
			}
		}
		else if(ch==3)
		{
			//display
			display();
		}
		else
		{
			//exit
			break;
		}
	}
}*/
#include<stdio.h>
# define MAX 5
int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void insert(int item)
{
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("Queue Overflow n");
return;
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
cqueue_arr[rear] = item ;
}
void deletion()
{
if(front == -1)
{
printf("Queue Underflown");
return ;
}
printf("Element deleted from queue is : %dn",cqueue_arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}
void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
printf("Queue is emptyn");
return;
}
printf("Queue elements :n");
if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
else
{
while(front_pos <= MAX-1)
{
printf("%d ",cqueue_arr[front_pos])
front_pos++;
}
front_pos = 0;
while(front_pos <= rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
}
printf("n");
}
int main()
{
int choice,item;
do
{
printf("1.Insertn");
printf("2.Deleten");
printf("3.Displayn");
printf("4.Quitn");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Input the element for insertion in queue : ");
scanf("%d", &item);
insert(item);
break;
case 2 :
deletion();
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Wrong choicen");
}
}while(choice!=4);
return 0;
}
