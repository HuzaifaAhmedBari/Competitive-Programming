#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,temp,sum,a;
    cin>>t;
    int ans[t] = {0};
    for(int i=0;i<t;i++)
    {
        int n;
        sum=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            sum+=temp;
        }
        a=((n+1)*100*0.5)-sum;
        if(a<0)
        {
            ans[i] = 0;
        }
        else if(a>100)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = a;
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}