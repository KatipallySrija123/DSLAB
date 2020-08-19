#include<stdio.h>

int selection_sort(int a[],int n);

int selection_sort(int a[],int n)
{
  for(int i=0;i<n-1;i++)
  {
     int min = i;
     for(int j=i+1;j<n;j++)
     {
        if(a[j] < a[min])
        {
           min=j;
        }
     }
     int t = a[i];
     a[i] = a[min];
     a[min] = t;
  }
  for(int i=0;i<n;i++)
  {
     printf("%d ",a[i]);
  }
  return 0;
}

int main()
{
    int n;
    printf("Enter no.of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
}
