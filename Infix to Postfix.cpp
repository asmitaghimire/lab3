#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50


typedef struct
{
	int top;
	int items[MAX];
}stack;



void push (stack*,char);
char pop (stack*);
int prcd (char);
char top(stack*);

int main()
{
	int i;
	char exp[100],symb,x,symb1;
	stack s;
	s.top=-1;
	printf("Enter a postfix expression\n");	
	gets(exp);
	for (i=0;i<strlen(exp);i++)
	{
		symb=exp[i];
		if((symb>='A' && symb<='Z') || (symb>='a' && symb<='z') )
       		printf("%c",symb);
       		
       			else if(symb == '(')
            		push(&s,symb);
        		else if(symb == ')')
                {
                    while((x = pop(&s)) != '(')
                	printf("%c", x);
                }
        else
        {
        	symb1=top(&s);
            while(prcd(symb1) >= prcd(symb))
                printf("%c",pop(&s));
            push(&s,symb);
        }
        
    }
    while(s.top != -1)
    {
        printf("%c",pop(&s));
    }
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
	}else
	{
		return s->items[s->top--];
	}
}


int prcd (char x)
{
	if(x == '(')
        return 0;
        
    if(x == '+' || x == '-')
        return 1;
        
    if(x == '*' || x == '/')
        return 2;
        
    if(x == '$')
        return 3;
}
    

char top(stack* s)
{
   return(s->items[s->top]);
}












