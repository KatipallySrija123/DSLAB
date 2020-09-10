#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node*prev;
 struct node*next; 
};

struct node *head = NULL, *tail = NULL, *cur, *t1, *t2;

void create()
{
  int n;
  printf("Enter no.of nodes you want to create: \n");
  scanf("%d",&n);
  for(int i = 0;i < n;i++)
  {
     cur = (struct node*)malloc(sizeof(struct node));
     printf("Enter current data: \n");
     scanf("%d",&(cur->data));
     cur->prev = NULL;
     cur->next = NULL;
     if(head == NULL)
     {
         head = tail = cur;
     }
     else
     {
         tail->next = cur;
         cur->prev = tail;
         tail = cur;
     } 
  } 
}

void insert_at_begin()
{
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current node data: \n");
  scanf("%d",&(cur->data));
  cur->prev = NULL;
  cur->next = head;
  head->prev = cur;
  head = cur;
}

void insert_at_end()
{
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current data: \n");
  scanf("%d",&(cur->data));
  cur->next = NULL;
  cur->prev = tail;
  tail->next = cur;
  tail = cur;
}

void insert_at_position()
{
  int pos,c=1;
  printf("Enter in which position you want to enter: \n");
  scanf("%d",&pos);
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current node data: \n");
  scanf("%d",&(cur->data));
  t1 = head;
  while(c<pos)
  {
     t2 = t1;
     t1 = t1->next; 
     c++;  
  }
  t2->next = cur;
  cur->prev = t2;
  cur->next = t1;
  t1->prev = cur; 
}

void insert_before()
{
  int value;
  printf("Before which you want to enter: \n");
  scanf("%d",&value);
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current data: \n");
  scanf("%d",&(cur->data));
  t1 = head;
  while(t1->data != value && t1 != NULL)
  {
    t2 = t1;
    t1 = t1->next; 
  }
  t2->next = cur;
  cur->prev = t2;
  t1->prev = cur;
  cur->next = t1;
}

void insert_after()
{
  int value;
  printf("After which you want to enter: \n");
  scanf("%d",&value);
  cur = (struct node*)malloc(sizeof(struct node));
  printf("Enter current data: \n");
  scanf("%d",&(cur->data));
  t1 = head;
  while(t1->data != value && t1 != NULL)
  {
     t1 = t1->next;
  }  
  cur->next = t1->next;
  t1->next->prev = cur;
  t1->next = cur;
  cur->prev = t1;
}

void delete_at_begin()
{
 cur = head;
 head = head->next;
 cur->next = NULL;
 head->prev = NULL;
 printf("deleted element = %d\n",cur->data);
 free(cur);
}

void delete_at_end()
{
  cur = tail;
  tail = tail->prev;
  tail->next = NULL;
  printf("deleted element: %d\n",cur->data);
  cur->prev = NULL;
  free(cur);
}

void delete_at_position()
{
  int n,c=1;
  printf("Enter position to be deleted:\n");
  scanf("%d",&n);
  t1 = head; 
  while(c < n)
  {
    t2 = t1;
    t1 = t1->next;
    c++;  
  }
  t2->next = t1->next;
  t1->next->prev = t2;
  t1->next = NULL;
  t1->prev = NULL;
  printf("deleted element = %d\n",t1->data);
  free(t1); 
}

void delete_before()
{
  int value;
  printf("Enter value before which you want to delete: \n");
  scanf("%d",&value);
  t1 = head;
  while(t1->data != value && t1 != NULL)
  {
    t2 = t1;
    t1 = t1->next;  
  } 
  t2->prev->next = t1;
  t1->prev = t2->prev;
  t2->prev = NULL;
  t2->next = NULL;
  printf("deleted data: %d\n",t2->data);
  free(t2); 
}

void delete_after()
{
  int value;
  printf("Enter value after which you want to delete: \n");
  scanf("%d",&value);
  t1 = head;
  while(t1->data != value && t1 != NULL)
  {
    t2 = t1;
    t1 = t1->next;
  }
  t2 = t1->next;
  t1->next = t2->next;
  t2->next->prev = t1;
  t2->prev = NULL;
  t2->next = NULL;
  printf("deleted data: %d\n",t2->data);
  free(t2);
}

void traversal()
{
  if(head == NULL)
  {
     printf("list is empty\n");
  }
  else
  {
     cur = head;
     while(cur->next != NULL)
     {
         printf("%d <-> ",cur->data);
         cur = cur->next;
     }
     printf("%d \n",cur->data);
  }  
}

void display_in_reverse()
{
  if(head == NULL)
  {
     printf("list is empty\n");
  }
  else
  {
    cur = tail;
    while(cur->prev != NULL)
    {
        printf("%d <-> ",cur->data);
        cur = cur->prev;
    }
    printf("%d \n",cur->data);
  }
}

void search()
{
  int value, c=0;
  printf("Enter value to be found: \n");
  scanf("%d",&value);
  cur = head;
  while(cur != NULL)
  {
     c++;
     if(cur->data == value)
     {
        printf("Element found at: %d\n",c);
        break;  
     }
     cur = cur->next;
  }
  if(c == 0)
  {
    printf("Element not found\n"); 
  }
}

void sort()
{
	struct node *p1,*p2,*last=NULL;
	int t,c;
	do
	{
		c=0;
		p1=head;
		while(p1->next!=last)
		{
			if(p1->data > p1->next->data)
			{
				t=p1->data;
				p1->data=p1->next->data;
				p1->next->data=t;
				c=1;
			}
			p1=p1->next;
		}
		last=p1;
	}
	while(c);
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