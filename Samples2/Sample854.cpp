//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//find_by_order(k): returns iterator to k-th smallest element (0-based)
//order_of_key(x): retruns number of elements strictly less than x
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
int main()
{
    io;
    string s;
    cin>>s;
    ll n = s.size();
    vl tree(n*4,0);
    function<void(ll,ll,ll)> build = [&](ll idx, ll l,ll r) {
        if(l==r)
        {
            tree[idx] = (1LL<<(ll)(s[l]-'a'));
            return;
        }
        ll mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        tree[idx] = tree[idx*2] | tree[idx*2+1];
    };
    function<void(ll,ll,ll,ll,ll)> update = [&](ll idx,ll l, ll r,ll pos, char val) {
        if(l==r)
        {
            tree[idx] = (1LL<<(ll)(val-'a'));
            return;
        }
        ll mid = (l+r)/2;
        if(pos<=mid)
            update(idx*2,l,mid,pos,val);
        else
            update(idx*2+1,mid+1,r,pos,val);
        tree[idx] = tree[idx*2] | tree[idx*2+1];
    };
    function<ll(ll,ll,ll,ll,ll)> ans = [&](ll idx, ll l,ll r,ll a,ll b) {
        if(a>r or b<l)
            return 0LL;
        if(a<=l and b>=r)
            return tree[idx];
        ll mid = (l+r)/2;
        return (ans(idx*2,l,mid,a,b) | ans(idx*2+1,mid+1,r,a,b));
    };
    ll q;
    cin>>q;
    build(1,0,n-1);
    while(q--)
    {
        ll m;
        cin>>m;
        if(m==2)
        {
            ll a,b;
            cin>>a>>b;  
            cout<<__builtin_popcountll(ans(1,0,n-1,a-1,b-1));
            nl;
        }
        else
        {
            ll a;
            char c;
            cin>>a>>c;
            update(1,0,n-1,a-1,c);
        }
    }
    return 0;
}