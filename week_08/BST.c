#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BST
{
   int data;
   struct BST *left;
   struct BST *right;
};

struct BST *root = NULL, *temp, *cur;

void ceate()
{
    char c[10];
    temp = root;
    cur = (struct BST*)malloc(sizeof(struct BST));
    printf("Enter data: \n");
    scanf("%d", &(cur->data));
    cur->left = NULL;
    cur->right = NULL;
    if(temp == NULL)
    {
	root = cur;
    }
    else
    {
        while(temp != NULL)
        {
             if((cur->data) < (temp->data))
             {
                 if(temp->left == NULL)
                 {
                     temp->left = cur; 
                     return;
                 }
                 else
                 {
		      temp = temp->left;
                 }
             }
             else
             {
                 if(temp->right == NULL)
                 {
		     temp->right = cur;
                      return;
                 }
                 else
                 {
		     temp = temp->right;
                 }
             }
        }
    }
}

void preorder(struct BST *temp)
{
     if(temp != NULL)
     {
         printf("%d \t", temp->data);
         preorder(temp->left);
         preorder(temp->right);
     }
}

void inorder(struct BST *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d \t", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct BST *temp)
{
    if(temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d \t", temp->data);
    }
}


int main()
{
   int ch;
   printf("\n 1-create \n 2-preorder \n 3-inorder \n 4-postorder \n 5-exit\n");
   while(1)
   {
      printf("Enter your choice: \n");
      scanf("%d", &ch);
      switch(ch)
      {
	 case 1: create();
	         break;
	 case 2: printf("Preorder traversal\n");
                 break;
         case 3: printf("Inorder traversal\n");
                 break;
         case 4: printf("postorder traversal\n");
                 break;
         case 5: exit(0);
         default: printf("Invalid choice\n");
      }
   }
   return 0;
}