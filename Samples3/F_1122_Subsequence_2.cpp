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
#define MOD 998244353
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
// Precompute factorials and inverse factorials for nCr and nPr
const ll MoD = 1e9+7;
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
    string s;
    cin>>s;
    build_fact((1e6)+5);
    ll n = s.size();
    vector<array<int,11>> pre(n,{0}), suf(n,{0});
    forr(n-1,0)
    {
        ll c = s[r]-'0';
        if(r==n-1)
        {
            suf[r][c]++;
            continue;
        }
        fori(0,10)
        {
            suf[r][i]+=suf[r+1][i];
        }
        suf[r][c]++;
    }
    fori(0,n)
    {
        ll c = s[i]-'0';
        if(i==0)
        {
            pre[i][c]++;
            continue;
        }
        forj(0,10)
        {
            pre[i][j]+=pre[i-1][j];
        }
        pre[i][c]++;
    }
    map<ll,ll> m;
    ll ans = 0;
    fori(0,n)
    {
        ll c = s[i]-'0';
        // ll before=0;
        // if(i!=0)
        //     before = pre[i-1][c];
        // before++;
        // ll after = suf[i+1][c+1];
        // ll mn = min(after,before);
        // ans += ((((mn)*((2*(after-mn+1))+(mn-1)))/2)%MOD);
        // cout<<(((mn)*((2*(after-mn+1))+(mn-1)))/2);
        if(i==0 or c==0)
            continue;
        if(pre[i-1][c-1]==0)
            continue;
        ll z = pre[i-1][c-1];
        z-=m[c-1];
        ll mn = min(z,(ll)suf[i][c]);
        forj(1,mn+1)
        {
            ans += (nCr(z,j)*nCr(suf[i][c],j)%MOD);
        }
        m[c-1]+=z;
    }
    cout<<ans;
    nl;
    return 0;
}