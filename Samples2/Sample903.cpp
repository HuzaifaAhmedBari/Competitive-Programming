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
        ll n,k;
        cin>>n>>k;
        ll a = 1LL<<n, te = 1LL<<(n+1);
        // unordered_map<ll,ll> dp, go;
        // function<ll(ll)> f = [&](ll x) {
        //     if(x==k)
        //         return 0LL;
        //     if(dp.count(x))
        //         return dp[x];
        //     ll mn = INT_MAX;
        //     if(!(x&1))
        //     {
        //         ll ans = 1 + f(x>>1LL);
        //         if(ans<mn)
        //         {
        //             mn = ans;
        //             go[x] = 1;
        //         }
        //     }
        //     if(!((te-x)&1))
        //     {
        //         ll ans = 1 + f((te+x)>>1LL);
        //         if(ans<mn)
        //         {
        //             mn = ans;
        //             go[x] = 2;
        //         }
        //     }
        //     return dp[x] = mn;
        // };
        // ll ans = f(a);
        // cout<<ans;
        // nl;
        // vl use;
        // while(a!=k)
        // {
        //     use.push_back(go[a]);
        //     if(use.back()==1)
        //         a>>=1LL;
        //     else
        //         a=(te+a)>>1LL;
        // }
        // cout<<use;
        // nl;
        // queue<ll> q;
        // unordered_map<ll,ll> dp, parent, go;
        // q.push(a);
        // dp[a] = 0;
        // parent[a] = -1;

        // while(not q.empty())
        // {
        //     ll u = q.front();
        //     q.pop();
        //     if(u==k)
        //         break;
        //     if(!(u&1))
        //     {
        //         ll x = u>>1LL;
        //         if(!dp.count(x))
        //         {
        //             dp[x] = dp[u] + 1;
        //             parent[x] = u;
        //             go[x] = 1;
        //             q.push(x);
        //         }
        //     }
        //     if(!((te-u)&1)) {
        //         ll x = (te + u)>>1LL;
        //         if (!dp.count(x))
        //         {
        //             dp[x] = dp[u] + 1;
        //             parent[x] = u;
        //             go[x] = 2;
        //             q.push(x);
        //         }
        //     }
        // }
        // cout<<dp[k];
        // nl;
        // vl use;
        // ll x = k;
        // while(parent[x]!=-1)
        // {
        //     use.push_back(go[x]);
        //     x = parent[x];
        // }
        // reverse(all(use));
        // cout<<use;
        // nl;
        if(a==k)
        {
            cout<<0;
            nl;
            nl;
        }
        else
        {
            vl use;
            while(k!=a)
            {
                if(2*k<=te)
                {
                    use.push_back(1);
                    k<<=1LL;
                }
                else
                {
                    use.push_back(2);
                    k<<=1LL;
                    k -= te;
                }
            }
            reverse(all(use));
            cout<<use.size();
            nl;
            cout<<use;
            nl;
        }
    }
    return 0;
}