//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
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
#define print(vec) fori(1,vec.size()) cout<<vec[i]<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
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
int main()
{
    io;
    ll n,m,q;
    cin>>n>>m>>q;
    vll dist(n+1,vl(n+1,LLONG_MAX));
    vb done(n+1,false);
    vector<unordered_map<ll,ll>> adj(n+1);
    fori(0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        if(adj[u].count(v)==0)
        {
            adj[u][v] = w;
        }
        else
        {
            adj[u][v] = min(w,adj[u][v]);
        }
        if(adj[v].count(u)==0)
        {
            adj[v][u] = w;
        }
        else
        {
            adj[v][u] = min(w,adj[v][u]);
        }
    }
    function<void(ll)>dijkstra = [&](ll i){
        priority_queue<pii,vpii,greater<pii>> pq;
        dist[i][i] = 0;
        pq.push({dist[i][i],i});
        while(!pq.empty())
        {
            ll d = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            if(d>dist[i][u])
                continue;
            for(auto [v,w]:adj[u])
            {
                if(dist[i][v]>dist[i][u]+w)
                {
                    dist[i][v] = dist[i][u]+w;
                    pq.push({dist[i][v],v});
                }
            }
        }
    };
    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        if(!done[u])
            dijkstra(u);
        cout<<((dist[u][v]==LLONG_MAX)?-1:dist[u][v]);
        done[u] = true;
        nl;
    }
    return 0;
}