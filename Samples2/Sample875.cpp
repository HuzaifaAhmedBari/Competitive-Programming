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
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vl arr(n);
        cin>>arr;
        map<ll,ll> m,fre;
        vector<pair<pii,ll>> query(n-1),ans(n-1);
        fori(0,n-1)
        {
            ll x,y;
            cin>>x>>y;
            query[i] = {{x-1,y-1},i};
            fre[query[i].fs.fs]++;
            fre[query[i].fs.sc]++;
        }
        sort(all(query),[&](pair<pii,ll>x,pair<pii,ll>y){
            if(fre[x.fs.fs]!=fre[y.fs.fs])
                return fre[x.fs.fs]>fre[y.fs.fs];
            return fre[x.fs.sc]>fre[y.fs.sc];
        });
        cout<<query;
        nl;
        vpii ret(n-1);
        bool flag=true;
        fori(0,n-1)
        {
            m[query[i].fs.fs] = i;
            m[query[i].fs.sc] = i;
        }
        fori(0,n-1)
        {
            if(m[query[i].fs.fs]!=i and m[query[i].fs.sc]!=i)
            {
                cout<<i;
                nl;
                flag=false;
                break;
            }
            // if(arr[query[i].fs]==0)
            // {
            //     flag=false;
            //     break;
            // }
            // if(m[query[i].fs]==i)
            // {
            //     ans[i].fs = arr[query[i].fs];
            //     arr[query[i].fs] = 0;
            // }
            // else
            // {
            //     ans[i].fs = 1;
            //     arr[query[i].fs]--;
            // }
            // if(arr[query[i].sc]==0)
            // {
            //     flag=false;
            //     break;
            // }
            // if(m[query[i].sc]==i)
            // {
            //     ans[i].sc = arr[query[i].sc];
            //     arr[query[i].sc] = 0;
            // }
            // else
            // {
            //     ans[i].sc = 1;
            //     arr[query[i].sc]--;
            // }
            if(m[query[i].fs.fs]==i)
            {
                ans[i].fs.fs = arr[query[i].fs.fs];
            }
            else
            {
                ans[i].fs.fs = 0;
            }
            if(m[query[i].sc]==i)
            {
                ans[i].fs.sc = arr[query[i].fs.sc];
            }
            else
            {
                ans[i].fs.sc = 0;
            }
            ans[i].sc = query[i].sc;
        }
        if(not flag)
        {
            YES(0);
            nl;
            continue;
        }
        fori(0,n-1)
        {
            ret[ans[i].sc] = ans[i].fs;
        }
        YES(1);
        nl;
        cout<<ret;
    }
    return 0;
}