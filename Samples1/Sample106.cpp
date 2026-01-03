#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    long long int t;
    t=3;
    long long int n,q;
    int i=0;
    while(cin>>n)
    {
        long long int arr[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        cin >> q;
        long long int ans[q];
        sort(arr,arr+n);
        long long int query[q];
        for(int j=0;j<q;j++)
        {
            cin>>query[j];
            ans[j] = LLONG_MIN;
        }
        cout << "Case " <<i+1<<":"<<endl;
        for(int j=0;j<q;j++)
        {
            for(int k=0;k<n-1;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    int sum = arr[k] + arr[l]; 
                    if(sum <= query[j])
                    {
                        if(ans[j]>query[j])
                        {
                            if(abs(sum - query[j]) < abs(ans[j] - query[j]))
                            {
                                ans[j] = sum;
                            }
                        }
                        else if(ans[j] < query[j])
                        {
                            if(sum>ans[j])
                            ans[j] = sum;
                        }
                    }
                    else if(sum > query[j])
                    {
                        if(abs(sum - query[j]) < abs(ans[j] - query[j]))
                        {
                            ans[j] = sum;
                        }
                        else if(ans[j] == INT_MIN)
                        {
                            ans[j] = sum;
                        }
                        break;
                    }
                }
            }
        }
        i++;
        for(int j=0;j<q;j++)
        {
            cout << "Closest sum to "<<query[j]<<" is "<<ans[j]<<"."<<endl;
        }

    }
}