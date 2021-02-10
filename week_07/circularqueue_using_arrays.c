#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 6
int f = -1, r = -1, cq[MAXSIZE];

int isfull()
{
   if(f == ((r + 1) % MAXSIZE))
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

void enqueue(int x)
{
   if(f == -1)
     f = 0;
   r = (r + 1) % MAXSIZE;
   cq[r] = x; 
}

int dequeue()
{
   int x;
   x = cq[f];
   if(f == r)
   {
      f = r = -1;
   }
   else
   {
      f = (f + 1) % MAXSIZE;
   }
   return x;
}

void display()
{
   int i = f;
   if(f == -1)
   {
      printf("circular queue is empty\n");
   }
   else
   {
      while(i != r)
      {
         printf("%d  ", cq[i]);
         i = (i + 1) % MAXSIZE;
      }
      printf("%d", cq[i]);
   }
}

int main()
{
   int ch, x;
   while(1)
   {
       printf("\n 1-enqueue \n 2-dequeue \n 3-display \n 4-exit\n");
       printf("Enter your choice\n");
       scanf("%d", &ch);
       switch(ch)
       {
           case 1: if(isfull())
                   {
                       printf("circular queue overflow\n");
                   }
                   else
                   {
                       printf("Enter data to insert: \n");
                       scanf("%d", &x);
                       enqueue(x);
                   }
                   break;
           case 2: if(isempty())
                   {
                       printf("circular queue underflow\n");
                   }
                   else
                   {
                       printf("Deleted Element: %d\n", dequeue());
                   }
           case 3: display();
                   break;
           case 4: exit(0);
       }
   }
   return 0;
}