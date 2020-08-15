#include<stdio.h>

int linear_search(int arr[],int target,int total_elements);
int linear_search(int arr[],int target,int total_elements)
{
    int found = 0;
    for(int i=0;i<total_elements;i++)
    {
        if(arr[i] == target)
        {
            found = i;
            break;
        }
    }
    if(found != 0)
    {
       printf("The element is found at: %d position\n",found + 1);
    }
    else
    {
       printf("The element not found\n");
    }
    return 0;
}

int main()
{
    int total_elements,target;
    printf("Enter total_elements and target\n");
    scanf("%d%d",&total_elements,&target);
    int arr[total_elements];
    printf("Elements of an array:\n");
    for(int i=0;i<total_elements;i++)
    {
        scanf("%d",&arr[i]);
    }
    linear_search(arr,target,total_elements);
}