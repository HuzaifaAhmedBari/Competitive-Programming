#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    int ans1,ans2,temp1=INT_MAX,temp2=INT_MAX;
    int arr[t];
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    int n;
    cin>>n;
    for(int i=0;i<t-1;i++)
    {
        for(int j=i+1;j<t;j++)
        {
            if(arr[i] + arr[j] == n)
            {
                if(abs(arr[j] - arr[i]) < temp1)
                {
                    ans1 = arr[i];
                    ans2 = arr[j];
                    temp1 = abs(arr[j] - arr[i]);
                }
            }
        }
    }
    if(ans1<ans2)
    {
        cout<<"Peter should buy books whose prices are " << ans1 << " and " << ans2 <<"\n"<<endl;
    }
    else
    {
        cout<<"Peter should buy books whose prices are " << ans2 << " and " << ans1 <<"\n"<<endl;
    }
    return 0;
}