#include<stdio.h>
int binary_search(int arr[],int target,int total_elements);
int binary_search(int arr[],int target,int total_elements)
{
     int first = 0, last = (total_elements - 1), mid;
     if(arr[last] < target)
     {
         printf("Element not found\n");
     }
     while(first <= last)
     { 
          mid = (first + last) / 2;   
          if(arr[mid] == target)
          {  
             printf("element found at %d position\n",mid + 1);
             break;
          }
          else if(arr[mid] < target)
          { 
              first = mid + 1;
          }
          else if(arr[mid] > target)
          {
              last = mid - 1;
          }
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
    binary_search(arr,target,total_elements);
}






