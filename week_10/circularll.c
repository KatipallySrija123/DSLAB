#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *link;
};

struct node *head = NULL, *cur, *temp, *t1, *t2;

void create()
{
   cur = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data: \n");
   scanf("%d", &(cur->data));
   cur->link = cur;
   if(head == NULL)
   {
      head = cur;
   }
   else
   {
      temp = head;
      while(temp->link != head)
      {
          temp = temp->link;
      }
      temp->link = cur;
      cur->link = head;
   }
}

void insert_at_begin()
{
   cur = (struct node*)malloc(sizeof(struct node));
   printf("Enter data: \n");
   scanf("%d", &(cur->data));
   temp = head;
   while(temp->link != head)
   {
       temp = temp->link;
   }
   temp->link = cur;
   cur->link = head;
   head = cur;
}

void insert_at_end()
{
   cur = (struct node*)malloc(sizeof(struct node));
   printf("Enter data: \n");
   scanf("%d", &(cur->data));
   temp = head;
   while(temp->link != head)
   {
       temp = temp->link;
   }
   temp->link = cur;
   cur->link = head;
}

void insert_at_pos()
{
    int c = 1, pos;
    printf("Enter position of insertion: \n");
    scanf("%d", &pos);
    cur = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: \n");
    scanf("%d", &(cur->data));
    t1 = head;
    while(c < pos)
    {
         t2 = t1;
         t1 = t1->link;
         c++;
    }
    t2->link = cur;
    cur->link = t1;
}

void delete_at_begin()
{
    cur = temp = head;
    while(temp->link != head)
    {
         temp = temp->link;
    }
    temp->link = cur->link;
    head = cur->link;
    cur->link = NULL;
    printf("Deleted Element: %d \n", cur->data);
    free(cur);
}

void delete_at_end()
{
    t1 = head;
    while(t1->link != head)
    {
         t2 = t1;
         t1 = t1->link;
    }
    t2->link = head;
    t1->link = NULL;
    printf("Deleted element: %d \n", t1->data);
    free(t1);
}

void delete_at_pos()
{
   int c = 1, pos;
   printf("Enter position of deletion. \n");
   scanf("%d", &pos);
   t1 = head;
   while(c < pos)
   {
       t2 = t1;
       t1 = t1->link;
       c++;
   }
   t2->link  = t1->link;
   t1->link = NULL;
   printf("Deleted Element: %d \n", t1->data);
   free(t1);
}

void display()
{
    if(head == NULL)
    {
       printf("circular linked list is empty \n");
    }
    else
    {
       temp = head;
       while(temp->link != head)
       {
	  printf("%d -> ", temp->data);
          temp = temp->link;
       }
       printf("%d", temp->data);
    }
}

int main()
{
   int ch;
   while(1)
   {
       printf("\n 1-create \n 2-insert_at_begin \n 3-insert_at_pos \n 4-insert_at_end \n 5-delete_at_begin \n 6-delete_at_end \n 7-delete_at_pos \n 8-display \n 9-exit\n");
       printf("Enter your choice: \n");
       scanf("%d", &ch);
       switch(ch)
       {
          case 1: create();
		  break;
	  case 2: insert_at_begin();
		  break;
          case 3: insert_at_pos();
		  break;
          case 4: insert_at_end();
                  break;
	  case 5: delete_at_begin();
		  break;          
          case 6: delete_at_end();
		  break;
	  case 7: delete_at_pos();
		  break;
          case 8: display();
                  break;
          case 9: exit(0);            
       }
   }
   return 0;
}