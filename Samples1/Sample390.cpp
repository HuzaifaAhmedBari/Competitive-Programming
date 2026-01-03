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
    unordered_map<ll,ll> m;
    ll n,q;
    cin>>n>>q;
    fori(0,n)
    {
        m[i+1]=i+1;
    }
    while(q--)
    {
        ll a;
        cin>>a;
        if(a==1)
        {
            ll b,c;
            cin>>b>>c;
            m[b] = c;
        }
        else if(a==2)
        {
            ll b,c;
            cin>>b>>c;
            fori(1,n+1)
            {
                if(m[i]==b)
                {
                    m[i] = c;
                }
                else if(m[i] == c)
                    m[i] = b;
            }
        }
        else
        {
            ll b;
            cin>>b;
            cout<<m[b];
            nl;
        }
    }
    return 0;
}