//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define us unordered_set<ll>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    ll w,h,t;
    cin>>w>>h>>t;
    ll x1,y1,x2,y2;
    x1=0;
    x2=w;
    y1=0;
    y2=h;
    while(t--)
    {
        ll m,x,y;
        cin>>x>>y>>m;
        if(m==1)
        {
            x1 = max(x1,x);
        }
        else if(m==2)
        {
            x2 = min(x2,x);
        }
        else if(m==3)
        {
            y1 = max(y1,y);
        }
        else
        {
            y2 = min(y2,y);
        }
    }
    if(x2<=x1 || y2<=y1)
    {
        cout<<0;
        nl;
        re;
    }
    cout << (x2-x1) * (y2-y1);
    nl;
    return 0;
}