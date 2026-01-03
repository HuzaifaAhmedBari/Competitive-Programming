#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
    int t,n,c,m;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>c;
        int big[100][100] = {0};
        int fre[100] = {0};
        int minsum=0;
        int maxsum=0;
        for(int j=0;j<c;j++)
        {
            int min = INT_MAX;
            int max = INT_MIN;
            cin>>m;
            int arr[m];
            fre[c] = m;
            for(int k=0;k<m;k++)
            {
                cin>>arr[k];
                if(min>arr[k])
                    min=arr[k];
                if(max<arr[k])
                    max=arr[k];
                big[j][k] = arr[k];
            }
            minsum+=min;
            maxsum+=max;
        }
        if(minsum>n)
        {
            cout<<"-1"<<endl;
            continue;
        }
        else if(maxsum<=n)
        {
            cout<<maxsum<<endl;
            continue;
        }
    }  
    return 0;
}