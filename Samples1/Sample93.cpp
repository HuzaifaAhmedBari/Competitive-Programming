#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,ans=0,temp;
    cin>>n;
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    for(int i=0;i<n;i++)
    {
        temp=arr1[i] - arr2[i];
        if(temp>0)
            ans+=temp;
    }
    cout<<ans;
    return 0;
}