#include<iostream>
using namespace std;
int main()
{
    int t,n,i,j,count,p1=0,p2=0;
    cin>>t;
    int ans[t];
    for(i=0;i<t;i++)
    {
        count=0;
        p1=1;
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        for(j=0;j<n;j++)
        {
            if(j<n-1)
            {
                if(arr[j] == 0 && arr[j+1] == 0)
                {
                    if(p1==1)
                    {
                        j++;
                        p1=0;
                        p2=1;
                    }
                    else if(p2==1)
                    {
                        p2=0;
                        p1=1;
                    }
                }
                else if(arr[j] == 0 && arr[j+1] == 1)
                {
                    if(p1==1)
                    {
                        p2=1;
                        p1=0;
                    }
                    else if(p2==1)
                    {
                        j++;
                        p1=1;
                        p2=0;
                    }
                }
                else if(arr[j] == 1 && arr[j+1] == 0)
                {
                    if(p1==1)
                    {
                        count++;
                        p1=0;
                        j++;
                        p2=1;
                    }
                    else if(p2==1)
                    {
                        p1=1;
                        p2=0;
                    }
                }
                else if(arr[j]==1 && arr[j+1] == 1)
                {
                    if(p1==1)
                    {
                        count++;
                        p1=0;
                        p2=1;
                    }
                    else if(p2==1)
                    {
                        p1=1;
                        j++;
                        p2=0;
                    }
                }
            }
            else if(j==n-1)
            {
                if(p2==1)
                {
                    continue;
                }
                else
                {
                    if(arr[j] == 1)
                        count++;
                }
            }
        }
        ans[i] = count;
    }
    for(i=0;i<t;i++)
    {
        printf("%d\n",ans[i]);
    }
}