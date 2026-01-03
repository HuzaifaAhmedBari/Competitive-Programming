#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m,a,b,flag=0,ans=0;
    cin>>n>>m;
    int fre[n+1];
    for(int i=0;i<=n;i++)   fre[i] = 1;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        fre[b] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(fre[i] == 1)
        {
            ans = i;
            flag += 1;
        }
    }
    if(flag==1)
    {
        cout<<ans;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}