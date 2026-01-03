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
        ll n,a;
        cin>>n>>a;
        vl c(n), d(n);
        fori(0,n)
        {
            cin>>c[i]>>d[i];
        }
        ll l=1,r=1,ans=0,fuel=0,minl=LLONG_MAX,maxr=LLONG_MIN;
        fori(0,n)
        {
            fuel += c[i];
            minl=min(minl,d[i]);
            maxr=max(maxr,d[i]);
            ll temp = ((r-l+1)*a) - fuel - ((maxr-minl)*(maxr-minl));
            if(temp<0)
            {
                fuel = 0;
                l=i+1;
                r=i+1;
                minl=LLONG_MAX;
                maxr=LLONG_MIN;
                continue;
            }
            ans = max(ans,temp);
            r++;
        }
        cout<<ans;
        nl;
    }
    return 0;
}