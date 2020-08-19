#include<stdio.h>

int bubble_sort(int a[],int n);

int bubble_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
         for(int j=0;j<n-i-1;j++)
         {
             if(a[j] > a[j+1])
             {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
             }
         }
    }
    printf("Elements after sorting\n");
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
    bubble_sort(a,n);
}
