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
void f(ll o, ll x, vector<unordered_set<ll>> &road, vb &visited, vll &ans)
{
    visited[x] = true;
    for(auto y : road[x])
    {
        ans[o][y]=1;
        ans[y][o]=1;
        if(!(road[y].empty()) && visited[y]==false)
        {
            f(o,y,road,visited,ans);
        }
    }
}
void z(ll o, ll x, vector<unordered_set<ll>> &rail, vb &visited, vll &ans)
{
    visited[x] = true;
    for(auto y : rail[x])
    {
        if(ans[o][y]==1)
            ans[o][y]=2;
        if(ans[y][o]==1)
            ans[y][o]=2;
        if(!(rail[y].empty()) && visited[y]==false)
        {
            z(o,y,rail,visited,ans);
        }
    }
}
int main()
{
    io;
    ll n,r,p;
    cin>>n>>r>>p;
    vll ans(n+1,vl(n+1,0));
    vb visited(n+1);
    vector<unordered_set<ll>> road(n+1);
    vector<unordered_set<ll>> rail(n+1);
    while(r--)
    {
        ll c,d;
        cin>>c>>d;
        road[c].insert(d);
        road[d].insert(c);
    }
    while(p--)
    {
        ll c,d;
        cin>>c>>d;
        rail[c].insert(d);
        rail[d].insert(c);
    }
    fori(1,n+1)
    {
        if(road[i].empty())
        {
            continue;
        }
        visited.assign(n+1,false);
        if(!(road[i].empty()))
        {
            for(auto x:road[i])
            {
                ans[i][x]=1;
                ans[x][i]=1;
                if(!(road[x].empty()))
                    f(i, i, road, visited, ans);
            }
        }
    }
    fori(1,n+1)
    {
        if(rail[i].empty())
        {
            continue;
        }
        visited.assign(n+1,false);
        {
            if(!(rail[i].empty()))
            {
                for(auto x:rail[i])
                {
                    if(ans[i][x]==1)
                        ans[i][x]=2;
                    if(ans[x][i]==1)
                        ans[x][i]=2;
                    if(!(rail[x].empty()))
                        z(i, i, rail, visited, ans);
                }
            }
        }
    }
    fori(1,n+1)
    {
        ans[i][i]=2;
    }
    fori(1,n+1)
    {
        cout<<count(ans[i].begin()+1,ans[i].end(),2)<<" ";
    }
    nl;
    return 0;
}