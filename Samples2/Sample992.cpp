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
vl spf;
void build_spf(ll n) {
    is_prime.assign(n+1,true);
    is_prime[0] = is_prime[1] = false;
    spf.assign(n + 1, 0);
    iota(spf.begin(), spf.end(), 0LL);
    for (ll i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

bool factorize(ll x, set<ll> &s) {
    ll z = x;
    ll mx = 0;
    while (x > 1) {
        if(x==1)
            break;
        if(s.count(spf[x]))
            return true;
        x /= spf[x];
    }
    while(z > 1)
    {
        if(z==1)
            return false;
        s.insert(spf[z]);
        z /= spf[z];
    }
    return false;
}
bool factorize2(ll x, set<ll> &s) {
    ll mx = 0;
    while (x > 1) {
        if(x==1)
            return false;
        if(s.count(spf[x]))
            return true;
        x /= spf[x];
    }
    return false;
}
int main()
{
    io;
    build_spf(2e5+1);
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll n;
        ll mn = LLONG_MAX;
        cin>>n;
        vl arr1(n), arr2(n);
        cin>>arr1>>arr2;
        ll even = count_if(all(arr1),[](ll x){return !(x&1);});
        if(even>=2)
        {
            cout<<0;
            nl;
            continue;
        }
        ll odd = n-even;
        vl use;
        set<ll> s;
        vpii arr(n);
        fori(0,n)
        {
            arr[i] = {arr1[i],arr2[i]};
        }
        sahi(arr);
        bool flag=false;
        factorize(arr[0].fs,s);
        fori(1,n)
        {
            if(arr[i].fs==1)
                continue;
            if(factorize(arr[i].fs,s))
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<0;
            nl;
            continue;
        }
        ll temp = LLONG_MAX;
        fori(0,n)
        {
            if(arr[i].fs&1)
                temp = min(temp,arr[i].sc);
        }
        if(even==1 and odd>0)
        {
            mn = min(mn,temp);
        }
        fori(0,n)
        {
            if(arr[i].fs==1)
                continue;
            if(factorize2(arr[i].fs+1,s))
            {
                mn = min(mn,arr[i].sc);
            }
        }
        ll ab;
        for(auto x:s)
        {
            ab = x;
            break;
        }
        fori(0,n)
        {
            auto it = s.upper_bound(arr[i].fs);
            if(it==s.end())
                continue;
            ll z = *it;
            mn = min(mn,(z-arr[i].fs)*arr[i].sc);
            mn = min(mn,((ab-(arr[i].fs%ab))*arr[i].sc));
        }
        sahi(arr2);
        mn = min(mn,arr2[0]+arr2[1]);
        cout<<mn;
        nl;
    }
    return 0;
}