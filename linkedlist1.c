 //STACK USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;//self referensial structure
	
};
typedef struct Node NODE; //creation of user defined data type i.e alias name
NODE *head=NULL;
void insert(int val)
{
	
	NODE *nn,*temp;//creating node
	nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;//adding the val 
	nn->next=NULL;//assign node address as NULL
	if(head==NULL)
	{
		head=nn;//address is storing in haed
	}
	else
	{
		temp=head;
		while(temp->next!=NULL) 
		{
			temp=temp->next;
		}
		temp->next=nn;	
	}
}

void display()
{
	NODE *temp;
	if(head==NULL)
	{
		printf("No Nodes\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;
		}
		printf("\n");
	}
	
}
int deletel()
{
	int val;
	NODE *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
	//	val=head->nn;
		val=head->data;
		head=NULL;
		return val;
	}
	temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	val=temp->next->data;
	
	temp->next=NULL;
	
	return val;
	
}
void main()
{
	int ch,val;
	while(1)
	{
		printf("\n1.insert  2.delete  3.display  4.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert
			scanf("%d",&val);
			insert(val);
		}
		else if(ch==2)
		{
			//delete
			val=deletel();
			if(val==-1)
			{
				printf("NO nodes");
			}
			else
			{
				printf("\n%d",val);
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
		}
	}
}

//insert delete display





















/* 
head always consists of first node address*/
