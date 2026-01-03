#include<iostream>
using namespace std;
int comp(const void*a, const void*b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int n,ans=0,temp;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    qsort(arr, n, sizeof(int), comp);
    for(int i=0;i<n-1;i++)
    {
        temp=arr[i+1] - arr[i];
        if(temp>1)
        {
            ans += temp-1;
        }
    }
    cout<<ans;
}