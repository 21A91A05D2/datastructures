/*#include<stdio.h>
#include<stdlib.h>
int n,*qu,r=-1,f=-1;
void enqueue(int val)
{
	if(r==n-1)
	{
		// queue is full
		printf("Over flow\n");
	}
	else if(f==-1 && r==-1)
	{
		//queue is empty
		qu[++r]=val;
		f++;
	}
	else
	{
		qu[++r]=val;
	}
}
int dequeue()
{
	int val;
	if(r==-1 && f==-1)
	{
		//queue is empty
		return -1;
	}
	else if(f==r)
	{
		// queue has single element
		val=qu[f];
		f=-1;
		r=-1;
		return val;
	}
	else
	{
		val=qu[f++];
		return val;
	}
}
void display()
{
	int i;
	if(r==-1 && f==-1)
	{
		//queue is empty
		printf("Under flow\n");
	}
	else
	{
		//printing queue from front end to rear end
		for(i=f;i<=r;i++)
		{
			printf("%d ",qu[i]);
		}
		printf("\n");
	}
}
void main()
{
	int i,ch,val;
	scanf("%d",&n);
	qu=(int *)calloc(n,sizeof(int));
	while (1)
	{
		printf("1.enqueue  2.dequeue  3.display  4.exit  :");
		scanf("%d",&ch);
		if(ch==1)
		{
			//enqueue function- inserting elements to queue from rear end
			scanf("%d",&val);
			enqueue(val);
		}
		else if(ch==2)
		{
			//dequeue function - removing an element from front end
			val=dequeue();
			if(val==-1)
			{
				// queue is empty
				printf("Under flow\n");
			}
			else
			{
				// printing the element which is removed
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			//display function-displaying elements in queue from front end to rear end
			display();
		}
		else
		{
			//exit - if ch>3
			break;
		}
	}
}*/
//BOTH ARE SAME
#include<stdio.h>
#include<stdlib.h>
int *que,size,rear=-1,front=-1;
void enque(int val)
{
	if(rear==size-1)
	{
		printf("Over Flow");
	}
	else if(front==-1 && rear==-1)
	{
		que[++rear]=val;
		front++;//rear is incremented first and them element is entering]
	}
	else
	{
		que[++rear]=val;
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
	if(front==-1 && rear ==-1)
	{
		printf("under flow");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",que[i]);
		}
		printf("\n");
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
}
