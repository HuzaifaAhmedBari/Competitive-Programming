//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<endl
#define re return 0
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t;
    cin>>t;
    vector<int> arr(t);
    ll j=0;
    ll k=0;
    int i=0;
    bool flag=true,ans = true;
    fori(0,t)
    {
        cin>>arr[i];
        if(i>0)
        {
            if(arr[i-1]>arr[i])
            {
                if(j!=k)
                {
                    j=i+1;
                    flag=false;
                }
                flag=false;
            }
            else
            {
                if(!flag)
                    k=i;
                flag=true;
            }
            if(j>k && flag)
            {
                ans=false;
            }
        }
    }
    if(j==0)
    {
        j=1;
    }
    if(k==0)
    {
        k=t;
    }
    if(ans)
    {
        cout<<"yes";
        nl;
        cout<<j<<" "<<k;
        nl;
    }
    else
    {
        cout<<"no";
        nl;
    }
    return 0;
}