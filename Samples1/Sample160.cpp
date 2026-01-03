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
ll r,c,ans,want;
ll recurse(ll a)
{
    if(a==1)
    {
        return r;
    }
    else if(a==2)
    {
        return c;
    }
    else if(a==want)
    {
        return 0;
    }
    ans += c;
    return ans - recurse(a+1);
}
ll MOD = 1000000007;
int main()
{
    io;
    ll x,y,n;
    cin>>x>>y>>n;
    r = x;
    c = y;
    want = n;
    if(n==1)
    {
        if(x<0)
        {
            x+=MOD;
        }
        cout<<(x % MOD);
        nl;
        re;
    }
    if(n==2)
    {
        if(y<0)
        {
            y += MOD; 
        }
        cout<<y % MOD;
        nl;
        re;
    }
    ans = y;
    ll ans2 = (y - (recurse(1) + recurse(3)));
    if(ans2<0)
    {
        ans2+=MOD;
    }
    cout << ans2 % MOD;
    return 0;
}