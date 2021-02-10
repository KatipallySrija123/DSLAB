#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int data;
   struct node *link; 
};

struct node *top = NULL, *cur, *next;

void push()
{
   cur = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data to push: \n");
   scanf("%d", &(cur->data));
   cur->link = top;
   top = cur;
}

int isempty()
{
    if(top == NULL)
      return 1;
    else
      return 0;
}

void display()
{
    if(top == NULL)
    {
        printf("list is empty \n");
    }
    else
    {
	next = top;
	while(next != NULL)
        {
	    printf("%d -> ", next->data);
            next = next->link;
        }
        printf("\n");
        printf("NULL\n");
    }
}

int peek()
{
    return (top->data);
}

void pop()
{
   cur = top;
   top = cur->link;
   cur->link = NULL;
   printf("Deleted Element: %d\n", cur->data);
   free(cur);
}


int main()
{
     int ch, x;
     while(1)
     {
	printf("\n 1-push \n 2-pop \n 3-display \n 4-peek \n 5-exit\n");
	printf("Enter the choice: \n");
	scanf("%d", &ch);
	switch(ch)
        {
            case 1: push(x);
	 	    break;
	    case 2: if(isempty())
                    {
                        printf("Stack Underflow\n");
                    }
		    else
                    {
                        pop();
                    }
		    break;
	    case 3: display();
		    break;
            case 4: printf("Top most element on stack: %d \n", peek());
                    break;
            case 5: exit(0);
	}
     }
     return 0;
}