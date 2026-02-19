#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    vector<bool> used(n,false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(arr[i].first>arr[j].first and arr[i].second<arr[j].second)
                used[i] = true;
        }
    }
    cout<<count(used.begin(),used.end(),true);
}