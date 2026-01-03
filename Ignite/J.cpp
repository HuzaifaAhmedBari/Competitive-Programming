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
    ll n;
    cin>>n;
    vll adj;
    unordered_map<ll,vl> m,idxs;
    unordered_map<ll,ll> starting;
    ll x=-1;
    cin.ignore();
    fori(0,n)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        ll x;
        vl temp;
        while(ss>>x)
        {
            temp.push_back(x);
            m[x].push_back(i);
        }
        starting[i] = temp.front();
        idxs[temp.front()].push_back(i);
        adj.push_back(temp);
    }
    unordered_map<ll,ll> s;
    ll start,last;
    cin>>start>>last;
    fori(0,n)
    {
        bool found1=false,found2=false;
        forj(0,adj[i].size())
        {
            if(adj[i][j]==start)
            {
                x = i;
                found1 = true;
            }
            if(adj[i][j]==last)
                found2=true;
        }
        if(found1 and found2)
        {
            cout<<0;
            nl;
            re;
        }
        if(x!=-1)
            break;
    }
    queue<pair<ll,ll>> q;
    
    q.push({start,-2});
    
    ll ans=-1;
    while(!q.empty())
    {
        auto [u,d] = q.front();
        q.pop();
        if(u==last)
        {
            ans = d;
            break;
        }
        for(auto x:m[u])
        {
            ll t ;
            if(!s.count(x))
            {
                ll found=-1;
                ll i=0;
                for(ll y:adj[x])
                {
                    if(u==y and found==-1)
                        found=i;
                    i++;
                    if(found==-1)
                        continue;
                    q.push({y,d+2});
                    t = found;
                }
            }
            ll j=0;
            if(starting.count(x))
            {
                for(ll v:adj[x])
                {
                    if(j>=t)
                        break;
                    q.push({v,d+3});
                    j++;
                }
                starting.erase(x);
                s[x] = 1;
            }
            s[x] = 1;
        }
    }
    cout<<ans;
    nl;
    return 0;
}