#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int flag=1;
    cin>>n;
    char a[n+1];
    cin>>a;
    for(int i=0;i<=n;i++)
    {
        if(a[i] == '*')
        {
            flag = (flag)? 0 : 1;
        }
        if(flag==0)
            continue;
        if(a[i] == '*')
            continue;
        cout<<char(a[i]);
    }
    return 0;
}