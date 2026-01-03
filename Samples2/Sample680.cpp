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
    ll n,x;
    cin>>n>>x;
    vector<vector<pair<ll,ll>>> arr(n+1);
    vll arr2(n+1);
    fori(0,x)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        if(find(all(arr2[u]),v)!=arr2[u].end())
        {
            ll d = distance(arr2[u].begin(),find(all(arr2[u]),v));
            arr[u][d] = {v,min(w,arr[u][d].second)};
        }
        else
        {
            arr[u].push_back({v,w});
            arr2[u].push_back(v);
        }
        if(find(all(arr2[v]),u)!=arr2[v].end())
        {
            ll d = distance(arr2[v].begin(),find(all(arr2[v]),u));
            arr[v][d] = {u,min(w,arr[v][d].second)};
        }
        else
        {
            arr[v].push_back({u,w});
            arr2[v].push_back(u);
        }
    }
    vl dist(n+1,LLONG_MAX);
    vl path(n+1,0);
    function<void()>dijkstra = [&](){
        dist[1] = 0;
        path[1] = 0;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({dist[1],1});
        while(!pq.empty())
        {
            ll u = pq.top().second;
            ll cur = pq.top().first;
            pq.pop();
            if(cur>dist[u])
                continue;
            for(auto [v,w]:arr[u])
            {
                if(dist[v]>dist[u]+w)
                {
                    dist[v] = dist[u]+w;
                    path[v] = u;
                    pq.push({dist[v],v});
                }
            }
        }
    };
    dijkstra();
    if(path[n]==0 || dist[n]==LLONG_MAX)
    {
        cout<<-1;
        nl;
        re;
    }
    vl go;
    ll cur = n;
    while(cur!=0)
    {
        go.push_back(cur);
        cur = path[cur];
    }
    reverse(all(go));
    if(*go.begin()!=1)
    {
        cout<<-1;
        nl;
        re;
    }
    print(go);
    nl;
    return 0;
}