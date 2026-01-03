#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n,q;
    int max=INT_MIN;
    cin>>n>>q;
    int min1=INT_MAX,min2=INT_MAX;
    int arr[n];
    int index=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        max = (arr[i]>max)? arr[i] : max;
        if(arr[i]<min1)
        {    
            min1=arr[i];
            index=i;
        }
        if(arr[i]<=min2 && i!= index)
        {
            min2=arr[i];
            
        }
    }
    long long int sum1=min1;
    long long int sum2=0;
    
    if(max == q)
        sum1+=max - min2;
    else
    {
        sum1+=q-max;
        sum1+=max - min2;
    }
    sum2+=max - min1;
    
    (sum1<sum2)? cout<<sum1<<endl:cout<<sum2<<endl;
}