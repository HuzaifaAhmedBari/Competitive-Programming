#include<stdio.h>
#include<stdlib.h>
int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), comp);
    int temp1=arr[n-1];
    int temp2=arr[n-2];
    int temp3=arr[n-3];
    
}