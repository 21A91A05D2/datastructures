#include<stdio.h>
#include<stdlib.h>
int f=-1,r=-1,n,*queue;
void rear_enqueue(int val)
{
	if((f==0&&r==n-1)||f==r+1)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1&&r==-1)
	{
		f=0;
		r=0;
		queue[r]=val;
	}
	else
	{
		r=(r+1)%n;
		queue[r]=val;
	}
}
void front_enqueue(int val)
{
	if((f==0&&r==n-1)||f==r+1)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1&&r==-1)
	{
		f=0;
		r=0;
		queue[f]=val;
	}
	else
	{
		if(f==0)
		{
			f=n-1;//circular queue way
		}
		else
		{
			f--;
		}
		queue[f]=val;
	}
}
int rear_dequeue()
{
	int val;
	if(f==-1&&r==-1)
	{
		return -1;
	}
	if(f==r)//single element
	{
		val=queue[r];
		f=-1;
		r=-1;
		return val;
	}
	val=queue[r];
	if(r==0)
	{
		r=n-1;
	}
	else
	{
		r--;
	}
	return val;
}
int front_dequeue()
{
	int val;
	if(f==-1&&r==-1)
	{
		return -1;
	}
	if(f==r)//single element
	{
		val=queue[f];
		f=-1;
		r=-1;
		return val;
	}
	val=queue[f];
	f=(f+1)%n;
	return val;
}
void display()
{
	int i;
	if(f==-1&&r==-1)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		for(i=f;i!=r;i=(i+1)%n)
		{
			printf("%d %d\n",i,queue[i]);
		}
		printf("%d %d\n",i,queue[i]);
	}
}
int main()
{
	int i,ch,val;
	scanf("%d",&n);
	queue=(int *)calloc(n,sizeof(int));
	while(1)
	{
		printf("1.Enqueue at Rear\t2.Dequeue at Rear\t3.Enqueue at Front\t4.Dequeue at Front\t5.Display\t6.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//enqueue at rear
			scanf("%d",&val);
			rear_enqueue(val);
		}
		else if(ch==2)
		{
			val=rear_dequeue();
			if(val==-1)
			{
				printf("Queue Underflow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			//enqueue at front
			scanf("%d",&val);
			front_enqueue(val);
		}
		else if(ch==4)
		{
			val=front_dequeue();
			if(val==-1)
			{
				printf("Queue Underflow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==5)
		{
			display();
		}
		else
		{
			break;
		}
	}
}
/*
properties are similar to circular queue
we can do both enque and deque at both front and rear
4 operations are there
1) enque at rear--> rear++
2) deque at rear--> rear--
3) enque at front--> front--
4) deque at front--> front++
*/

/*
//written by sir
#include<stdio.h>
#include<stdlib.h>
int *que,size,rear=-1,front=-1;
void enque_at_rear(int val)
{
	if((front==0 && rear==size-1)|| rear+1==front)
	{
		printf("Queue is overflow");
	}
	else if(front==-1 && rear==-1)
	{
		front==0;
		rear=0;
		que[rear]=val;
	}
	else
	{
		rear=(rear+1)%size;
		que[rear]=val;
	}
}
void enque_at_front(int val)//decrement
{
	if((front==0 && rear==size-1)|| rear+1==front)
	{
		printf("Queue is overflow");
	}
	else if(front==-1 && rear==-1)
	{
		front==0;
		rear=0;
		que[front]=val;
	}
	else
	{
	//	val=que[front]
		if(front==0)
		{
			front=size-1;
		}
		else{
			front--;
		}
		que[front]=val;	
	}
}
int deque_at_rear()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	if(front==rear)
	{
		val=que[front];
		front=-1;
		rear=-1;
		return val;
	}
	val=que[rear];
	if(rear==0)
	{
		rear=size-1;
	}
	else
	{
		rear--;
	}
	return val;
	
}
int deque_at_front()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	if(front==rear)
	{
		val=que[front];
		front=-1;
		rear=-1;
		return val;
	}
		val=que[front];
		front=(front+1)%size;
		return val;
}
void display()
{
	int i,j;
	if(front==-1 &&rear==-1)
	{
		printf("under flow\n");
	}
	else{
		i=front;
		j=rear;
		while(i!=j)
		{
			printf("%d %d\n ",i,que[i]);
			i=(i+1)%size;
		}
		printf("%d %d\n",j,que[j]);
		//still therer
	}
}
void main()
{
	int i,ch,val;
	scanf("%d",&size);
	que=(int *)calloc(size,sizeof(int));
	while(1)
	{
		printf("\n1.enque at rear 2.deque at rear 3.enque at front 4.deque at front 5.dispaly  6.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			//enque at rear
			scanf("%d",&val);
			enque_at_rear(val);
		}
		
		else if(ch==2)
		{
			val=deque_at_rear();
			if(val==-1)
			{
				printf("Queue under flow");
			}
			else
			{
				printf("%d",val);
			}
		}
		
		else if(ch==3)
		{
			//enque at front
			scanf("%d",&val);
			enque_at_front(val);
		}
		
		else if(ch==4)
		{
			val=deque_at_front();
			if(val==-1)
			{
				printf("Queue under flow");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		
		else if(ch==5)
		{
			display();
		}
		else
		{
			break;
		}
	}
}*/
