#include<iostream>
using namespace std;
int main()
{
    int t,n,m,b;
    cin>>t;
    int flag;
    while(t--)
    {
        flag=0;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>b;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]<arr[i-1])
            {
                arr[i] = b-arr[i];
            }
        }
        if(arr[0]>arr[1])
        {
            arr[0] = b-arr[0];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>arr[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
}