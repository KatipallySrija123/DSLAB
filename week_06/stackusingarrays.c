#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int a[MAXSIZE];
int top = -1;

int isfull()
{
    if(top == MAXSIZE-1)
       return 1;
    else
       return 0;
}

void push(int element)
{
     top += 1;
     a[top] = element;
}

int isempty()
{
    if(top == - 1)
      return 1;
    else
      return 0;
}

int pop()
{
    return a[top--];
}

void display()
{
    if(top == -1)
    {
       printf("Stack is empty\n");
    }
    else
    {
       for(int i = top; i >= 0;i--)
       {
	   printf("%d  ", a[i]);
       }
    }
}

int peek()
{
    return a[top];
}


int main()
{
    int x, ch;
    while(1) 
    {
        printf("1-push \n 2-pop \n 3-display \n 4-peek \n 5-exit \n");
        printf("Enter your choice: \n");
	scanf("%d", &ch);
	switch(ch) 
        {
	     case 1: if(isfull())
                     {
			printf("Stack overflow\n");
                     }
		     else
		     {
			printf("Enter the data you want to push: \n");
			scanf("%d", &x);
                        push(x);
                     }
		     break;
             case 2: if(isempty())
                     {
			printf("Stack Underflow\n");
                     }
		     else
 		     {
			x = pop();
			printf("Deleted Element: %d\n", x);
   		     }
		     break;
             case 3: display();
                     break;
             case 4: printf("Top most element: %d\n", peek());
                     break;
             case 5: exit(0); 
        }
    }
    return 0;
}