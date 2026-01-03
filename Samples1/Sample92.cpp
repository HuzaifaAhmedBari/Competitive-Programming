#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int comp1(const void*a, const void*b)
{
    return *(int *)a - *(int *)b;
}
int comp2(const void*b, const void*a)
{
    return *(int *)a - *(int *)b;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n-1];
        for(int j=0;j<n-1;j++)
        {
            cin>>arr[j];
        }
        int sum;
        if(arr[0] > arr[1])
        {
            sum = arr[1] - arr[0];
            cout<<sum<<' ';
            for(int j=0;j<n-1;j++)
        {
            if(j<n-2)
                cout<<arr[j] - sum<<' ';
            else
                cout<<arr[j];
            sum = arr[j] - sum;
        }
        }
        else
        {
            sum = arr[n-1] - arr[n-2];
            cout<<sum<<' ';
            for(int j=n-1;j>=0;j++)
        {
            if(j<n-2)
                cout<<arr[j] - sum<<' ';
            else
                cout<<arr[j];
            sum = arr[j] - sum;
        }
        }
            
        
        
        
        cout<<endl;
    }
    return 0;
}