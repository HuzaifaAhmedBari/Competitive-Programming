#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,temp1,temp2;
    int ans;
    cin>>t;
    int a,b;
    for(int i=0;i<t;i++)
    {
        ans=0;
        int count=0;
        cin>>a>>b;
        int start=-1,end=-1;
        int arr[a];
        for(int j=0;j<a;j++)
        {
            cin>>arr[j];
            if(arr[j]>=0 && start==-1)
            {
                start = j;
            }
            
            if(arr[j]<0 && start!=-1 && end==-1)
            {
                end = j-1;
            }
            if(start!=-1 && end==-1)
            {
                count++;
            }
        }
        if(end==-1)
            end=a-1;
        temp1=-1;
        temp2=1;
        for(int j=end;j<a;j++)
        {
            if(arr[j]>0 && temp1==-1)
            {
                temp1=j;
                continue;
            }
            if(arr[j]>0 && temp1!=-1)
            {
                temp2++;
            }
            if((arr[j]<0 && temp1!=-1) || j==a-1)
            {
                if(temp2>count)
                {
                    count=temp2;
                    start = temp1;
                    end = j-1;
                }
                temp1=-1;
                temp2=1;
            }
        }
        int sum=0;
        for(int j=start;j<=end;j++)
        {
            sum+=arr[j];
        }
        if(sum==b && ans==0)
        {
            ans=1;
            cout<<"YES"<<endl;
            continue;
        }
        temp1=-1;
        temp2=1;
        for(int j=0;j<a;j++)
        {
            if(arr[j]>0 && temp1==-1)
            {
                temp1=j;
                continue;
            }
            if(arr[j]>0 && temp1!=-1)
            {
                temp2++;
            }
            if((arr[j]<0 && temp1!=-1) || j==a-1)
            {
                if(temp2==count)
                {
                    count=temp2;
                    start = temp1;
                    end = j-1;
                }
                sum=0;
                for(int j=start;j<=end;j++)
                {
                    sum+=arr[j];
                }
                if(sum==b && ans==0)
                {
                    ans=1;
                    cout<<"YES"<<endl;
                }
                temp1=-1;
                temp2=1;
            }
        }
        if(ans==0)
            cout<<"NO"<<endl;
    }
    return 0;
}