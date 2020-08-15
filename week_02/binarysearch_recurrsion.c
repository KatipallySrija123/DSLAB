#include<stdio.h>

int binarysearch(int first,int last,int a[50],int x)
{
   int mid;
   if(first <= last)
   {
       mid = (first + last)/2;
       if (a[mid] == x)
           return mid + 1;
       else if(a[mid] < x)
           binarysearch(mid + 1, last, a, x);
       else 
           binarysearch(mid - 1, last, a, x);
   }
   else
         return -1;
}

int main()
{
   int n, pos, x;
   scanf("%d%d",&n,&x);
   int a[50];
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   pos = binarysearch(0, n-1, a, x);
   if(pos == -1)
        printf("Element not found\n");
   else
        printf("Element found at %d position\n",pos);
}