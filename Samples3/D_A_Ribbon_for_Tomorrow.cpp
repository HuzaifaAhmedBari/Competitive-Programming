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
    ll t = 1;
    cin>>t;
    build_fact((ll)(1e6+5));
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll z = 0, o = 0;
        ll cnt0 = count(all(s),'0');
        ll cnt1 = n-cnt0;
        fori(0,n)
        {
            char cur = s[i];
            while(i<n and s[i]==cur)
            {
                i++;
            }
            i--;
            if(cur=='0')
                z++;
            else
                o++;
        }
        ll a = 1, b = 1;
        if(z)
            a = nCr(cnt0-1,z-1);
        if(o)
            b = nCr(cnt1-1,o-1);
        ll ans = (a%MOD*b%MOD)%MOD;
        cout<<ans;
        nl;
    }
    return 0;
}