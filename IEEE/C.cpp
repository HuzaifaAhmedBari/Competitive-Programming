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
    for(ll i=5;i*i<=n;i++)
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
struct Edge {
    ll u,v,w,c;
};
int main()
{
    io;
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<unordered_map<ll,pii>> adj(n+1);
        vector<Edge> a(m);
        vl cost(m);
        fori(0,m)
        {
            ll u,v,w,c;
            cin>>u>>v>>w>>c;
            if(not adj[u].count(v))
            {
                adj[u][v] = {w,c};
                adj[v][u] = {w,c};
            }
            else if(adj[u][v].sc>c)
            {
                adj[u][v] = {w,c};
                adj[v][u] = {w,c};
            }
            else if(adj[u][v].sc==c)
            {
                adj[u][v] = {min(w,adj[u][v].fs),c};
                adj[v][u] = {min(w,adj[v][u].fs),c};
            }
            a[i].u = u;
            a[i].v = v;
            a[i].w = w;
            a[i].c = c;
        }
        vb visited(n+1,false);
        ll mn = LLONG_MAX;

        function<ll()> chota = [&]() {
            vl dist(n+1, LLONG_MAX);
            dist[1] = LLONG_MIN;

            min_heap<pii> pq;
            pq.push({LLONG_MIN, 1});

            while (!pq.empty())
            {
                auto [d, u] = pq.top();
                pq.pop();
                if(d > dist[u])
                    continue;

                for (auto [v, w] : adj[u])
                {
                    if(max(dist[u],w.sc) < dist[v])
                    {
                        dist[v] = max(dist[u],w.sc);
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist[n];
        };
        
        vector<unordered_map<ll,ll>> aj(n+1);
        function<ll()> dijkstra = [&]() {
            vl dist(n+1, LLONG_MAX);
            dist[1] = 0;

            min_heap<pii> pq;
            pq.push({0, 1});

            while (!pq.empty())
            {
                auto [d, u] = pq.top();
                pq.pop();
                if(d > dist[u])
                    continue;

                for (auto [v, w] : aj[u])
                {
                    if(dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist[n];
        };
        mn = chota();
        fori(0,m)
        {
            if(a[i].c>mn)
                continue;
            if(not aj[a[i].u].count(a[i].v))
            {
                aj[a[i].u][a[i].v] = a[i].w;
                aj[a[i].v][a[i].u] = a[i].w;
            }
            else if(aj[a[i].u][a[i].v]>a[i].w)
            {
                aj[a[i].u][a[i].v] = a[i].w;
                aj[a[i].v][a[i].u] = a[i].w;
            }
        }
        ll ans = dijkstra();
        if(ans==LLONG_MAX)
        {
            cout<<-1;
        }
        else
        {
            cout<<mn<<" "<<ans;
        }
        nl;
    }
    return 0;
}