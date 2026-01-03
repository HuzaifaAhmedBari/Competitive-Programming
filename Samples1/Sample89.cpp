#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        int maxwant = 0;
        int mingive = INT_MAX;
        int arr1[n], arr2[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr1[j];
        }
        int diff[n] = {0};
        for(int j=0;j<n;j++)
        {
            cin>>arr2[j];
            int ans = arr1[j] - arr2[j];
            if(ans < 0)
            {
                maxwant += abs(ans);
                diff[j] = abs(ans);
            }
            else if(ans > 0)
            {
                if(mingive > ans)
                    mingive = abs(ans);
            }
        }
        int ans = mingive-maxwant;
        for(int j=0;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(diff[j] == diff[k] && diff[j]!= 0)
                {
                    ans = -1;
                }
            }
        }
        if(ans >= 0)
        {
            cout<<"YES"<<endl;
            cout<<maxwant<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
