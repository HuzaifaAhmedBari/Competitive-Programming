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
#define input(vec) fork(0,vec.size()) cin>>vec[k]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t = 1;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vl arr(n);
        input(arr);
        ulta(arr);
        vl pre(n,0);
        pre[0] = arr[0];
        fori(1,n)
        {
            pre[i] = pre[i-1] + arr[i];
        }
        while(q--)
        {
            ll x;
            cin>>x;
            if(x>pre[n-1])
            {
                cout<<-1;
                nl;
                continue;
            }
            // fori(0,n)
            // {
            //     if(pre[i]>=x)
            //     {
            //         cout<<i+1;
            //         nl;
            //         break;
            //     }
            // }
            ll low = 0;
            ll high = n-1;
            ll a = distance(pre.begin(),lower_bound(all(pre),x))+1;
            cout<<a;
            nl;
        }
    }
    return 0;
}