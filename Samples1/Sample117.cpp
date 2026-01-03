#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        char a;
        cin>>a;
        int n,m;
        cin>>n>>m;
        int arr1[n],arr2[m];
        for(int j=0;j<n;j++)    cin>>arr1[i];
        for(int j=0;j<m;j++)    cin>>arr2[i];
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        int min = arr2[0];
    }
}