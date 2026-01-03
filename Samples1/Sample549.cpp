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
void f(vector<unordered_set<ll>> &arr, vb &visited, vl &check, ll &x, ll &k, ll &count)
{
    visited[x]=true;
    for(auto y:arr[x])
    {
        fori(0,check.size())
        {
            if(abs(check[i]-y)<=k)
                count++;
        }
        vl checka(check.begin(),check.end());
        checka.push_back(y);
        if(visited[y]==false)
            f(arr,visited,checka,y,k,count);
    }
}
int main()
{
    io;
    ll n,k;
    cin>>n>>k;
    ll t=n-1;
    vector<unordered_set<ll>> arr(n+1);
    while(t--)
    {
        ll c,d;
        cin>>c>>d;
        arr[c].insert(d);
    }
    ll count=0;
    vb visited(n+1,false);
    fori(1,n+1)
    {
        vl check;
        if(visited[i]==true)
            continue;
        check.push_back(i);
        for(auto x:arr[i])
        {
            visited[i]=true;
            if(abs(x-i)<=k)
                count++;
            vl checka(check.begin(),check.end());
            checka.push_back(x);
            f(arr,visited,checka,x,k,count);
        }
    }
    cout<<count;
    nl;
    return 0;
}