// record 
#include<stdio.h>
#include<stdlib.h>
int Top=-1;
int n,*st;
void push(val)
{
	if(Top==n-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		st[++Top]=val;
	}	
}
int pop()
{
	int val;
	if(Top==-1)
	{
	//	printf("Stack is empty");
	return -1;
	}
	else
	{
		val=st[Top];
		st[Top--]=0;
		return val;
	}
}
void display()
{
	int i;
	if(Top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(i=Top;i>=0;i--)
		{
			printf("%d ",st[i]);
		}
		printf("\n");
	}
}
void main()
{
	int i,ch,val;
	scanf("%d",&n);//read the size of stack
	st=(int *)calloc(n,sizeof(int));//allocating the memory of stack
	while(1)
	{
		printf("1.push  2.pop  3.Display  4.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//push function
			scanf("%d",&val);//reading a value
			push(val);//calling a funtion
		}
		else if(ch==2)
		{
			//pop function
			val=pop();
			if(val==-1)
			printf("Stack is empty\n");
			else
			printf("%d ",val);
		}
		else if(ch==3)
		{
			//display function
			display();
			
		}
		else 
		{
			break;
		}
	}
}
/*6
1.push  2.pop  3.Display  4.exit:1
55
1.push  2.pop  3.Display  4.exit:1
54
1.push  2.pop  3.Display  4.exit:1
5652
1.push  2.pop  3.Display  4.exit:3
5652 54 55
1.push  2.pop  3.Display  4.exit:1
5455
1.push  2.pop  3.Display  4.exit:1
555
1.push  2.pop  3.Display  4.exit:1
58
1.push  2.pop  3.Display  4.exit:1
88
Stack is full
1.push  2.pop  3.Display  4.exit:1
458
Stack is full
1.push  2.pop  3.Display  4.exit:3
58 555 5455 5652 54 55
1.push  2.pop  3.Display  4.exit:2
58 1.push  2.pop  3.Display  4.exit:3
555 5455 5652 54 55
1.push  2.pop  3.Display  4.exit:*/
