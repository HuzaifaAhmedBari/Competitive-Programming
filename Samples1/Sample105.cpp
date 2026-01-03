#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int sum=0;
    long long int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr,arr+n);
    long long int ans = max(arr[n-1]*2,sum);
    cout<<ans;

}