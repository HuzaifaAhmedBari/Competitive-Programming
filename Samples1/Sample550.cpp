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
    ll n,m;
    cin>>n>>m;
    vl arr(n);
    input(arr);
    ll sum=0;
    ll l=0;
    ll ans=0;
    ll count=0;
    fori(0,n)
    {
        sum+=arr[i];
        if(arr[i]>m)
        {
            l=i+1;
            sum=0;
            count=0;
            continue;
        }
        if(sum>m)
        {
            count--;
            sum-=arr[l];
            l++;
            sum-=arr[i];
            i--;
            if(count<0)
            {
                l=i+1;
                sum=0;
                count=0;
            }
            continue;
        }
        count++;
        ans=max(count,ans);
    }
    ans=max(count,ans);
    cout<<ans;
    nl;
    return 0;
}