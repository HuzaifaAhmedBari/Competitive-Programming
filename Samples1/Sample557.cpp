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
void dfs(ll x, vector<unordered_set<ll>> &arr, vb &visited)
{
    visited[x] = true;
    for(auto y:arr[x])
    {
        if(!visited[y])
            dfs(y,arr,visited);
    }
}
int main()
{
    io;
    ll n,q;
    cin>>n>>q;
    vector<unordered_set<ll>> arr(n+1);
    vb visited(n+1,false);
    vl ans;
    while(q--)
    {
        ll c,d;
        cin>>c>>d;
        arr[c].insert(d);
        arr[d].insert(c);
    }
    fori(1,n+1)
    {
        if(!visited[i])
        {
            dfs(i,arr,visited);
            ans.push_back(i);
        }
    }
    ll s = ans.size()-1;
    cout<<s;
    nl;
    fori(0,s)
    {
        cout<<ans[i]<<" "<<ans[i+1];
        nl;
    }
    return 0;
}