#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int arr2[m];
    for(int j=0;j<m;j++)
    {
        cin>>arr2[j];
    }
    sort(arr2,arr2+m);
    int ans=0;
    int temp = INT_MAX;
    int diff;
    for(int i=m-1;i>=0;i--)
    {
        temp = INT_MAX;
        for(int j=n-1;j>=0;j--)
        {
            diff = arr[j] - arr2[i];
            if(diff>=0 && diff < temp)
            {
                temp = diff;
            }
            if(arr[j] < arr2[i])
                break;
        }
        ans+=temp;
    }
    cout<<ans;
    return 0;
}