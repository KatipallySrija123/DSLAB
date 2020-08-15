#include<stdio.h>

int linearsearch_recurrsion(int arr[],int total_elements,int target);
int linearsearch_recurrsion(int arr[],int total_elements,int target)
{
    static int x = 0;
    if(arr[x] == target)
    { 
        printf("Element found at %d position\n",x+1);
    }
    else 
    {
        x += 1;
        linearsearch_recurrsion(arr,total_elements,target);
    }
    return 0;
}

int main()
{
    int total_elements, target;
    printf("Enter no.of elements and target:\n");
    scanf("%d%d",&total_elements,&target);
    int arr[total_elements];
    printf("Enter elements of array:\n");
    for(int i=0;i<total_elements;i++)
    {
        scanf("%d",&arr[i]);
    }
    linearsearch_recurrsion(arr,total_elements,target);
}