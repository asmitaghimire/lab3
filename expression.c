#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50


typedef struct
{
	int top;
	int items[MAX];
}stack;



void push (stack*,char);
char pop (stack*);
char close(char);



int main()
{
	stack s;
	s.top=-1;
	int i,valid=1;
	char exp[100],symb,x,y;
	gets(exp);
	for (i=0;i<strlen(exp);i++)
	{	
		symb=exp[i];
		
		if(symb=='(' || symb=='[' || symb=='{')
		{
			push(&s,symb);
		}
		
		if(symb==')' || symb==']' || symb=='}')
			if	(s.top == -1)
				valid=0;
			else 
			{
				x=pop(&s);
				if ((symb=='(' && symb=='[')|| (symb==')'&& symb=='{'))
					valid=0;						
			}	
	}
	if	(s.top != -1)
		valid=0;
		
	if (valid == 1)
	printf("\n\nThe Given Expression is Valid");
	else
	printf("\n\nThe Given Expression is not Valid");
	return 0;
	
}

char close(char x)
{
	if (x==')')
	return '(';
	else if (x=='}')
	return '{';
	else
	return '[';
}

void push (stack *s,char x)
{
	if (s->top==(MAX-1))
	{	
		printf("Stack Overflow\n");
		
	}else{
		++(s->top);
		s->items[s->top]=x;	
	}
}



char pop (stack *s)
{
	if (s->top==-1)
	{
		printf("Stack Underflow");
		exit(0);
	}else{
	return s->items[s->top--];
}
}











