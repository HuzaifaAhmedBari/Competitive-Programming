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
#define us unordered_set<ll>
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
istream& operator>>(istream &in, vector<pair<A,B>> &vp) {
    for (auto &p : vp) in >> p.first >> p.second;
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
template <typename A, typename B>
ostream& operator<<(ostream &out, const vector<pair<A,B>> &vp) {
    for (auto &p : vp) out << p.first << " " << p.second << "\n";
    return out;
}

vb is_prime;
void sieve(ll n) {
    is_prime.assign(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for(ll i=2;i*i<=n;i++) {
        if(is_prime[i]) {
            for(ll j=i*i;j<=n;j+=i)
                is_prime[j] = false;
        }
    }
}
bool isprime(ll n) {
    if(n<2)	return false;
    if(n==2 || n==3)	return true;
    if(n%2==0 || n%3==0)	return false;
    for(ll i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
ll nextprime(ll n)	{ return (isprime(n))? n : nextprime(n+1); }
ll sum_digits(ll n)	{ return (n<10)? n : n%10 + sum_digits(n/10); }
ll gcd(ll a, ll b)	{ return (b==0)? a : gcd(b,a%b); }
ll lcm(ll a, ll b)	{ return (a*b)/gcd(a,b); }

struct HopcroftKarp {
    ll n, m;  
    vll adj;
    vl dist, matchL, matchR;

    HopcroftKarp(ll n, ll m) : n(n), m(m) {
        adj.resize(n);
        dist.resize(n);
        matchL.assign(n, -1);
        matchR.assign(m, -1);
    }

    void addEdge(ll u, ll v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<ll> q;
        for(ll u = 0; u < n; u++)
        {
            if(matchL[u] == -1)
            {
                dist[u] = 0;
                q.push(u);
            }
            else
            {
                dist[u] = LLONG_MAX;
            }
        }

        bool found = false;

        while(not q.empty())
        {
            ll u = q.front();
            q.pop();
            for(ll v : adj[u])
            {
                ll w = matchR[v];
                if(w == -1)
                {
                    found = true;
                }
                else if(w != -1 && dist[w] == LLONG_MAX)
                {
                    dist[w] = dist[u] + 1;
                    q.push(w);
                }
            }
        }
        return found;
    }

    bool dfs(ll u) {
        for(ll v : adj[u])
        {
            ll w = matchR[v];
            if(w == -1 || (dist[w] == dist[u] + 1 && dfs(w)))
            {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dist[u] = LLONG_MAX;
        return false;
    }

    ll maxMatching()
    {
        ll matching = 0;
        while(bfs())
        {
            for(int u = 0; u < n; u++)
            {
                if(matchL[u] == -1 && dfs(u))
                    matching++;
            }
        }
        return matching;
    }
};

int main()
{
    io;
    ll n;
    cin>>n;
    // vll adj(n+1);
    // ll count = 0;
    // map<ll,ll> m;
    // fori(0,n)
    // {
    //     ll u,v;
    //     cin>>u>>v;
    //     adj[i+1].push_back(u+v);
    //     adj[i+1].push_back(u-v);
    // }
    // function<bool(ll,map<ll,ll>&)> dfs = [&](ll u, map<ll,ll> &visited) {
    //     for(ll v:adj[u])
    //     {
    //         if(visited[v])
    //             continue;
    //         visited[v] = 1;
    //         if(m[v]==0 or dfs(m[v], visited))
    //         {
    //             m[v] = u;
    //             return true;
    //         }
    //     }
    //     return false;
    // };
    // fori(1,n+1)
    // {
    //     map<ll,ll> visited;
    //     if(dfs(i,visited))
    //         count++;
    // }
    // cout<<count;
    // nl;
    vpii arr(n);
    cin>>arr;
    map<ll,ll> m;
    vl r(n);
    fori(0,n)
    {
        r.push_back(arr[i].fs+arr[i].sc);
        r.push_back(arr[i].fs-arr[i].sc);
    }
    set<ll> s(all(r));
    r.clear();
    for(ll x:s)
        r.push_back(x);
    ll d = r.size();
    fori(0,d)
    {
        m[r[i]] = i;
    }
    HopcroftKarp h(n,d);
    fori(0,n)
    {
        ll u = arr[i].fs+arr[i].sc;
        ll v = arr[i].fs-arr[i].sc;
        h.addEdge(i,m[u]);
        h.addEdge(i,m[v]);
    }
    cout<<h.maxMatching();
    nl;
    return 0;
}