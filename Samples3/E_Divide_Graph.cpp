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
const ll MOD = 998244353;
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

class DSU {
public:
    ll n, components;
    vl parent, size;

    DSU(int n) : n(n), components(n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        iota(all(parent), 0);
    }

    ll find(ll x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;

        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        components--;
        return true;
    }

    bool connected(ll a, ll b) {
        return find(a) == find(b);
    }

    ll getSize(ll x) {
        return size[find(x)];
    }
};

struct Edge {
    ll u, v, w;
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};

vb kruskal(ll n, vector<Edge> &edges) {
    vb used(edges.size()+1,false);
    used[0] = true;
    reverse(all(edges));
    DSU dsu(n);

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            used[e.w] = true;
            // store edge (e.u, e.v) if needed
        }
    }
    return used;
}

// Precompute factorials and inverse factorials for nCr and nPr
const ll MoD = 998244353;
vl fact, invfact;

ll modpow(ll a, ll b, ll m = MoD) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void build_fact(ll n) {
    fact.assign(n+1, 1);
    invfact.assign(n+1, 1);

    for (ll i = 1; i <= n; i++)
        fact[i] = (fact[i-1] * i) % MoD;

    invfact[n] = modpow(fact[n], MoD-2, MoD); // Fermat's inverse

    for (ll i = n-1; i >= 0; i--)
        invfact[i] = (invfact[i+1] * (i+1)) % MoD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invfact[r]) % MoD) * invfact[n-r]) % MoD;
}

ll nPr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return (fact[n] * invfact[n-r]) % MoD;
}

int main()
{
    io;
    ll n,m;
    cin>>n>>m;
    vector<Edge> e(m);
    fori(0,m)
    {
        cin>>e[i].u>>e[i].v;
        e[i].w = i+1;
    }
    vb used = kruskal(n,e);
    reverse(all(e));
    ll ans = 0;
    fori(1,m+1)
    {
        if(used[i])
        {
            used[i] = false;
            break;
        }
    }
    DSU d(n);
    fori(1,m+1)
    {
        if(used[i])
        {
            d.unite(e[i-1].u,e[i-1].v);
        }
    }
    fori(1,m+1)
    {
        if(not used[i])
        {
            if(d.find(e[i-1].u)==d.find(e[i-1].v))
            {
                d.unite(e[i-1].u,e[i-1].v);
                used[i] = true;
            }
        }
    }
    fori(1,m+1)
    {
        if(not used[i])
        {
            ans = (ans+modpow(2,i))%MOD;
        }
    }
    cout<<ans;
    nl;
    return 0;
}