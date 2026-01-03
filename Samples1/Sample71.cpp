#include<stdio.h>
int main()
{
    int t,i,n,j,k,count;
    scanf("%d",&t);
    int ans[t];
    for(int i=0;i<t;i++)
    {
        count=0;
        scanf("%d", &n);
        int arr[n];
        for(j=0;j<n;j++)
        {
            scanf("%d", &arr[j]);
        }
        for(j=0;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if((arr[j] & arr[k]) >= (arr[j] ^ arr[k]))
                {
                    count++;
                }
            }
        }
        ans[i] = count;
    }
    for(i=0;i<t;i++)
    {
        printf("%d\n", ans[i]);
    }
}