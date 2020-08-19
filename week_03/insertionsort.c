#include<stdio.h>

int insertion_sort(int a[],int n)
{
   int j,index;
   for(int i=1;i<n;i++)
   {
      index = a[i];
      j = i;
      while((j>0) && (a[j-1] > index))
      {
          a[j] = a[j-1];
          j = j-1;
      }
      a[j] = index;
   }
   for(int i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   return 0;
} 

int main()
{
    int n,x;
    printf("Enter no.of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
}