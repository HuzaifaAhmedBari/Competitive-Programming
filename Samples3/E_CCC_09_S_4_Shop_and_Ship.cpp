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
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define fs first
#define sc second
#define MOD 1000000007
#define pii pair<int,int>
#define vl vector<int>
#define vll vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pair<int,int>>>
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
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int r=a;r>=b;r--)
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

map<int,int> st;
vl parent;
vl dijkstra(int n, int source, vvpii &adj)
{
    vl dist(n+1, INT_MAX);
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
            if(dist[u] + w< dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
vl getPath(int target) {
    vl path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}
struct Edge {
    int u,v,w;
    Edge() : u(0), v(0), w(0) {}
    Edge(int a,int b,int c) : u(a), v(b), w(c) {}
    bool operator<(const Edge other) {
        if(u!=other.u)
            return u<other.u;
        if(v!=other.v)
            return v<other.v;
        return w<other.w;
    }
};

int main()
{
    io;
    int n;
    cin>>n;
    vvpii adj(n);
    int m;
    cin>>m;
    vector<Edge> e(m);
    fori(0,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        if(u>v)
            swap(u,v);
        e[i] = Edge(u,v,w);
    }
    sahi(e);
    pii cur = pii{e[0].u,e[0].v};
    adj[cur.fs].push_back({cur.sc,e[0].w});
    adj[cur.sc].push_back({cur.fs,e[0].w});
    fori(1,m)
    {
        if(cur==pii{e[i].u,e[i].v})
            continue;
        cur = pii{e[i].u,e[i].v};
        adj[cur.fs].push_back({cur.sc,e[i].w});
        adj[cur.sc].push_back({cur.fs,e[i].w});
    }
    int q;
    cin>>q;
    vl check(q);
    fori(0,q)
    {
        int u,x;
        cin>>u>>x;
        u--;
        st[u] = x;
        check[i] = u;
    }
    int d;
    cin>>d;
    d--;
    vl dist = dijkstra(n, d, adj);
    int mn = INT_MAX;
    fori(0,q)
    {
        mn = min(mn,dist[check[i]]+st[check[i]]);
    }
    cout<<mn;
    nl;
    return 0;
}