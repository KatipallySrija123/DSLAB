#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int f = -1, r = -1, count = 0;
int q[MAXSIZE];

int isfull()
{
   if((f == 0) && (r == MAXSIZE - 1))
     return 1;
   else
     return 0;
}

int isempty()
{
   if(f == -1)
     return 1;
   else
     return 0;
}

void display()
{
   for(int i = f; i <= r;i++)
   {
 	printf("%d  ", q[i]);
   }
}

void enqueue(int element)
{
    if(f == -1)
    {
       f = 0;
       r = 0;
    }
    else if ((f != 0) && (r == MAXSIZE - 1))
    {
        int t = (MAXSIZE - count + 1), i = count;
        while(t--)
        {
	    q[i - 1] = q[i];
            i++;
        }
        f--;
        count--;
    }
    else
    {
        r++;
    }
    q[r] = element;      
}

int dequeue()
{
   int x = q[f];
   if(f == r)
   {
       f = r = -1;
       count++;
   }
   else
   {
      f++;
      count++;
   }
   return x;
}

int main()
{
    int ch, x;
    while(1)
    {
       printf("\n 1-enqueue \n 2-dequeue \n 3-display \n 4-exit \n");
       printf("Enter your choice: \n");
       scanf("%d", &ch);
       switch(ch)
       {
            case 1: if(isfull())
                    {
 			printf("queue overflow\n");
                    }
		    else
                    {
			printf("Enter data: \n");
			scanf("%d", &x);
			enqueue(x);
                    }
		    break;
            case 2: if(isempty())
                    {
 			printf("queue underflow\n");
                    }
		    else
		    {
			printf("Deleted Element: %d\n", dequeue());
                    }
		    break;
            case 3: if(isempty())
                     {
			printf("queue is empty\n");
                     } 
		     else
		     {
 			display();
                     }
		     break;
	    case 4: exit(0);
       }
    }
    return 0;
}