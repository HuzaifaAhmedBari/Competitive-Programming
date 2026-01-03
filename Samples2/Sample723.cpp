//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define pii pair<ll,ll>
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
    ll n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n+1);
    fori(0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vl fre(n+1,0);
    function<void()>cycle = [&](){
        ll count=0;
        fori(1,n+1)
        {
            for(auto [v,w]:adj[i])
            {
                fre[v]++;
            }
        }
        queue<ll> q;
        fori(1,n+1)
        {
            if(fre[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            ll u = q.front();
            q.pop();
            count++;
            for(auto [v,w]:adj[u])
            {
                fre[v]--;
                if(fre[v]==0)
                {
                    q.push(v);
                }
            }
        }
    };
    cycle();
    function<bool(ll,vb)>dfs1 = [&](ll u, vb visited){
        visited[u] = true;
        if(u==n)
            return true;
        for(auto [v,w]:adj[u])
        {
            if(!visited[v])
            {
                if(dfs1(v,visited)) return true;
            }
        }
        return false;
    };
    function<bool(ll,vb,ll)>dfs2 = [&](ll u, vb visited, ll x){
        visited[u] = true;
        if(u==x)
            return true;
        for(auto [v,w]:adj[u])
        {
            if(!visited[v])
            {
                if(dfs2(v,visited,x))   return true;
            }
        }
        return false;
    };
    fori(1,n+1)
    {
        vb visited(n+1,false);
        if(fre[i]!=0)
        {
            if(dfs1(i,visited))
            {
                visited.assign(n+1,false);
                if(dfs2(1,visited,i))
                {
                    cout<<"inf";
                    nl;
                    re;
                }
            }
        }
    }
    vl dist(n+1,LLONG_MIN);
    vb stack(n+1,false);
    function<void()>dijkstra = [&](){
        dist[1] = 0;
        priority_queue<pii> pq;
        pq.push({dist[1],1});
        while(!pq.empty())
        {
            ll d = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            if(d<dist[u])
                continue;
            for(auto [v,w]:adj[u])
            {
                if(dist[v]<dist[u]+w)
                {
                    dist[v] = dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
    };
    dijkstra();
    cout<<dist[n];
    nl;
    return 0;
}