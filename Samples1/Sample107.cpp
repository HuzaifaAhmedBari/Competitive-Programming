#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int comp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
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
        if(arr[1] < arr[0])
            sort(arr, arr+n);
        else
            qsort(arr,n-1, sizeof(int), comp);
            
        int sum = arr[0]/2;
        cout<<sum<<' ';
        for(int j=0;j<n-1;j++)
        {
            cout<<arr[j] - sum<<' ';
            sum = arr[j] - sum;
        }
        cout<<endl;
    }
    return 0;
}