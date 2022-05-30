#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert_at_end(int val)
{
	node *nn,*temp;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
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
int delete_at_end()
{
	int val;
	node *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL; 
		return val;
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=NULL;
		return val;
	}
}
void display()
{
	node *temp;
	if(head==NULL)
	{
		printf("NO NODES\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
void insert_at_head(int val)
{
	node *nn;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;//inserting head(2nd node) at new node's next
		head=nn;//making 1st new node as head
	}
}
void insert_by_pos(int val,int pos)
{
	node *temp,*nn;
	int cn=1,i;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	temp=head;
	while(temp)//temp!=NULL both r same
	{
		temp=temp->next;
		cn++;//count
	}
	if(head==NULL)
	{
		head=nn;
	}
	else if(pos==1)//to add element at fisrt position
	{
		insert_at_head(val);
	}
	else if(cn<pos)//no nodes
	{
		insert_at_end(val);//if the position is not there then we can directly add at the end
		//add element at end by end fun
	}
	else
	{
		temp=head;//original logic
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;	
	}
}
int del_by_pos(int pos)
{
	node *temp;
	int cn=1,i,val;
	temp=head;
	while(temp)//temp!=NULL both r same
	{
		temp=temp->next;
		cn++;
	}
	if(head==NULL)
	{
		return -1;
	}
	if(pos==1)//to add element at fisrt position
	{
		return delete_at_head();
	}
	else if(cn<=pos)//no nodes
	{
		return delete_at_end();
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=temp->next->next;
		return val;
	}
}
int delete_at_head()
{
	int val;
	node *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		temp=temp->next;
		head->next=NULL;
		val=head->data;
		head=temp;
		/*
		val=head->data;//copying the deleting head data
		head=head->next;//making head point to next node address
		*/
		return val;
	}
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1)Insert at end\t2)Delete at end\t3)Display\t4)Insert at head\t5)Delete at head\t6)insert by position  7.delete by position  8.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			insert_at_end(val);
		}
		else if(ch==2)
		{
			val=delete_at_end();
			if(val==-1)
			{
				printf("NO NODES TO DELETE\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else if(ch==4)
		{
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if(ch==5)
		{
			val=delete_at_head();
			if(val==-1)
			{
				printf("NO NODES TO DELETE\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==6)
		{
			//positon
			scanf("%d%d",&val,&pos);
			insert_by_pos(val,pos);
		}
		else if(ch==7)
		{
			//delete at position
			scanf("%d",pos);
			val=del_by_pos(pos);
			if(val==-1)
			{
				printf("No nodes");
			}
			else
			printf("%d",val);
		}
		else 
		{
			break;
		}
	}
}
//insert and head and delete at head
