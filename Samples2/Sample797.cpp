//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
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
    ll n,m,ans=0;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>> adj(m);
    fori(0,m)
    {
        cin>>adj[i].fs>>adj[i].sc.fs>>adj[i].sc.sc;
    }
    sort(all(adj),[](pair<ll,pair<ll,ll>> x, pair<ll,pair<ll,ll>> y){
        return x.sc.sc<y.sc.sc;
    });
    vl parent(n+1);
    fori(1,n+1)
        parent[i]=i;
    function<ll(ll)>findd = [&](ll x){
        if(x!=parent[x])
            parent[x] = findd(parent[x]);
        return parent[x];
    };
    function<bool(ll,ll)>unite = [&](ll a,ll b){
        a = findd(a);
        b = findd(b);
        if(a==b)
            return false;
        if(a<b)
            swap(a,b);
        parent[b] = a;
        return true;
    };
    fori(0,m)
    {
        if(unite(adj[i].fs,adj[i].sc.fs))
        {
            ans+=adj[i].sc.sc;
        }
    }
    map<ll,ll> ma;
    fori(1,n+1)
    {
        ma[findd(i)]++;
    }
    if(ma.size()>=2)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        cout<<ans;
    }
    nl;
    return 0;
}