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
    int n;
    cin>>n;
    vl arr(n);
    input(arr);
    ll t=0;
    ll sum = accumulate(all(arr),0LL);
    fori(0,n)
    {
        ll a=n-i+1;
        while(a!=0)
        {
            forj(i+1,n)
            {
                if(j+a<=n)
                {
                    sum+=arr[i]%1000000007LL;
                    for(ll k=j,h=0;(k<n && h<a);h++,k++)
                    {
                        sum+=arr[k]%1000000007LL;
                    }
                }
            }
            a--;
        }
    }
    cout<<sum%1000000007LL;
    nl;
    return 0;
}