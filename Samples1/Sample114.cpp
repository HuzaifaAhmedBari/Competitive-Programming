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
    int n,m;
    int sum;
    for(int i=0;i<t;i++)
    {
        sum=0;
        cin>>n>>m;
        m--;
        for(int j=0;j<n;j++)
        {
            sum += m;
            m--;
        }
        cout<<sum<<endl;
    }
    
}