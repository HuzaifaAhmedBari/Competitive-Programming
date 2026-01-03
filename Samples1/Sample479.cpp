#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n-1][(n*2)-1];
    int start = 0;
    int end = (n*2)-1;
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        for(j=0;j<start;j++)
        {
            arr[i][j] = arr[i-1][j];
        }
        for(j=start;j<end;j++)
        {
            arr[i][j] = n-i;
        }
        for(j=j;j<(n*2)-1;j++)
        {
            arr[i][j] = arr[i-1][j];
        }
        start+=1;
        end-=1;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<(n*2)-1;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for(int i=n;i>0;i--)
    {
        printf("%d ",i);
    }
    for(int i=2;i<=n;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(int i=n-2;i>=0;i--)
    {
        for(j=0;j<(n*2)-1;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}