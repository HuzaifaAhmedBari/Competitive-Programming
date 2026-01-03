#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum=0;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++)    cin>>arr1[i];
    for(int i=0;i<n;i++)    cin>>arr2[i];
    for(int i=0;i<n;i++)
    {
        if(arr1[i]%2==1)
            sum++;
    }
    (sum%2)? cout<<"1":cout<<"0";
}