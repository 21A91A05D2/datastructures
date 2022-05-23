 /*
infix to post
1. if it is operand append to output string
2.if it is operator:
		if st empty push to stack
		op(i)>op(top) add aperator to stack
		if it is less than pop ot from stack to output string
		and check*/
#include<stdio.h>
char infix[100],st[100],post[100];
int top=-1;
int isoper(char ch)
{
	
	switch(ch)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		default:return 0;
	}
}
void infix_postfix(char *str)
{
	int i,k=0;
	char ch;
	for(i=0;str[i]!='\0';i++)
	{
		if(isoper(str[i]))
		{
			X:if(top==-1)//stack is empty
			{
				st[++top]=str[i];	
			}
			else
			{
				if(isoper(str[i])>isoper(st[top]))
				{
					st[++top]=str[i];
				}
				else
				{
					ch=st[top--];
					post[k++]=ch;
					goto X;
				}
			}	
		}
		else
		{
			post[k++]=str[i];
		}
	}
	for(i=top;i>=0;i--)
	{
		post[k++]=st[i];
	}
}
void main()
{
	scanf("%[^\n]s",&infix);
	infix_postfix(infix);
	printf("%s",post);
}
/*a+b*c-d*e/f
abc*+de*f/-*/

