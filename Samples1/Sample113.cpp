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
    int n;
    cin>>n>>t;
    for(int i=0;i<t;i++)
    {
        if(n%10!=0)
        {
            n--;
        }
        else{
            n/=10;
        }
    }
    cout<<n;
    
}