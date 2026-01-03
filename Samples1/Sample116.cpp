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
    int counter=1;
    int ans=0;
    for(int i=n/2;i>=1;i--)
    {
        if(i==n/2 && i%n!=0)
        {
            i=i-(n%i);
        }
        if(n%i==0)
        {
            ans = i;
            break;
        }
    }
    if(n==1)
        cout<<0<<endl;
    else
        cout<<n-ans;
}