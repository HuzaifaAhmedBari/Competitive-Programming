//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//find_by_order(k): returns iterator to k-th smallest element (0-based)
//order_of_key(x): returns number of elements strictly less than x
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define fs first
#define sc second
#define MOD 1000000007
#define pii pair<ll,ll>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vpii vector<pair<ll,ll>>
#define vvpii vector<vector<pair<ll,ll>>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define vc vector<char>
#define vcc vector<vector<char>>
#define vs vector<string>
#define vss vector<vector<string>>
#define all(vec) vec.begin(), vec.end()
#define allr(vec) vec.rbegin(), vec.rend()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)

template <typename A, typename B>
istream& operator>>(istream &in, pair<A,B> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
istream& operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}

template <typename A, typename B>
ostream& operator<<(ostream &out, const pair<A,B> &p) {
    out << p.first << " " << p.second;
    return out;
}
template <typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (auto &x : v) out << x << " ";
    return out;
}

int main()
{
    io;
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ll n,q;
    cin>>n>>q;
    vll arr(n,vl(n,LLONG_MAX));
    vvpii adj(n);
    fori(1,n)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vl dist(n,LLONG_MAX);
    vb visited(n,false);
    function<void(ll,ll)>dfs = [&](ll u, ll cur) {
        visited[u] = true;
        dist[u] = cur;
        for(auto [v,w]:adj[u])
        {
            if(not visited[v])
            {
                dfs(v, min(cur,w));
            }
        }
    };
    fori(0,n)
    {
        dist.assign(n,LLONG_MIN);
        visited.assign(n,false);
        dfs(i, LLONG_MAX);
        arr[i] = dist;
    }
    while(q--)
    {
        ll u,v;
        cin>>v>>u;
        u--;
        ll ans = 0;
        fori(0,n)
        {
            if(u==i)
                continue;
            if(arr[u][i]>=v)
                ans++;
        }
        cout<<ans;
        nl;
    }
    return 0;
}