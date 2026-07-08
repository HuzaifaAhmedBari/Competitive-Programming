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

vl parent;
vl dijkstra(ll n, ll source, vector<map<ll,ll>> &adj)
{
    vl dist(n+1, LLONG_MAX);
    parent.assign(n+1, -1); // For path reconstruction
    dist[source] = 0;

    priority_queue<pii, vpii, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
            else if(dist[u] + w == dist[v])
            {
                if(u!=1)
                {
                    parent[v] = u;
                }
            }
        }
    }
    return dist;
}
vl getPath(ll target) {
    vl path;
    for (ll v = target; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    io;
    ll n,m,q;
    cin>>n>>m>>q;
    vector<map<ll,ll>> road(n+1), rail(n+1);
    vb chk(n+1,false);
    map<ll,ll> cnt;

    fori(0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        if(not road[u].count(v))
        {
            road[u][v] = w;
            road[v][u] = w;
            rail[u][v] = w;
            rail[v][u] = w;
        }
        else
        {
            road[u][v] = min(road[u][v],w);
            road[v][u] = min(road[v][u],w);
            rail[u][v] = min(road[u][v],w);
            rail[v][u] = min(road[v][u],w);
        }
    }
    fori(0,q)
    {
        ll v,w;
        cin>>v>>w;
        if(not rail[1].count(v))
            chk[v] = true;
        else
        {
            if(w<rail[1][v])
                chk[v] = true;
        }
        if(not rail[1].count(v))
            rail[1][v] = w;
        else
            rail[1][v] = min(rail[1][v],w);
        cnt[v]++;
    }
    vl dist1 = dijkstra(n, 1, road);
    vl dist2 = dijkstra(n, 1, rail);
    ll ans = 0;
    fori(2,n+1)
    {
        if(dist2[i]<dist1[i] and dist2[i]==rail[1][i] and parent[i]==1 and chk[i])
        {
            ans += cnt[i]-1;
        }
        else
        {
            ans += cnt[i];
        }
    }
    cout<<ans;
    nl;

    return 0;
}