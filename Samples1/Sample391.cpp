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
    unordered_map<ll,vl> y;
    ll n,q;
    cin>>n>>q;
    fori(0,n)
    {
        y[i+1].push_back(i+1);
    }
    while(q--)
    {
        ll a;
        cin>>a;
        if(a==1)
        {
            ll b,c;
            cin>>b>>c;
            fori(1,n+1)
            {
                auto it = find(y[i].begin(),y[i].end(),b);
                if(it != y[i].end())
                {
                    y[i].erase(it);
                    break;
                }
            }
            y[c].push_back(b);
        }
        else if(a==2)
        {
            ll b,c;
            cin>>b>>c;
            // fori(1,n+1)
            // {
            //     if(x[i]==b)
            //     {
            //         x[i] = c;
            //     }
            //     else if(x[i] == c)
            //         x[i] = b;
            // }
            vl arr;
            arr = y[b];
            y[b].clear();
            y[b] = y[c];
            y[c].clear();
            y[c] = arr;
        }
        else
        {
            ll b;
            cin>>b;
            bool flag=false;
            fori(1,n+1)
            {
                for(auto x : y[i])
                {
                    if(x==b)
                    {
                        cout<<i;
                        nl;
                        flag=true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
    }
    return 0;
}