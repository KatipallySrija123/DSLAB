#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *link;
};

struct node *f = NULL, *r = NULL, *cur;

void enqueue()
{
   cur = (struct node*)malloc(sizeof(struct node));
   printf("Enter data: \n");
   scanf("%d", &(cur->data));
   if(f == NULL)
   {
      f = cur;
      r = cur;
   }
   else
   {
      r->link = cur;
      cur->link = NULL;
      r = cur;
   }
}

void dequeue()
{
   if(f == NULL)
   {
       printf("queue underflow\n");
   }
   else if(f == r)
   {
       printf("Deleted element: %d\n", f->data);
   }
   else
   {
       cur = f;
       f = f->link;
       printf("Deleted data: %d\n", cur->data);
       free(cur);
   }
}

void display()
{
   cur = f;
   if(f == NULL)
   {
       printf("queue is empty\n");
   }
   else
   {
     while(cur != NULL)
     {
	printf("%d ", cur->data);
        cur = cur->link;
     }
   }
}


int main()
{
   int ch, x;
   while(1)
   {
      printf("\n 1-enqueue \n 2-dequeue \n 3-display \n 4-exit \n");
      scanf("%d", &ch);
      switch(ch)
      {
         case 1: enqueue();
                 break;
         case 2: dequeue();
                 break;
         case 3: display();
                 break;
         case 4: exit(0);
      }
   }
   return 0;
}