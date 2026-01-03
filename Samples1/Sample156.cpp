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
    ll n,x;
    cin>>n>>x;
    ll count=0;
    if(x<=n)
    {
        count++;
    }
    if(x<n)
    {
        int temp = x+1;
        while(temp-- && temp > 1)
        {
            if(x%temp == 0 && x / temp <= n)
            {
                count++;
            }
        }
    }
    else
    {
        int temp = n+1;
        while(temp-- && temp>1)
        {
            if(x%temp == 0 && x / temp <= n)
            {
                count++;
            }
        }
    }
    cout<<count;
    nl;    
    return 0;
}