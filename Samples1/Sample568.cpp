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
ll f(vl &arr,ll n, ll l, ll r)
{
    static ll suml=0,sumr=0;
    if(l>r)
    {
        return abs(sumr-suml);
    }
    if(suml<=sumr)
    {
        suml+=arr[l];
        return f(arr,n,l+1,r);
    }
    else
    {
        sumr+=arr[r];
        return f(arr,n,l,r-1);
    }
}
int main()
{
    io;
    ll n;
    cin>>n;
    vl arr(n);
    input(arr);
    cout<<f(arr,n,0,n-1);
    return 0;
}