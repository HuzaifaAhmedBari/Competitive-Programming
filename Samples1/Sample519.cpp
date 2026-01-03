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
void f(ll x, vector<unordered_set<ll>> &a, vb &arr, vb &jachuka)
{
    jachuka[x] = true;
    for(auto y:a[x])
    {
        arr[y]=true;
        if(!(a[y].empty()) && jachuka[y]==false)
            f(y, a, arr, jachuka);
    }
}
int main()
{
    io;
    ll n,q;
    cin>>n>>q;
    vb arr(n+1,false);
    vector<unordered_set<ll>> a(n+1);
    vb jachuka(n+1,false);
    while(q--)
    {
        ll c,d;
        cin>>c>>d;
        a[c].insert(d);
        a[d].insert(c);
    }
    arr[1] = true;
    for(auto x:a[1])
    {
        arr[x] = true;
        f(x, a, arr, jachuka);
    }
    bool flag=false;
    fori(1,n+1)
    {
        if(arr[i]==false)
        {
            flag=true;
            cout<<i;
            nl;
        }
    }
    if(!flag)
    {
        cout<<"Connected";
        nl;
    }
    return 0;
}