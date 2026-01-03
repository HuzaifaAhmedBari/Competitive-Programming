//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<endl
#define re return 0
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int n,x,t;
    cin>>n>>x>>t;
    vi arr(n);
    ll ans=0;
    ll end=-1;
    input(arr);
    for(int i=n-1,j=x;(i>=0 && j>0);i--,j--)
    {
        if(arr[i]>t)
        {
            ans+=t;
            end=i;
        }
        else
        {
            break;
        }
    }
    fori(0,end)
    {
        ans+=arr[i];
    }
    cout<<ans;
    nl;
    return 0;
}