#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node*link;
};
struct node* head = NULL, *tail = NULL, *cur, *prev, *next,*p1,*p2;

void create()
{
  int n;
  printf("Enter no.of nodes you want to create:\n");
  scanf("%d",&n);
  for(int i = 0;i < n;i++)
  {
     cur = (struct node*)malloc(sizeof(struct node));
     printf("Enter current node data: \n");
     cur->link = NULL;
     scanf("%d",&(cur->data));
     if(head == NULL)
     {
          head = tail = cur;
     }
     else
     {
        tail->link = cur;
        tail = cur;
     }
  }
}

void insert_at_begin()
{
    cur = (struct node*)malloc(sizeof(struct node));
    printf("Enter current node data:\n");
    scanf("%d",&(cur->data));
    cur->link = head;
    head = cur;
}

void insert_at_end()
{
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current node data:\n");
  scanf("%d",&(cur->data));
  cur->link = NULL;
  tail->link = cur;
  tail = cur;
}

void insert_at_position()
{
  int pos,c = 1;
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current data:\n");
  scanf("%d",&(cur->data));
  printf("Enter position where you want to insert:\n");
  scanf("%d",&pos);
  next = head;
  while(c < pos)
  {
      prev = next;
      next = next->link;
      c++;
  }
  prev->link = cur;
  cur->link = next; 
}

void insert_before()
{
  int value;
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter the current node data:\n");
  scanf("%d",&(cur->data));
  printf("Enter the value before which you want to enter: \n");
  scanf("%d",&value);
  next = head;
  while(next->data != value && next != NULL)
  {
    prev = next;
    next = next->link;
  }
  prev->link = cur;
  cur->link = next;
}

void insert_after()
{
  int value;
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current node data: \n");
  scanf("%d",&(cur->data));
  printf("Enter the value after which you want to enter: \n");
  scanf("%d",&value);
  next = head;
  while(next->data != value && next != NULL)
  {
     next = next->link;
  }
  cur->link = next->link;
  next->link = cur;
}

void delete_at_begin()
{
  cur = head;
  head = cur->link; 
  cur->link = NULL;
  printf("deleted node data = %d\n",cur->data);
  free(cur);
}

void delete_at_end()
{
  cur = head;
  while(cur->link != tail)
  {
     cur = cur->link;
  }
  cur->link = NULL;
  next = tail;
  printf("deleted node data: %d\n",next->data);
  tail = cur;
  free(next);
}

void delete_at_position()
{
   int pos,c = 1;
   printf("Enter position which you want to delete: \n");
   scanf("%d",&pos);
   next = head;
   while(c < pos)
   {
     prev = next;
     next = next->link;
     c++;
   }
   prev->link = next->link;
   next->link = NULL;
   printf("deleted node data = %d\n",next->data);
   free(next);
}

void delete_before()
{
  int value;
  printf("Enter before which node you want to delete:\n");
  scanf("%d",&value);
  next = head;
  while(next->link->data != value)
  {
      prev = next;
      next = next->link;
  }
  prev->link = next->link;
  next->link = NULL;
  printf("deleted node data: %d\n",next->data);
  free(next);
}

void delete_after()
{
 
  int value;
  printf("Enter after which node you want to delete:\n");
  scanf("%d",&value);
  next = head;
  while(next->data != value)
  {
    prev = next;
    next = next->link;
  }
  prev = next->link;
  next->link = prev->link;
  printf("deleted node data: %d\n",prev->data);
  prev->link = NULL;
  free(prev);
}

void traversal()
{
   if(head == NULL)
   {
      printf("list is empty\n");
   }
   else
   {
     next = head;
     while(next != NULL)
     {
         printf("%d->",next->data);
         next = next->link;
     }
   }
}

void sort()
{
  p1 = head;
  int c = 0,i,t;
  while(p1 != NULL)
  {
   c++;
   p1 = p1 -> link;
  }
  for(i=0;i<c;i++)
  {
   p2 = head;
   while(p2->link != NULL)
   {
      if(p2->data > p2->link->data)
      {
          t = p2->data;
          p2->data = p2->link->data;
          p2->link->data = t;
      }
      p2 = p2->link; 
   }
  }
}

void display_in_reverse()
{
  int a[100],i=0;
  cur = head;
  while(cur != NULL)
  {
      a[i++] = cur->data;
      cur = cur->link;
  }
  while(i >= 0)
  {
    printf("%d->",a[i]);
    i--;
  }
}

void search()
{
        int key,flag=0,c=1;
	printf("Enter value\n");
	scanf("%d",&key);
        cur=head;
        while(cur!=NULL)
        {
                if(cur->data==key)
                {
                        flag=1;
			printf("Element found at %d\n",c);
                        break;
                }
                cur=cur->link;
		c++;
        }
	if(flag==0)
	{
		printf("Element not found\n");
	}
}

int main()
{
  int num;
  while(1)
  {
    printf("1-create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insertbefore\n");
    printf("6-insert after\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before\n");
    printf("11-delete after\n12-traversal\n13-display in reverse\n14-search\n15-sort\n16-exit\n");
    scanf("%d",&num);
    switch(num)
    {
         case 1: create();
                 break;
         case 2: insert_at_begin();
                 break;
         case 3: insert_at_position();
                 break;
         case 4: insert_at_end();
                 break;
         case 5: insert_before();
                 break;
         case 6: insert_after();
                 break;
         case 7: delete_at_begin();
                 break;
         case 8: delete_at_end();
                 break;
         case 9: delete_at_position();
                 break;
         case 10: delete_before();
                 break;
         case 11: delete_after();
                 break; 
         case 12: traversal();
                 break;
         case 13: display_in_reverse();
                 break;
         case 14: search();
                 break;
         case 15: sort();
                 break; 
         case 16: exit(0);
          
    }
  }
  return 0;
}